# Explicação Básica do Projeto e Como Fazer Uma Simulação

Este repositório contém o código para a simulação de monitoramento de cheia de rios

## Itens Necessários
  - **ESP-32**
  - **Cabo USB para conexão**
  - **PC ou Notebook**

## Instalações Necessárias

É necessária a instalação de algumas ferramentas para que o projeto rode e a simulação seja feita com êxito.

### 1. **Arduino IDE**
  - **Do que se trata?** O arduino IDE é um software de código aberto utilizado para escrever, compilar e enviar código para microcontroladores. Facilitando-se sua programação.
  - **Como é feita a sua instalação?**
    - Acesse [Arduino official website](https://www.arduino.cc/en/software/).
    - Faça o Download referente ao sistema operacional da máquina (Windows, Linux ou MacOS).

### 2. **Instalando o ESP-32 no Arduino IDE**
  - **Essencial para o reconhecimento e funcionamento da placa**
    - Abra o IDE
    - Vá em Files - Preferences
    - Insira a seguinte URL no campo abaixo: (https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json)
    - Abra a opção de Board Manager, pesquise por "ESP32 Espressif" e faça sua instalação.

### 3. **Strapi API**
  - **Do que se trata?** O Strapi é Sistema de Gerenciamento de Conteúdo de código aberto com uma interface de administração que cria e gerencia conteúdos como sites e aplicativos.
  - **Tem como pré-requisito a instalação do do Node.JS LTS**
    - Acesse [Node.js official website](https://nodejs.org/).
  - **Para fazer sua instalação basta apenas seguir o site oficial**
    - Acesse [Strapi official website](https://strapi.io/) 

  ## Como Rodar o Projeto
  - **Painel do Strapi**
    - Abra o Powershell ou terminal(prompt de comando) e execute o comando:

      cd /caminho/para/a/pasta/do/projeto
