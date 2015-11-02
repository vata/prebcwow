xcopy bin\pythoncore_OurDebug\python24_d.dll ..\Win32_Debug\ /Y
xcopy bin\pythoncore_OurDebug\python24_d.lib ..\Win32_Debug\ /Y
xcopy bin\pythoncore_OurDebug\python24_d.pdb ..\Win32_Debug\ /Y

xcopy bin\pythoncore_OurRelease\python24.lib ..\Win32_Release\ /Y

xcopy Python-2.4.2\Include\*.* ..\Win32_include\Python\ /Y
xcopy Python-2.4.2\PC\pyconfig.h ..\Win32_include\Python\ /Y
