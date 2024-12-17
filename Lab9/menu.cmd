@echo off
:menu
cls
echo =============================
echo          Menu
echo =============================
echo 1. IPv4 and IPv6 Info
echo 2. Traceroute
echo 3. IP Address of Host
echo 4. Encrypt File/Text
echo 5. Decrypt File
echo 6. Execute File
echo 7. Restore (Not Implemented)
echo 8. File Size to Cost Calculation
echo 9. Exit
echo =============================
set /p choice=Enter number: 

if "%choice%"=="1" goto ipv4_ipv6
if "%choice%"=="2" goto traceroute
if "%choice%"=="3" goto ip_address
if "%choice%"=="4" goto encrypt
if "%choice%"=="5" goto decrypt
if "%choice%"=="6" goto execute
if "%choice%"=="7" goto restore
if "%choice%"=="8" goto cost
if "%choice%"=="9" exit

echo Invalid option! Please select a valid number.
pause
goto menu

:ipv4_ipv6
cls
echo Displaying IPv4 and IPv6 addresses:
ipconfig | findstr "IPv4 IPv6"
echo.
pause
goto menu

:traceroute
cls
set /p host=Enter host name or IP to trace route: 
if "%host%"=="" (
    echo You must enter a host name or IP address.
    pause
    goto menu
)
tracert %host%
pause
goto menu

:ip_address
cls
set /p host=Enter host name or IP to resolve: 
if "%host%"=="" (
    echo You must enter a host name or IP address.
    pause
    goto menu
)
nslookup %host%
pause
goto menu

:encrypt
cls
set /p input=Enter the file path or text to encrypt: 
if "%input%"=="" (
    echo You must provide a file path or text to encrypt.
    pause
    goto menu
)
if exist "%input%" (
    certutil -encode "%input%" encrypted.txt
    echo File encrypted and saved as encrypted.txt
) else (
    echo Input is text, saving encrypted text as "encrypted.txt"
    echo %input% | certutil -encode - encrypted.txt
)
pause
goto menu

:decrypt
cls
set /p input=Enter path to encrypted file: 
if "%input%"=="" (
    echo You must provide a file path to decrypt.
    pause
    goto menu
)
if exist "%input%" (
    certutil -decode "%input%" decrypted.txt
    echo File decrypted and saved as decrypted.txt
) else (
    echo The specified file does not exist.
    pause
)
goto menu

:execute
cls
set /p input=Enter full file path to execute: 
if "%input%"=="" (
    echo You must provide a file path to execute.
    pause
    goto menu
)
if exist "%input%" (
    start "" "%input%"
    echo Executing file: %input%
) else (
    echo The specified file does not exist.
    pause
)
goto menu

:restore
cls
echo Restore functionality is not implemented yet.
pause
goto menu

:cost
cls
set /p path=Enter path to file for cost calculation: 
if "%path%"=="" (
    echo You must provide a file path.
    pause
    goto menu
)
if exist "%path%" (
    for %%F in ("%path%") do set size=%%~zF
    set /a cost=%size%/1024/1024*10  :: Example: $10 per MB
    echo File size: %size% bytes
    echo Estimated cost: $%cost% USD
) else (
    echo The specified file does not exist.
)
pause
goto menu
