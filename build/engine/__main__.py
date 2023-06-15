#!/usr/bin/env python3
import platform,os,sys
from pathlib import Path
os.chdir(Path(__file__).parent)
operatingSystem=platform.system()
#Build script for engine

Path('../../bin').mkdir(parents=True, exist_ok=True)

#Get a list of all the .cpp files.
cppFilenames=' '.join([str(file) for file in Path().rglob(r'*.cpp')])

#print("Files:",cppFilenames)

assembly='engine'
compilerFlags={
    'Windows':    "-g -shared -Wvarargs -Wall -Werror -std=c++17",    #-Wall -Werror
    'Linux'  :    "-g -shared -fPIC -std=c++17" }[operatingSystem]    # -fms-extensions    # -Wall -Werror
includeFlags='-Isrc'
linkerFlags={ 'Windows': f"-luser32", 'Linux': '' }[operatingSystem]
defines={
    'Windows':    "-D_DEBUG -DLEXPORT -D_CRT_SECURE_NO_WARNINGS",
    'Linux'  :    "-D_DEBUG -DLEXPORT" }[operatingSystem]
outputFilename = { 'Windows': f'{assembly}.dll', 'Linux': f'lib{assembly}.so' }[operatingSystem]

print(f"Building {assembly}...")
ERRORLEVEL=os.system(f'g++ {cppFilenames} {compilerFlags} -o ../../bin/{outputFilename} {defines} {includeFlags} {linkerFlags}')
if ERRORLEVEL:
    sys.exit(ERRORLEVEL)
