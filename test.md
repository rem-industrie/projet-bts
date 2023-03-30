## Projet bts
## Problème carte
* [Info General](#Info-General)
* [Contenue](#Contenue)
* [Technologies](#technologies)
* [Schéma structurelle](#Schéma-structurelle)
* [Carte](#Carte)
* [Setup](#setup)

## Info General
Ce projet consiste à capter le courant et une fois fais le renvoyer sur une passerelle MQTT envoyer en RS232.

| **Fonction** | Statut probleme|  Description  |    Tension    |
| :----------- | :------------: | ------------: | ------------: |
| CONN Capteur |       Ok       |               |      +5V      |
|     SDA     |  IMPORTANT  |  Problème conception inversion conn | +5V  |
|     SCL     |  IMPORTANT  |  Problème conception inversion conn | +5V  |
| BOUTON |       Ok       |               |      +V      |
|     LED ALIM    |  GRAVE  |  Court-circuit entre Vin et Gnd | +5V  |
|     LED RX   |  MOYEN |  Court-circuit entre entre les pin led | +5V  |
| ALIM PRINCIPAL |       Ok       |               |      +28V     |
| VIN |  IMPORTANT  | SOUS ALIMENTATION ARDUINO PONT DIVISEUR  |      +7.40V     |
