# Atividade 2 - Participativa

Este repositório contém a **Atividade 2 Participativa**, desenvolvida para controlar LEDs e buzzer utilizando o **Raspberry Pi Pico W** e a ferramenta educacional **BitDogLab**. O projeto permite o envio de comandos via **monitor serial** para controlar LEDs RGB e ativar um buzzer, demonstrando o funcionamento do protocolo UART.

---

## 🎯 **Objetivo**

O objetivo desta atividade é utilizar o **Raspberry Pi Pico W** para controlar periféricos como LEDs e um buzzer, simulando interações básicas de hardware. O projeto também explora a comunicação serial UART para receber comandos em tempo real e controlar os dispositivos conectados.

---

## 🖥️ **Descrição do Projeto**

- **Plataforma**: Raspberry Pi Pico W
- **Periféricos controlados**:
  - LEDs RGB (Vermelho, Azul e Verde)
  - Buzzer
- **Comandos disponíveis**:
  - `RED`: Liga o LED vermelho.
  - `BLUE`: Liga o LED azul.
  - `GREEN`: Liga o LED verde.
  - `WHITE`: Liga todos os LEDs.
  - `OFF`: Desliga todos os LEDs.
  - `BUZZER`: Ativa o buzzer por 500ms (frequência de 1kHz).

---

## ⚙️ **Configuração do Hardware**

1. **Conexões**:
   - **LEDs**:
     - LED vermelho: Pino GPIO 13.
     - LED azul: Pino GPIO 12.
     - LED verde: Pino GPIO 11.
   - **Buzzer**: Pino GPIO 21.
2. **Esquema do Circuito**:
   - Use resistores adequados (ex: 220Ω) em série com os LEDs para limitar a corrente.
   - Conecte o buzzer diretamente ao pino GPIO 21 e ao GND.

---

## 🚀 **Como Executar o Projeto**

### 1. **Clone o repositório**:
   ```bash
   git clone https://github.com/LucaScripts/Atividade-2-Participativa-.git
   cd Atividade-2-Participativa-
   ```

### 2. **Prepare o ambiente de desenvolvimento**:
   Instale as ferramentas necessárias para o Raspberry Pi Pico W:
   - **CMake**
   - **GNU Arm Embedded Toolchain**
   - **Pico SDK**

### 3. **Configure o SDK do Pico**:
   Configure o diretório do SDK conforme a documentação oficial:
   ```bash
   export PICO_SDK_PATH=/caminho/para/pico-sdk
   ```

### 4. **Compile o código**:
   Crie um diretório de build e compile o código:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```

### 5. **Carregue o firmware**:
   Após a compilação, conecte o **Raspberry Pi Pico W** ao computador em modo "bootloader" (pressione o botão BOOTSEL enquanto conecta). Copie o arquivo `.uf2` gerado para o diretório do Raspberry Pi Pico.

### 6. **Execute o monitor serial**:
   Utilize um terminal serial (como o **minicom** ou o monitor serial do **Arduino IDE**) para enviar comandos e observar a saída.

---

## 🛠️ **Tecnologias e Ferramentas Utilizadas**

- **Linguagem**: C
- **Microcontrolador**: Raspberry Pi Pico W
- **Protocolo**: UART
- **IDE**: Visual Studio Code (com extensões para CMake e Raspberry Pi Pico)
- **SDK**: Pico SDK

---

## 🧩 **Como Usar**

Após carregar o firmware, envie os seguintes comandos através do monitor serial (**9600 baud rate**):

- **RED**: Liga o LED vermelho.
- **BLUE**: Liga o LED azul.
- **GREEN**: Liga o LED verde.
- **WHITE**: Liga todos os LEDs.
- **OFF**: Desliga todos os LEDs.
- **BUZZER**: Ativa o buzzer por 500ms.

---

## 🖥️ **Simulação no Wokwi**

Para facilitar a visualização e testes do projeto, uma simulação interativa foi criada no [Wokwi](https://wokwi.com/). Clique no link abaixo para acessar o projeto simulado:

[**Link do Wokwi**](https://wokwi.com/projects/420514180202003457)

---

## 📹 **Vídeo Ensaio**

[**Link do vídeo ensaio**](https://drive.google.com/file/d/1uxQ6PgeYWfG_cYCrO5AH0S089p5ZPhw3/view?usp=sharing)

---

## 📌 **Sobre a Execução do Projeto**

Optei por realizar a Atividade 2 Participativa de forma individual, como fui orientado pelo meu mentor. Devido à indisponibilidade da minha placa BitDogLab, utilizei simulações no Wokwi e no Visual Studio Code para testar e validar a implementação do código.

---

🧑‍💻 **Autor**

Projeto desenvolvido por **Lucas Dias da Silva** em **19 de janeiro de 2025**.
