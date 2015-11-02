It is dir with all external libraries.
Files in this dir must NOT be edited. They must be built once for each platform/configuration and lay untouched.

./Win32_Debug/	 			dir with "DLL, /MD" or "LIB /MDd" (dll "Multithreaded DLL" or static lib "Debug Multithreaded DLL")
./Win32_Release/			dir with "LIB /MT" (static lib "Multithreaded")
./Win32_include/			includes of all libraries

./doc/MySQL_win32_notes.txt	note about MySQL on win32
./doc/wwwlinks.txt			www links to all libraries
./doc/build_*.txt			notes about building of each librarie

./make_Win32/				solution for building all libraries on win32 platform