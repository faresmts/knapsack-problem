@echo off

REM Define o diretório de build
set BUILD_DIR=build

REM Limpa artefatos de build anteriores
if exist "%BUILD_DIR%" (
    echo Removendo diretorio de build anterior...
    rmdir /s /q "%BUILD_DIR%"
)

REM Cria um novo diretório de build
echo Criando diretorio de build...
mkdir "%BUILD_DIR%"

REM Navega para o diretório de build
cd "%BUILD_DIR%"

REM Executa o CMake para gerar os arquivos de projeto (ex: para Visual Studio)
echo Executando CMake...
cmake ..

REM Compila o projeto
echo Compilando o projeto...
cmake --build .

echo.
echo Build concluido!

REM Navega de volta para a raiz do projeto
cd ..

REM Executa o benchmark
echo Executando o benchmark...
"%BUILD_DIR%\knapsack_problem.exe"