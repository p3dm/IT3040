@echo off

for /l %%i in (1, 1, 100) do (
    gentest.exe 
    bai1_4_sol1.exe 
    bai1_4_sol2.exe
    fc bai1_4_sol1.out bai1_4_sol2.out 
    if errorlevel 1 (
        goto :eof
    ) else (
        echo Test %%i correct
    )
)

