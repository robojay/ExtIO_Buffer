f = open('..\\LC_ExtIO_Types.h', 'r')

pfn = []
calls = []
funcs = []

for line in f:
	if line.startswith('typedef'):
		#print(line, end = '')
		words = line.split()
		call = 'extern "C" ' + words[1] + ' __declspec(dllexport) __stdcall '
		func = words[1] + ' __stdcall '
		for w in words:
			if w.startswith('pfn'):
				p = w[:w.find(')')]
				#print(p)
				pfn.append(p)
				call += p[3:]
				func += p[3:]
				#print(call.split()[-1])
				#print(line[line.find(call.split()[-1]) + len(call.split()[-1]) + 1:])
				call += line[line.find(call.split()[-1]) + len(call.split()[-1]) + 1:].lstrip()	
				func += line[line.find(func.split()[-1]) + len(func.split()[-1]) + 1:].lstrip()
				call = call[:call.find(';') + 1]	
				func = func[:func.find(';')]					
				#print(call)
				calls.append(call)
				funcs.append(func)
f.close()

print('**** INSERT INTO MAIN CPP FILE ****')

print('// [Start of generated code block]')
print("// Pointers to the ExtIO functions of the DLL we're loading")
print('// Insert as Global Variables')
print()
for p in pfn:
	print(f'{p} x_{p[3:]};')
print()
print('// [End of generated code block]')
print()

print('// [Start of generated code block]')
print('// Insert into main')
print()
print('LPCWSTR dllName = L".\\ExtIO_ICR8600.dll";')
print('HINSTANCE extIO;')
print()
print('void dllInit() {')
print()
print('    extIO = LoadLibrary(dllName);')
print()

for i in range(0,len(pfn)):
	print(f'    x_{pfn[i][3:]} = ({pfn[i]})GetProcAddress(extIO, "{pfn[i][3:]}");')

print()
print('}')
print()
print('// Create cross DLL calls')
print()

for i in range(0,len(funcs)):
	fn = funcs[i]
	params = fn[fn.find('('):fn.find(')') + 1]
	params = params[1:-1]
	params = params.split(',')
	#print(params)
	cp = ''
	if len(params) != 0:
		for pp in params:
			pp = pp.strip()
			if pp != 'void':
				pp = pp.split()[-1]
				if pp.startswith('*'):
					pp = pp[1:]
				if pp.startswith('&'):
					pp = pp[1:]
				cp += pp + ', '
		cp = cp[:-2]
	print(fn + ' {')
	print(f'    return x_{pfn[i][3:]}({cp});')
	print('}')
	print()

print('// [End of generated code block]')
print()

print('**** INSERT INTO MAIN H FILE ****')

print('// [Start of generated code block]')
print("// Exported ExtIO DLL calls")
print('// Insert into .h file')
for call in calls:
	print(call)
print()
print('// [End of generated code block]')
print()
