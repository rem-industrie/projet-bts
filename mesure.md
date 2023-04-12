## Projet bts

## Type mesure:
* [1. Capteur ASC712](#1.-Capteur-ASC712)
* [2. Mesure RS232](#2.-Mesure-RS232)

## 1. Capteur ASC712

|    Capteur    : |  |
|    :-----------     | :----------- |
| Tension ALIM |  +5V  |
| Tension à vide| +2,50 |
| Sensibilité | 40mV/A |
| Marche d'erreur |±0.8%  |

Formule pour obtenir la Tension à partir du courant:
- courant(A) x sensibilité(40mV)

| Tension |  **Mesure Capteur**  |     Calcul     |
|    :-----------     | :----------- | :------------: |
|       +0V       |      +2,50        |     +0V    |
|      +9V        | +2,51  |     +0,..V   |
|      +15V       | +2,51V |   +0,..V  |


## 2. Mesure RS232
Ce projet consiste à capter le courant et une fois fais le renvoyer sur une passerelle MQTT envoyer en RS232.
