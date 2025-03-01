#include "audio.h"
#include <stdio.h>
#include <math.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "kiss_fft/kiss_fft.h"
#include <stdint.h>  

#define ADC_PIN 26  // Pino do microfone
#define SAMPLE_RATE 4000  // Taxa de amostragem em Hz
#define BUFFER_SIZE 256   // Tamanho do buffer para processamento FFT

// Buffer para capturar dados do ADC
static int16_t buffer[BUFFER_SIZE];

// Definindo o buffer para o FFT
kiss_fft_cfg cfg;
kiss_fft_cpx fft_in[BUFFER_SIZE], fft_out[BUFFER_SIZE];

void audio_init() {
    adc_init();
    adc_gpio_init(ADC_PIN);
    adc_select_input(0);
    cfg = kiss_fft_alloc(BUFFER_SIZE, 0, NULL, NULL); // Aloca memória para FFT
}

void audio_capture(int16_t *buffer, uint16_t size) {
    // Captura de áudio do ADC
    for (int i = 0; i < size; i++) {
        buffer[i] = adc_read();  // Leitura do sinal de áudio
        sleep_us(1000000 / SAMPLE_RATE);  // Espera para manter a taxa de amostragem
    }
}

// Função para processar o áudio e calcular as frequências
float audio_process(int16_t *buffer, uint16_t size) {
    // Preenche o array fft_in com os dados do buffer
    for (int i = 0; i < size; i++) {
        fft_in[i].r = buffer[i];  // Real
        fft_in[i].i = 0;          // Imaginário (não usado)
    }

    // Executa a FFT
    kiss_fft(cfg, fft_in, fft_out);

    // Encontrar a frequência dominante
    float max_magnitude = 0;
    int max_index = 0;

    for (int i = 0; i < size / 2; i++) {
        float magnitude = sqrt(fft_out[i].r * fft_out[i].r + fft_out[i].i * fft_out[i].i);
        if (magnitude > max_magnitude) {
            max_magnitude = magnitude;
            max_index = i;
        }
    }

    // Calcula a frequência a partir do índice da FFT
    float frequency = (float)max_index * SAMPLE_RATE / size;
    printf("Frequência detectada: %.2f Hz\n", frequency);

    return frequency;
}
