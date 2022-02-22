@echo off
setlocal

rem カレントディレクトリ取得
set PREFIX=%~DP0


rem 環境変数設定
set TESTUE4CONFIG=%PREFIX%Config\

echo set %TESTUE4CONFIG%
echo;

rem Batを閉じて、slnを開始
START "" ImportTextFile.sln