# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

# Configuração do padrão de linguagem
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Configuração do Raspberry Pi Pico SDK
set(PICO_BOARD pico_w CACHE STRING "Board type")
include(pico_sdk_import.cmake)

# Nome do projeto
project(Tarefa_2 C CXX ASM)

# Inicialização do SDK do Raspberry Pi Pico
pico_sdk_init()

# Adicionar o executável principal
add_executable(Tarefa_2 Tarefa_2.c)

# Configuração do nome e versão do programa
pico_set_program_name(Tarefa_2 "Tarefa_2")
pico_set_program_version(Tarefa_2 "0.1")

# Habilitar saída padrão UART/USB
pico_enable_stdio_uart(Tarefa_2 1)
pico_enable_stdio_usb(Tarefa_2 1)

# Vincular biblioteca padrão
target_link_libraries(Tarefa_2 pico_stdlib)

# Incluir os arquivos do diretório atual
target_include_directories(Tarefa_2 PRIVATE ${CMAKE_CURRENT_LIST_DIR})

# Gerar arquivos binários e UF2
pico_add_extra_outputs(Tarefa_2)
