#include <stdio.h>
#include "pico/stdlib.h"
#include "matrizRGB.h"
#include "desenho.h"

// Configuração dos pinos

const uint LED_RED_PIN = 13; // Green = 11, Blue = 12 and Red = 13

const uint BUTTON1_PIN = 5; // Define o botão 1 como pino 5
const uint BUTTON2_PIN = 6; // Define o botão 2 como pino 6

// Definição de variáveis globais

static volatile int num;           // Variável global para definir qual número selecionar na matriz
static volatile int num1 = 1;      // Variável global para testar doubounce
static volatile int num2 = 1;      // Variável global para testar doubounce
static volatile int last_time = 0; // Variável global para amarzenar o tempo do último evento

static void gpio_irq_handle(uint gpio, uint32_t events);

int main()
{
    // Inicialização dos pinos
    stdio_init_all();

    gpio_init(LED_RED_PIN);
    gpio_init(BUTTON1_PIN);
    gpio_init(BUTTON2_PIN);

    // Inicializa os pinos da matriz de Leds no pino 7

    npInit(7);

    // Confira direção dos pinos (Entrada ou saída)

    gpio_set_dir(LED_RED_PIN, GPIO_OUT);
    gpio_set_dir(BUTTON1_PIN, GPIO_IN);
    gpio_set_dir(BUTTON2_PIN, GPIO_IN);

    /* Configuração para habilitar o pull up interno para os botões, evitando o uso de resistores externos e
    garantindo que o pino esteja em nível alto quando o botão não estiver pressionado. */

    gpio_pull_up(BUTTON1_PIN);
    gpio_pull_up(BUTTON2_PIN);

    // Escreve o número inicial a ser exibido na matriz de Leds, neste caso o número 5.

    num = 5; // inicializa o valor da variável volátil como 5

    // Escreve o primeiro número inicial na matriz de leds 5x5, neste caso o 5.
    setMatrizDeLEDSComIntensidade(caixa_de_desenhos[num], 0.007, 0.007, 0.007);

    // Configuração da interrupção com o callback
    gpio_set_irq_enabled_with_callback(BUTTON1_PIN, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handle);
    gpio_set_irq_enabled_with_callback(BUTTON2_PIN, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handle);

    // Loop principal

    while (true)
    {

        gpio_put(LED_RED_PIN, true);
        sleep_ms(100);
        gpio_put(LED_RED_PIN, false);
        sleep_ms(100);
    }
}

static void gpio_irq_handle(uint gpio, uint32_t events)
{
    // Cria uma varíavel que pega o tempo atual do sistema em microsegundos.
    uint32_t current_time_us = to_us_since_boot(get_absolute_time());

    // Print para debbugar o efeito do doubounce

    printf("Sinais de transição lidos pelo sistema: %d \n", num1);
    num1++;

    if (current_time_us - last_time > 200000) // 200 ms de doboucing
    {
        last_time = current_time_us; // atualiza o tempo do último evento.
        if (num >= 0 && num <= 9)
        {
            if (gpio == BUTTON1_PIN)
            {
                /* Ternário (Condição ? valor se verdadeiro: valor se falso), atribui valor a variável volátil num
                   Se o número for menor que 9 ele incrementa o num em 1, se não, faz o valor permanecer em 9 */

                num = (num < 9) ? num + 1 : 9;
            }
            else if (gpio == BUTTON2_PIN)
            {
                /* Ternário (Condição ? valor se verdadeiro: valor se falso), atribui valor a variável volátil num
                  Se o número for maior que 0 ele decrementa o num em 1, se não, faz o valor permanecer em 0 */
                num = (num > 0) ? num - 1 : 0;
            }

            // Print para mostrar quantas vezes eu apertei o botão na plaquinha e realmente rodou o código
            printf("O botão foi realmente apertado: %d \n", num2);
            num2++;

            // Escreve desenho atual na plaquinha, os três parâmetro são sobre a intensidade
            setMatrizDeLEDSComIntensidade(caixa_de_desenhos[num], 0.007, 0.007, 0.007);
        }
    }
}
