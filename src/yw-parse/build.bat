REM Work in directory containing this batch file
cd %0\..

REM Generate the C++ parser classes for the grammar in YW.g4
antlr4 -Dlanguage=Cpp -package yw YW.g4