import os
import sys
import subprocess

def insertBlock(fileIn, fileOut, block, startTag, endTag, lastBlock = True):
	""" insert code in file between tags """
	found = False
	while not found:
		line = fileIn.readline()
		fileOut.write(line)
		if startTag in line:
			for item in block:
				fileOut.write(item)

			while endTag not in line:
				line = fileIn.readline()
			fileOut.write(line)
			found = True

	if lastBlock:
		""" rest of the file """
		while line != '':
			line = fileIn.readline()
			fileOut.write(line)

if (len(sys.argv) != 2):
	print('Usage: python make_Extio_Buffer.py <ExtIO DLL File Name>')
	exit()



InitHWfnCall = """
bool __stdcall InitHW(char* name, char* model, int& hwtype) {
	bool retVal;

	retVal = x_InitHW(name, model, hwtype);
	hwTypeReported = hwtype;

	if (debug) std::cout << "[ExtIO_Buffer] hwtype = " << hwTypeReported << std::endl;

	return retVal;
}
"""

StartHWfnCall = """
int __stdcall StartHW(long extLOfreq) {

	xIqPairsPerCall = x_StartHW(extLOfreq);
	stopBufferThread = FALSE;
	return(createBuffer());
}
"""		

StopHWfnCall = """
void __stdcall StopHW(void) {
	if (buffering) {
		stopBufferThread = TRUE;
		bufferThread.join();
	}
	return x_StopHW();
}
"""

SetCallbackfnCall = """
void __stdcall SetCallback(pfnExtIOCallback funcptr) {
	// intercept callback functions with our own
	if (debug) std::cout << "[ExtIO_Buffer] Redirecting callback" << std::endl;
	appCallback = funcptr;
	return x_SetCallback(bufferCallback);
}
"""

StartHW64fnCall = """
int __stdcall StartHW64(int64_t extLOfreq) {
	xIqPairsPerCall = x_StartHW64(extLOfreq);
	stopBufferThread = FALSE;
	return(createBuffer());
}
"""		

StartHW_dblfnCall = """
int __stdcall StartHW_dbl(double extLOfreq) {
	xIqPairsPerCall = x_StartHW_dbl(extLOfreq);
	stopBufferThread = FALSE;
	return(createBuffer());
}
"""


dllName = os.path.normpath(sys.argv[1])

scanCall = subprocess.run(['scanDll', dllName], stdout = subprocess.PIPE, text = True)
validCalls = scanCall.stdout.split('\n')

hFile = open('..\\LC_ExtIO_Types.h', 'r')

externFileIn = open('..\\ExtIO_Buffer.h', 'r')
externFileOut = open('..\\ExtIO_Buffer.h.tmp', 'w')

cFileIn = open('..\\ExtIO_Buffer.cpp', 'r')
cFileOut = open('..\\ExtIO_Buffer.cpp.tmp', 'w')

defIn = open('..\\ExtIO_Buffer.def.master', 'r')
defOut = open('..\\ExtIO_Buffer.def', 'w')

pfnNames = []
callNames = []
retVals = []
paramDefs = []
params = []

for line in hFile:
	if line.startswith('typedef'):
		#print(line, end = '')
		words = line.split()
		if words[1] != 'enum':
			for w in words:
				if w.startswith('pfn'):
					pfn = w[:w.find(')')]
					#print(p)
					pfnNames.append(pfn)
					call = pfn[3:]
					callNames.append(call)
			retVals.append(words[1])
			paramDef = line[line.find(pfn + ')') + len(pfn) + 1:]
			paramDef = paramDef[:paramDef.find(';')]
			paramDef = paramDef.strip()
			paramDefs.append(paramDef)

for i in range(0, len(paramDefs)):
	param = paramDefs[i]
	if retVals[i] != 'enum':
		paramList = ''
		param = param[1:-1].strip()
		#print(param)
		if param != 'void':
			vtList = param.split(',')
			#print(vtList)
			for vt in vtList:
				#print(vt)
				vt = vt.split()
				varName = vt[-1]
				varName = varName.strip()
				if varName.startswith('*') or varName.startswith('&'):
					varName = varName[1:]
				paramList += varName + ','
			paramList = paramList[:-1]
		#print(paramList)
		params.append(paramList)


hFile.close()

