@if not "%MINGW_ROOT%" == "" (@set "PATH=%PATH%;%MINGW_ROOT%")

cd .

if "%1"=="" ("C:\MATLAB\R2017a\bin\win64\gmake"  -f Moment_work_2017.mk all) else ("C:\MATLAB\R2017a\bin\win64\gmake"  -f Moment_work_2017.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
