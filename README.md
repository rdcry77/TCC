# Explicação Básica do Projeto e Como Fazer Uma Simulação

Este repositório contém o código para a simulação de monitoramento de cheia de rios

## Itens Necessários
  - **ESP-32**
  - **Cabo USB para conexão**
  - **PC ou Notebook**

## Instalações Necessárias

É necessária a instalação de algumas ferramentas para que o projeto rode e a simulação seja feita com êxito.

### 1. **Arduino IDE**
  - **Funcionalidade?** O arduino IDE é um software de código aberto utilizado para escrever, compilar e enviar código para microcontroladores. Facilitando-se sua programação.
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
  - **Funcionalidade?** O Strapi é Sistema de Gerenciamento de Conteúdo de código aberto com uma interface de administração que cria e gerencia conteúdos como sites e aplicativos.
  - **Tem como pré-requisito a instalação do do Node.JS LTS**
    - Acesse [Node.js official website](https://nodejs.org/).
  - **Para fazer sua instalação basta apenas seguir o site oficial**
    - Acesse [Strapi official website](https://strapi.io/) 

### 4. **Telegram**
  - **Funcionalidade?** O Telegram é um serviço de mensagens instantâneas baseado na nuvem e vai ser responsável pelo nosso alerta de perigo.
  - Abra o Telegram e procure por "**BotFather**".
  - Digite o seguinte comando: **(/newbot)**.
  - Nomeie o seu bot e armazene o Token do Telegram.
  - Pesquise por "**IDBot**".
  - Digite o seguinte comando: **(/start)** e armazene o ID de Usuário.

  ## Como Rodar o Projeto

  1 **Baixar Código pelo GitHub**
    - Faça o download do código em formato ZIP pelo GitHub: 
    [Sistema De Monitoramento e Alerta de Aumento Fluvial e Cheias de Rios.](https://github.com/rdcry77/TCC) 
      - Clique no botão "Code" e selecione "Download ZIP"

      
  2. **Painel do Strapi**
    - Abra o Powershell ou terminal(prompt de comando) e execute o comando:

      **cd /nome_da_pasta_do_projeto**
      
      **npm run develop**
  
      - Agora basta apenas colar o link gerado no navegador.
      - Selecione a opção "**Content-Type-Builder**".
      - Crie uma nova Coleção.
      - Gere variáveis dos tipos Date/Time, Number e Enumeration.
        **Especificações**
          - Date/Time em formato: (01/11/2011 01:11 AM).
          - Number em formato: (Decimal).
          - Enumeration com os estados (Empty, Moderate, Full, Overflowing).
      - Vá em Configurações - Roles.
        - Modifique o conteúdo da Permissão "Public" (Ícone do lápis).
        - Conceda todas as permissões para o Content-Type-Builder criado (Select all).
        - Crie uma Token de API com duração indeterminada (Unlimited) e acesso completo (Full Access).
        - Salve as mudanças.


  3. **Telegram**
    - Procure pelo nome do bot criado.
    - Inicie-o com **(/start)**.
       
  4. **Arduino IDE**
    - Abra o arquivo .ino do ZIP baixado pelo Arduino IDE.
    - Altere o código de forma adequada.
      **Dados importantes**
        - Configurações da rede Wi-Fi.
        - URL do Strapi de acordo com o endereço IPv4 e nome do projeto Strapi.
            - Em caso de dúvidas, basta apenas acessar o cmd e digitar "**ipconfig**".
        - Configurações do Bot Telegram (Token/ChatID).
        - Token de autorização da API do Strapi.
          
  - Plug o ESP-32 à máquina pelo cabo USB.
  - Faça o upload do código para o micro-controlador.

  **A simulação será iniciada**
    - Pode ser acompanhada pelo Monitor Serial do IDE (Ctrl + Shift + M)
    - Pode ser acompanhada pelo Painel do Strapi (Content Manager)
    - Quando o estado de "**Overflowing**" for atingido, a notificação será enviada pelo Telegram
      **Extra**
        - Caso deseje parar a simulação, basta apenas digitar **(/stop)**.
        - Lembre-se de não fechar o PowerShell/Cmd onde foi aberto o Strapi.
       
  
   
  
      


  
