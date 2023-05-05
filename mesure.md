## Projet bts

## Type mesure:
* [1. Capteur ASC712](#1.-Capteur-ASC712)
* [2. Mesure RS232](#2.-Mesure-RS232)
* [3. Mesure autre](#3.-Mesure-autre)
* [4. Test capteur](#4.Test-capteur)

## 1. Capteur ASC712

|    Capteur    : |              |
|  :-----------   | :----------- |
|   Tension ALIM  |      +5V     |
| Tension à vide  |     +2.50    |
|   Sensibilité   |     40mV/A   |
| Marche d'erreur |     ±0.8%    |

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
![mesure final test](https://user-images.githubusercontent.com/58986671/233841365-fdf63a05-1779-42c7-bfc0-981ae5bfedca.png)





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

## 4. Test capteur

| Nombre ampoule(s) 2W |  Nombre ampoule(s) 10W |  **Mesure Capteur(A)**   |     Calcul     |   Tensio(V)    |
|    :-----------      | :-----------           | :------------:           | :------------: | :------------: |
|         0            |            0           |     +0A                  |     +0V        |     +2.49V     |
|         0            |            1           |     +0.80A               |     +0.8V      |     +2.52V     |
|         0            |            2           |     +1.66A               |     +1.6V      |     +2.56V     |
|         1            |            2           |     +1.90A               |     +1.84V     |     +2.57V     |
|         2            |            2           |     +2.14A               |     +2.08V     |     +2.58V     |
|         3            |            2           |     +2.39A               |     +2.32V     |     +2.59V     |

Calcul: P / U