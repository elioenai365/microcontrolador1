/*
    Com o objetivo de consolidar os conceitos sobre o uso de conversores analógico-digitais (ADC) no
    RP2040 e explorar as funcionalidades da placa de desenvolvimento BitDogLab, propõe-se a realização da
    seguinte atividade prática individual.

    Objetivos:

    • Compreender o funcionamento do conversor analógico-digital (ADC) no RP2040.
    • Utilizar o PWM para controlar a intensidade de dois LEDs RGB com base nos valores do joystick.
    • Representar a posição do joystick no display SSD1306 por meio de um quadrado móvel.
    • Aplicar o protocolo de comunicação I2C na integração com o display.

*/

// Declaração de bibliotecas do projeto
#include <stdio.h> // biblioteca padrao de entrada e saida 
#include "pico/stdlib.h"// Biblioteca de comunicação serial USB
#include "hardware/adc.h"// Biblioteca de converção adc
#include "hardware/pwm.h"//Biblioteca responsavel pelo pwm



int main()
{
    stdio_init_all();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
