xcopy bin\ZThread_OurDebug\ZThread.dll ..\Win32_Debug\ /Y
xcopy bin\ZThread_OurDebug\ZThread.lib ..\Win32_Debug\ /Y
xcopy bin\ZThread_OurDebug\ZThread.pdb ..\Win32_Debug\ /Y

xcopy bin\ZThread_OurRelease\ZThread.lib ..\Win32_Release\ /Y

xcopy ZThread-2.3.2\include\zthread\*.* ..\Win32_include\zthread\ /Y
xcopy ZThread-2.3.2\include\zthread.client\*.* ..\Win32_include\zthread\ /Y
