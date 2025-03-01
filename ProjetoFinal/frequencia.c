#include "frequencia.h"
#include <math.h>
#include <stdio.h>

// Definição do vetor com as frequências das notas musicais (exemplo para notas da 4ª oitava)
const float frequencias[12] = {
    261.63, // C4
    277.18, // C#4
    293.66, // D4
    311.13, // D#4
    329.63, // E4
    349.23, // F4
    369.99, // F#4
    392.00, // G4
    415.30, // G#4
    440.00, // A4
    466.16, // A#4
    493.88  // B4
};

float get_note(int note) {
    if (note >= 0 && note < 12) {
        return frequencias[note];
    }
    return -1.0f; // Retorna -1 se a nota estiver fora do intervalo
}

void testar_frequencia() {
    int note_index = 2; // Exemplo: E4
    float frequency = get_note(note_index);

    if (frequency != -1.0f) {
        printf("A frequência da nota %d é: %.2f Hz\n", note_index, frequency);
    } else {
        printf("Nota inválida!\n");
    }
}

void init_frequencias(void) {
    // Inicialização das frequências, se necessário
}

float capturar_frequencia(void) {
    // Código para capturar a frequência de uma nota
    // Este é um exemplo simples, ajuste conforme necessário
    float freq = 440.0;  // Exemplo: frequência do A4
    return freq;
}

void comparar_frequencia(float freq, char* nota) {
    // Código para comparar a frequência capturada com as notas musicais
    // e determinar qual nota está mais próxima da frequência capturada
    int index = -1;
    float min_diff = 1e6;
    for (int i = 0; i < 12; ++i) {
        float diff = fabs(freq - frequencias[i]);
        if (diff < min_diff) {
            min_diff = diff;
            index = i;
        }
    }
    
    // Exemplo de mapeamento de índice para nomes de notas
    const char* notas[12] = {
        "C4", "C#4", "D4", "D#4", "E4", "F4", "F#4", "G4", "G#4", "A4", "A#4", "B4"
    };
    
    if (index != -1) {
        snprintf(nota, 4, "%s", notas[index]);
    } else {
        snprintf(nota, 4, "N/A");
    }
}
