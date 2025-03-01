#include "pico/stdlib.h"
#include "audio.h"
//#include "exibicao.h"
//#include "feedback.h"
#include "frequencia.h"
#include "lib/ssd1306.h"

#define LED_R 11
#define LED_G 12
#define LED_B 13
#define BUZZER 15

void testar_frequencia();



void setup() {
    stdio_init_all();
    //init_microfone();
    //init_display();
    //init_feedback();
    init_frequencias();
    gpio_init(LED_R);
    gpio_init(LED_G);
    gpio_init(LED_B);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_set_dir(LED_B, GPIO_OUT);
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
}

int main() {
    setup();

    testar_frequencia();
    while (true) {
        float freq = capturar_frequencia();
        char nota[4];
        comparar_frequencia(freq, nota);
        //exibir_nota(nota);
        //fornecer_feedback(nota);
    }
    return 0;
}