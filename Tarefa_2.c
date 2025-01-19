/*
 ATIVIDADE-2- (Participativa): Controle de pinos GPIO da
ferramenta educacional BitDogLab.

## DESCRIÇÃO
O presente projeto busca utilizar o monitor serial para realizar o envio de comandos para o microcontrolador Raspberry Pi Pico W. 
A comunicação via protocolo UART entre o computador e a placa viabiliza o envio do programa e a execução do mesmo, que consiste em 
fazer o controle de LEDs RGB e ativar um buzzer por um intervalo de 2000 ms.

### Desenvolvedor
Este projeto foi realizado individualmente por **LUCAS DIAS DA SILVA**.

### DATA
19/01/2025

*/

#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"

// Definição dos pinos
#define LED_RED 13
#define LED_BLUE 12
#define LED_GREEN 11
#define BUZZER 21

// Inicializa os pinos GPIO
void init_peripherals() {
    gpio_init(LED_RED);
    gpio_init(LED_BLUE);
    gpio_init(LED_GREEN);
    gpio_init(BUZZER);

    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(BUZZER, GPIO_OUT);

    // Apaga todos os LEDs e o buzzer
    gpio_put(LED_RED, 0);
    gpio_put(LED_BLUE, 0);
    gpio_put(LED_GREEN, 0);
    gpio_put(BUZZER, 0);
}

// Liga/desliga os LEDs com base nos valores
void set_leds(int red, int blue, int green) {
    gpio_put(LED_RED, red);
    gpio_put(LED_BLUE, blue);
    gpio_put(LED_GREEN, green);
}

// Toca o buzzer por uma frequência e duração especificada
void play_buzzer(uint frequency, uint duration_ms) {
    uint delay = 1000000 / (2 * frequency); // Calcula atraso para frequência
    uint cycles = (frequency * duration_ms) / 1000;

    for (uint i = 0; i < cycles; i++) {
        gpio_put(BUZZER, 1);
        sleep_us(delay);
        gpio_put(BUZZER, 0);
        sleep_us(delay);
    }
}

// Executa o comando recebido
void execute_command(const char *command) {
    if (strcmp(command, "RED") == 0) {
        set_leds(1, 0, 0); // Liga LED vermelho
        printf("LED vermelho ligado.\n");
    } else if (strcmp(command, "BLUE") == 0) {
        set_leds(0, 1, 0); // Liga LED azul
        printf("LED azul ligado.\n");
    } else if (strcmp(command, "GREEN") == 0) {
        set_leds(0, 0, 1); // Liga LED verde
        printf("LED verde ligado.\n");
    } else if (strcmp(command, "WHITE") == 0) {
        set_leds(1, 1, 1); // Liga todos os LEDs
        printf("LEDs brancos ligados.\n");
    } else if (strcmp(command, "OFF") == 0) {
        set_leds(0, 0, 0); // Apaga todos os LEDs
        printf("Todos os LEDs desligados.\n");
    } else if (strcmp(command, "BUZZER") == 0) {
        set_leds(0, 0, 0); // Apaga os LEDs antes do buzzer
        play_buzzer(1000, 500); // Frequência de 1000 Hz por 500 ms
        sleep_ms(2000); // Pausa após o som
        printf("Buzzer ativado.\n");
    } else {
        printf("Comando não reconhecido: %s\n", command);
    }
}

int main() {
    stdio_init_all(); // Inicializa comunicação UART
    init_peripherals(); // Configura os periféricos

    char command[20]; // Buffer para comando recebido

    while (true) {
        printf("Digite um comando (RED, BLUE, GREEN, WHITE, OFF, BUZZER): ");
        scanf("%s", command); // Recebe o comando via UART
        execute_command(command); // Executa o comando
        sleep_ms(50); // Aguarda para evitar leituras repetidas
    }

    return 0;
}