#ifndef AUDIO_H
#define AUDIO_H

#include <stdint.h>  // Adicione esta linha

#define SAMPLE_RATE 4000  // Taxa de amostragem em Hz
#define BUFFER_SIZE 256   // Tamanho do buffer para processamento

extern void audio_init(void);
extern void audio_capture(int16_t *buffer, uint16_t size);
extern float audio_process(int16_t *buffer, uint16_t size);
extern int detect_zero_crossing(int16_t *buffer, uint16_t size);  // Função de detecção de zero-crossing
extern float calculate_frequency(int crossings);  // Função para calcular a frequência

#endif
