#ifndef FREQUENCIA_H
#define FREQUENCIA_H

#include <stdint.h>

// Vetor com as frequências das notas musicais (exemplo para notas da 4ª oitava)
extern const float frequencias[12];

// Função para obter a frequência de uma nota específica
float get_note(int note);

#endif // FREQUENCIA_H
