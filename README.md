Bitcoin-Blocktime-Monitor-ESP32

Dieses Skript ermöglicht es Ihnen, die aktuelle Anzahl der Bitcoin-Blöcke von einer Webseite zu extrahieren und auf einem ESP32-Mikrocontroller anzuzeigen. Inhaltsverzeichnis

Einführung
Abhängigkeiten
Konfiguration

Einführung

Das Skript "Bitcoin-Blocktime-Monitor-ESP32" ist ein einfaches Programm, das auf einem ESP32-Mikrocontroller ausgeführt wird. Es liest die Anzahl der Bitcoin-Blöcke von einer Webseite und gibt diese auf dem seriellen Monitor aus. Abhängigkeiten

Um das Skript auszuführen, müssen die folgenden Bibliotheken in der Arduino IDE oder Ihrer bevorzugten Entwicklungsumgebung installiert sein:

WiFi.h: Ermöglicht die Verbindung des ESP32 mit einem WLAN-Netzwerk.
HTTPClient.h: Ermöglicht das Senden von HTTP-Anfragen und das Empfangen von Antworten.

Konfiguration

Bevor Sie das Skript ausführen, müssen Sie es für Ihre Bedürfnisse konfigurieren. Ändern Sie die folgenden Zeilen im Skript entsprechend:

const char* ssid = "YOURSSID";
const char* password = "YOURPASSWORD";

Ersetzen Sie YOURSSID und YOURPASSWORD durch die SSID und das Passwort Ihres WLAN-Netzwerks.