"""
for i in range(1, len(pfnNames)):
	print(f'{pfnNames[i]} {retVals[i]} {callNames[i]} {paramDefs[i]} {params[i]}')
"""

""" These will be insterted into ExtIO_Buffer.h """
externs = []

""" These are needed in ExtIO_Buffer.cpp as globals """
pfnVariables = []

""" These are needed in ExtIO_Buffer dllInit() """
dllInits = []

dllInits.append(f'\tLPCWSTR dllName = L"{dllName}";\n')
dllInits.append(f'\textIO = LoadLibrary(L"{dllName}");\n')
dllInits.append('\n')
dllInits.append('\tif (extIO) {\n')

""" These are needed in ExtIO_Buffer after dllInit() """
fnCalls = []

for i in range(1, len(pfnNames)):

	if callNames[i] in validCalls:

		externs.append(f'extern "C" {retVals[i]} __declspec(dllexport) __stdcall {callNames[i]}{paramDefs[i]};\n')

		pfnVariables.append(f'{pfnNames[i]} x_{callNames[i]};\n')

		dllInits.append(f'\t\tx_{callNames[i]} = ({pfnNames[i]})GetProcAddress(extIO, "{callNames[i]}");\n')


		""" Function calls 
		These receive special treatment:
		InitHW
		StartHW
		SetCallback
		StartHW64
		StartHW_dbl
		"""

		if callNames[i] == 'InitHW':
			fnCall = InitHWfnCall
		elif callNames[i] == 'StartHW':
			fnCall = StartHWfnCall
		elif callNames[i] == 'StopHW':
			fnCall = StopHWfnCall
		elif callNames[i] == 'SetCallback':
			fnCall = SetCallbackfnCall
		elif callNames[i] == 'StartHW64':
			fnCall = StartHW64fnCall
		elif callNames[i] == 'StartHW_dbl':
			fnCall = StartHW_dblfnCall
		else:
			fnCall = f'{retVals[i]} __stdcall {callNames[i]}{paramDefs[i]}' + ' {\n'
			fnCall += f'\treturn x_{callNames[i]}({params[i]});\n'
			fnCall += '}\n\n'
		fnCalls.append(fnCall)

"""
for extern in externs:
	print(extern)

for pfnVariable in pfnVariables:
	print(pfnVariable)

for dllInit in dllInits:
	print(dllInit)

for fnCall in fnCalls:
	print(fnCall)
"""

""" Update the extern file """
insertBlock(fileIn = externFileIn, fileOut = externFileOut, block = externs, startTag = 'EXTERN: BEGIN', endTag = 'EXTERN: END', lastBlock = True)

""" Update main cpp file """
insertBlock(fileIn = cFileIn, fileOut = cFileOut, block = pfnVariables, startTag = 'PFN: BEGIN', endTag = 'PFN: END', lastBlock = False)
insertBlock(fileIn = cFileIn, fileOut = cFileOut, block = dllInits, startTag = 'DLLINIT: BEGIN', endTag = 'DLLINIT: END', lastBlock = False)
insertBlock(fileIn = cFileIn, fileOut = cFileOut, block = fnCalls, startTag = 'FNCALLS: BEGIN', endTag = 'FNCALLS: END', lastBlock = True)

""" Deal with the .def file """
for line in defIn:
	keywords = line.split()
	if keywords != []:
		if keywords[0] in validCalls:
			defOut.write(line)
		elif keywords[0] in ['LIBRARY','EXPORTS']:
			defOut.write(line)

""" Close and rename files """

externFileIn.close()
externFileOut.close()
try:
	os.remove('..\\ExtIO_Buffer.h.old')
except:
	pass
os.rename('..\\ExtIO_Buffer.h', '..\\ExtIO_Buffer.h.old')
os.rename('..\\ExtIO_Buffer.h.tmp', '..\\ExtIO_Buffer.h')

cFileIn.close()
cFileOut.close()
try:
	os.remove('..\\ExtIO_Buffer.cpp.old')
except:
	pass
os.rename('..\\ExtIO_Buffer.cpp', '..\\ExtIO_Buffer.cpp.old')
os.rename('..\\ExtIO_Buffer.cpp.tmp', '..\\ExtIO_Buffer.cpp')

defIn.close()
defOut.close()

exit()




