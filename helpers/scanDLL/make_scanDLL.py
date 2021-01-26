import os

hFile = open('..\\LC_ExtIO_Types.h', 'r')

cFileIn = open('.\\scanDLL.cpp', 'r')
cFileOut = open('.\\scanDLL.cpp.tmp', 'w')

pfnNames = []
callNames = []

for line in hFile:
	if line.startswith('typedef'):
		#print(line, end = '')
		words = line.split()
		for w in words:
			if w.startswith('pfn'):
				pfn = w[:w.find(')')]
				#print(p)
				pfnNames.append(pfn)
				call = pfn[3:]
				callNames.append(call)
hFile.close()

"""
for pfn in pfnNames:
	print(pfn)

for call in callNames:
	print(call)
"""

"""
First item in both lists are the callback
ignore that...

Create the pfn variable declarations
"""

pfnVariables = []
for i in range(1, len(pfnNames)):
	pfnVariables.append(f'{pfnNames[i]} {callNames[i]};\n')

"""
for pfn in pfnVariables:
	print(pfn)
"""

"""
Create the main function tests
"""
mainCode = []
for i in range(1, len(pfnNames)):
	mainCode.append(f'\t{callNames[i]} = ({pfnNames[i]})GetProcAddress(extIO, "{callNames[i]}");\n')
	mainCode.append(f'\tif ({callNames[i]} != NULL) std::cout << "{callNames[i]}" << std::endl;\n')
	mainCode.append('\n')

"""
for code in mainCode:
	print(code)
"""

""" insert pointer function variables """
found = False
while not found:
	line = cFileIn.readline()
	cFileOut.write(line)
	if 'PFN: BEGIN' in line:
		for pfnV in pfnVariables:
			cFileOut.write(pfnV)

		while 'PFN: END' not in line:
			line = cFileIn.readline()
		cFileOut.write(line)
		found = True

""" insert main code """
found = False
while not found:
	line = cFileIn.readline()
	cFileOut.write(line)
	if 'MAIN: BEGIN' in line:
		for code in mainCode:
			cFileOut.write(code)

		while 'MAIN: END' not in line:
			line = cFileIn.readline()
		cFileOut.write(line)
		found = True

""" rest of the file """
while line != '':
	line = cFileIn.readline()
	cFileOut.write(line)


cFileIn.close()
cFileOut.close()

os.remove('.\\scanDLL.cpp.old')
os.rename('.\\scanDLL.cpp', '.\\scanDLL.cpp.old')
os.rename('.\\scanDLL.cpp.tmp', '.\\scanDLL.cpp')

