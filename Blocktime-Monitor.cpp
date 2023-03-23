#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "YOURSSID";
const char* password = "YOURPASSWORD";
const char* url = "https://explorer.btc.com/btc/blocks"; // URL der Webseite
const String startString = "<span class=\"font-size-sm responsive-label nowrap secondary-text\">";
const String endString = "</span>";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Verbindung wird hergestellt...");
  }
  Serial.println("Verbunden mit WLAN");
}

String extractBetween(String data, String startStr, String endStr) {
  int startIndex = data.indexOf(startStr);
  if (startIndex == -1) {
    return "";
  }
  startIndex += startStr.length();
  int endIndex = data.indexOf(endStr, startIndex);
  if (endIndex == -1) {
    return "";
  }
  return data.substring(startIndex, endIndex);
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(url);
    int httpResponseCode = http.GET();
    if (httpResponseCode > 0) {
      String payload = http.getString();
      String extractedSpan = extractBetween(payload, startString, endString);
      String extractedNumber = extractBetween(extractedSpan, "of ", " Blocks");
      if (extractedNumber != "") {
        extractedNumber.trim();
        Serial.print("Extrahierter Text: ");
        Serial.println(extractedNumber);
      } else {
        Serial.println("Text nicht gefunden");
      }
    } else {
      Serial.print("Fehler beim Abrufen der Webseite. HTTP-Code: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  } else {
    Serial.println("Keine WLAN-Verbindung");
  }
  delay(20000);
}
