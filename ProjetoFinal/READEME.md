
# Afinador de Guitarra - Projeto Final

Este é um projeto de afinador de guitarra desenvolvido usando o Raspberry Pi Pico W e a placa BitDogLab. O sistema captura a frequência das notas musicais através de um microfone e fornece feedback visual e auditivo para o usuário, utilizando um display OLED SSD1306, LEDs RGB e buzzer.

## Componentes Utilizados

- **Raspberry Pi Pico W** (usado como microcontrolador principal)
- **Microfone** (para captura das frequências das notas)
- **Display OLED SSD1306** (para exibição da nota musical detectada)
- **LEDs RGB** (para feedback visual)
- **Buzzer** (para feedback sonoro)
- **BitDogLab** (placa de desenvolvimento)

## Funcionalidades

- **Captura de Frequências:** O sistema captura as frequências emitidas pela guitarra através do microfone.
- **Exibição da Nota Musical:** As frequências são mapeadas para notas musicais, e a nota detectada é exibida no display OLED.
- **Feedback Visual e Sonoro:** LEDs RGB e um buzzer fornecem feedback ao usuário, indicando se a nota está afinada ou não.

## Estrutura do Código

O código principal foi desenvolvido em C utilizando o **Pico SDK** e é dividido nas seguintes partes:

- **Inicialização de Componentes:** Configuração dos pinos GPIO, display OLED, LEDs RGB e buzzer.
- **Loop de Captura e Comparação:** O sistema captura as frequências e as compara com as notas musicais definidas para dar feedback.
- **Feedback Visual e Sonoro:** Com base na comparação das frequências, LEDs RGB e buzzer fornecem indicações sobre a afinação.

## Como Rodar o Projeto

1. **Clone este repositório:**
   ```bash
   git clone https://github.com/elioenai365/ProjetoFinal.git
   ```

2. **Instale as dependências do Pico SDK e configure o ambiente de desenvolvimento.**
   
3. **Compile o código utilizando o VS Code e a extensão do Pico SDK.**

4. **Carregue o firmware para o Raspberry Pi Pico W e conecte a placa BitDogLab.**

5. **Conecte o microfone e a guitarra ao sistema. O display OLED e os LEDs RGB fornecerão o feedback de afinação.**

## Como Funciona

- **Passo 1:** A guitarra é tocada, e o microfone captura o som da nota.
- **Passo 2:** A frequência da nota é extraída e comparada com as frequências mapeadas para as notas musicais.
- **Passo 3:** O display OLED exibe a nota detectada, enquanto o LED RGB e o buzzer fornecem feedback sobre a afinação.

## Contribuindo

Se você deseja contribuir para o projeto, faça um fork deste repositório e envie pull requests com melhorias ou correções.

## Licença

Este projeto é licenciado sob a licença MIT - veja o arquivo [LICENSE](LICENSE) para mais detalhes.

---

Esse README oferece uma visão geral do projeto, como configurá-lo, e descreve a funcionalidade do afinador de guitarra que você está desenvolvendo. Se precisar de mais detalhes ou ajustes, é só me avisar!