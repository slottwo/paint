@echo off

REM Caminho para o diretório raiz onde estão os arquivos .c
set "SOURCE_DIR=C:\Caminho\Para\Seu\Diretorio"

REM Limpa a lista de arquivos .c
set "C_FILES="

REM Encontra recursivamente todos os arquivos .c no diretório e subdiretórios
for /r "%SOURCE_DIR%" %%F in (*.c) do (
    set "C_FILES=!C_FILES! "%%F""
)

REM Adiciona o arquivo principal à variável C_FILES
set "C_FILES=%C_FILES% %1"

REM Compilação dos programas em C para arquivos objetos individuais
for %%F in (%C_FILES%) do (
    gcc -c "%%~F" -o "%%~dpnFo"
    if errorlevel 1 (
        echo Erro ao compilar "%%~F"
        exit /b 1
    )
)

REM Vinculação dos arquivos objetos em um único executável
set "OUTPUT_EXE=%~n1.exe"
gcc %C_FILES% -o "%OUTPUT_EXE%" -lopengl32 -lglu32 -lfreeglut

REM Verifica se a compilação teve êxito
if errorlevel 1 (
    echo Erro durante a compilação.
) else (
    echo Compilação bem-sucedida. Executável gerado: programas.exe
)
