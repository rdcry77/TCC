#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>

//Configurações d Wi-Fi
const char* ssid = "CLNG"; //Nome da rede Wi-fi
const char* password = "16012727"; //Senha da rede Wi-fi

const char* serverName = "http://xxxxxx:1337/api/xxxxxx";//URL do Strapi no padrão http:// Seu_endereço_IPv4:1337 /api/ nome_do_content-type.

// Configurações bot do Telegram
const char* telegramToken = " xxxxxxxxx "; //Token do Bot do telegram
const char* telegramChatID = " xxxxxxxx "; //Meu ID do telegram

// Simulação do rio
char RiverStatus[15] = "Empty"; //Estado inicial
float RiverValue = 1.0;
char RiverDate[30] = "2025-01-01 00:00:00"; //Data de início
int stateDuration = 0;
bool simulationRunning = true;
bool riverIncreasing = true;  // Controle da direção (crescente ou decrescente)

// Envio de notificação via Telegram
void sendTelegramMessage(const char* message) {
  HTTPClient http;
  String url = "https://api.telegram.org/bot" + String(telegramToken) + "/sendMessage";
  String payload = "chat_id=" + String(telegramChatID) + "&text=" + message;

  http.begin(url);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  int httpResponseCode = http.POST(payload);
  if (httpResponseCode > 0) {
    Serial.println("Notificação enviada com sucesso para o Telegram!");
  } else {
    Serial.println("Falha ao enviar a notificação para o Telegram.");
  }

  http.end();
}

// Adicionando 30 minutos à smulação
void addHalfHour() {
  struct tm timeinfo;
  strptime(RiverDate, "%Y-%m-%d %H:%M:%S", &timeinfo);
  timeinfo.tm_min += 30;
  mktime(&timeinfo);
  strftime(RiverDate, sizeof(RiverDate), "%Y-%m-%d %H:%M:%S", &timeinfo);
  Serial.print("Nova data de simulação: ");
  Serial.println(RiverDate);
}
// Definição dos estados
float generateValueForState(const char* state) { //variação da altura
  if (strcmp(state, "Empty") == 0) 
    return random(10, 150) / 100.0;  //  0.1m - 1.5m
  else if (strcmp(state, "Moderate") == 0) 
    return random(151, 300) / 100.0;  // 1.5m - 3.0m
  else if (strcmp(state, "Full") == 0) 
    return random(301, 500) / 100.0;  // 3.0m - 5.0m
  else if (strcmp(state, "Overflowing") == 0) 
    return random(501, 800) / 100.0;  // 5.0m - 8.0m
  return 0.0;
}

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando...");

  // Conecta ao Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Conectando ao Wi-Fi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("Conectado!");
  Serial.println("Digite 'stop' no Monitor Serial para cancelar a simulação."); //Para a simulação
}

void loop() {
  // Verifica entrada no Monitor Serial
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    if (input.equalsIgnoreCase("stop")) {
      Serial.println("Simulação cancelada!");
      simulationRunning = false;
    }
  }

  if (!simulationRunning) {
    delay(1000);
    return;
  }

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/json"); 
    http.addHeader("Authorization", "Bearer  xxxxxxxxxxxxxxxx"); //Strapi API Token no padrão "Bearer token_do_strapi"

    // Garante que o valor do rio está correto
    RiverValue = generateValueForState(RiverStatus);

    // Envia mensagem pelo Telegram quando o estado chega no Overflowing
    if (strcmp(RiverStatus, "Overflowing") == 0) {
      sendTelegramMessage("⚠️ ALERTA: O RIO ESTÁ TRANSBORDANDO!"); //mensagem enviada
    }

    char postData[256];
    snprintf(postData, sizeof(postData), "{\"data\": {\"RiverStatus\":\"%s\", \"RiverValue\":%.1f, \"RiverDate\":\"%s\"}}", RiverStatus, RiverValue, RiverDate);

    int httpResponseCode = http.POST(postData);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("Resposta do servidor: " + response);
    } else {
      Serial.println("Erro no envio da requisição: " + String(httpResponseCode));
    }

    http.end();
    delay(10000);
    stateDuration++;

    addHalfHour();

    if (stateDuration >= 3) {
      // Transição entre estados
      if (riverIncreasing) { //crescente
        if (strcmp(RiverStatus, "Empty") == 0) strcpy(RiverStatus, "Moderate");
        else if (strcmp(RiverStatus, "Moderate") == 0) strcpy(RiverStatus, "Full");
        else if (strcmp(RiverStatus, "Full") == 0) strcpy(RiverStatus, "Overflowing");
        else {
          strcpy(RiverStatus, "Full");
          riverIncreasing = false;
        }
      } else { //decrescente
        if (strcmp(RiverStatus, "Overflowing") == 0) strcpy(RiverStatus, "Full");
        else if (strcmp(RiverStatus, "Full") == 0) strcpy(RiverStatus, "Moderate");
        else if (strcmp(RiverStatus, "Moderate") == 0) strcpy(RiverStatus, "Empty");
        else {
          strcpy(RiverStatus, "Moderate");
          riverIncreasing = true;
        }
      }
      stateDuration = 0;
    }
  } else {
    Serial.println("Desconectado do Wi-Fi!");
  }
}
