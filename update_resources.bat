ECHO OFF
cd C:\Users\sweetsbeats\SDL2-Engine-Test
set buildDir=%.\build
pushd %buildDir%
echo D | xcopy /y ..\resources .\resources
popd

PAUSE
