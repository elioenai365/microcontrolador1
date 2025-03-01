#include "audio.h"
#include <stdio.h>
#include <math.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include <stdint.h>

#define ADC_PIN 26  // Pino do microfone
#define SAMPLE_RATE 4000  // Taxa de amostragem em Hz
#define BUFFER_SIZE 256  // Tamanho do buffer para processamento

static int16_t buffer[BUFFER_SIZE];

void audio_init() {
    adc_init();
    adc_gpio_init(ADC_PIN);
    adc_select_input(0);
}

void audio_capture(int16_t *buffer, uint16_t size) {
    // Captura o áudio do ADC
    for (int i = 0; i < size; i++) {
        buffer[i] = adc_read();
        sleep_us(1000000 / SAMPLE_RATE);  // Aguarda para manter a taxa de amostragem
    }
}

// Função de detecção de zero-crossing
int detect_zero_crossing(int16_t *buffer, uint16_t size) {
    int last_value = 0;
    int crossings = 0;

    for (int i = 0; i < size; i++) {
        int16_t current_value = buffer[i];

        // Verifica se houve um cruzamento de zero
        if (last_value >= 0 && current_value < 0) {
            crossings++;  // Cruzamento de zero positivo para negativo
        }
        else if (last_value < 0 && current_value >= 0) {
            crossings++;  // Cruzamento de zero negativo para positivo
        }

        last_value = current_value;  // Atualiza o valor anterior
    }

    return crossings;
}

// Função para calcular a frequência a partir dos cruzamentos de zero
float calculate_frequency(int crossings) {
    // A frequência é metade dos cruzamentos de zero por amostra, multiplicada pela taxa de amostragem
    return (float)crossings / 2.0 * (SAMPLE_RATE / BUFFER_SIZE);
}

// Função de processamento de áudio, agora utilizando a detecção de zero-crossing
float audio_process(int16_t *buffer, uint16_t size) {
    printf("Processando áudio...\n");

    // Detecta os cruzamentos de zero
    int zero_crossings = detect_zero_crossing(buffer, size);

    // Calcula a frequência a partir dos cruzamentos de zero
    float frequency = calculate_frequency(zero_crossings);

    printf("Frequência detectada: %.2f Hz\n", frequency);
    return frequency;  // Retorna a frequência detectada
}

