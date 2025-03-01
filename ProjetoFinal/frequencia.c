#include "frequencia.h"

// Frequências das notas (exemplo para uma oitava padrão)
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
