ECHO OFF
set buildDir=%.\build
pushd %buildDir%
echo D | xcopy /y ..\resources .\resources
popd

PAUSE
