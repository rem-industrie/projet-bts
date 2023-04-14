## Projet bts

## Type mesure:
* [1. Capteur ASC712](#1.-Capteur-ASC712)
* [2. Mesure RS232](#2.-Mesure-RS232)
* [3. Mesure autre](#3.-Mesure-autre)

## 1. Capteur ASC712

|    Capteur    : |  |
|    :-----------     | :----------- |
| Tension ALIM |  +5V  |
| Tension à vide| +2.50 |
| Sensibilité | 40mV/A |
| Marche d'erreur |±0.8%  |

Formule pour obtenir la Tension à partir du courant:
- courant(A) x sensibilité(40mV)

| Tension         |  **Mesure Capteur(V)** |  **Mesure Capteur(A)**   |     Calcul     |
|    :----------- | :-----------           | :------------:           | :------------: |
|       +0V       |      +2,50V            |     +0A                  |     +0V        |
|      +5V        | +2,50V                 |   +0.07A                 |     +0.028V    |
|      +9V        | +2,51V                 |     +0.25A               |     +0.1V      |
|      +15V       | +2,51V                 |   +0.31A                 |     +0.124V    |


## 2. Mesure RS232
Ce projet consiste à capter le courant et une fois fais le renvoyer sur une passerelle MQTT envoyer en RS232.

## 3. Mesure autre


- Regulateur

|     Pins        |             Tension   |
|    :----------- | :-----------          |
|     ADJ(1)      |      +6.22V           |
|     VO(2)       |      +7.50V           | 
|     VIN(3)      | +15V (change selon l'alim)|

- Mesure Transmission:

|                 |             Tension   |
|    :----------- | :-----------          |
|    TX           |      +4,70V           |
|     ESP         |      +3.37V           | 
|     SCL         |      +4.99V           |
|     SDA         |      +4.99V           |

- Button:

|                 |             Tension   |
|    :----------- | :-----------          |
|    Entré        |      +4.95V           |
|    Sortie       |      +1.80V           |

- Capteur:

|                 |             Tension   |
|    :----------- | :-----------          |
|    Vcc          |      +5V              |
|    Out          |    +2.5V voir +2.49V  |

- Mesure:

|                 |             Tension   |
|    :----------- | :-----------          |
|    Vin-ard      |      +7,47V           |
|    +5 ard       |          +5V          |
|   Alim-led      |        +2.10V         |
|   led-led       |        +4.70V         |
