xcopy MySQL-4.1.15\debug\libmysql.dll ..\Win32_Debug\ /Y
xcopy MySQL-4.1.15\debug\libmysql.lib ..\Win32_Debug\ /Y

xcopy MySQL-4.1.15\opt\libmysql.dll ..\Win32_Release\ /Y
xcopy MySQL-4.1.15\opt\libmysql.lib ..\Win32_Release\ /Y

xcopy MySQL-4.1.15\include\*.* ..\Win32_include\mysql\ /Y
