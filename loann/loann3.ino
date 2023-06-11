#include <WiFiManager.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
int amper;
int temp;
int etatBT;

const char *ssid = "Loann";
const char *password = "loannheyms1";

ESP8266WebServer server(80);

void handle_root()
{

    // C'est ici qu'on construit la page web:

    server.send(200, "html", "<head>  <title>ESP8266</title> </head> "
                             "<body><H1>Page web g&eacute;n&eacute;r&eacute;e par votre ESP8266</H1>"
                             "<p>Valeur du courant : " +
                                 String(amper) + "</p>"
                                                 "<p>" +
                                 etatBT + "</p>"
                                          "<p>valeur de la temp&eacute;rature : " +
                                 String(temp) + "</p>");

    delay(100);
}

void setup(void)
{

    // Affichage dans le moniteur série:
    Serial.begin(115200);

    // Connexion au réseau WiFi
    WiFi.begin(ssid, password);
    Serial.print("\n\r \n\rConnection au reseau en cours");

    // On attend la connexion
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Nom du reseau WiFi: ");
    Serial.println(ssid);
    Serial.print("Adresse IP de la page web: ");
    Serial.println(WiFi.localIP());

    server.on("/", handle_root);

    server.begin();
    Serial.println("Le serveur web est en fonction.");
}

void loop()
{

    server.handleClient();
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("PAGE WEB ESP IP:");
    lcd.setCursor(0, 1);
    lcd.print("");
    lcd.println(WiFi.localIP());
}