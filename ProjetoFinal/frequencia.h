#ifndef FREQUENCIA_H
#define FREQUENCIA_H

#include <stdint.h>

// Vetor com as frequências das notas musicais (exemplo para notas da 4ª oitava)
extern const float frequencias[12];

// Função para obter a frequência de uma nota específica
float get_note(int note);

// Declaração da função init_frequencias
void init_frequencias(void);

// Declarações das funções capturar_frequencia e comparar_frequencia
float capturar_frequencia(void);
void comparar_frequencia(float freq, char* nota);

float get_note(int index);

#endif // FREQUENCIA_H
