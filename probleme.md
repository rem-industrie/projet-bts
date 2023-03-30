## Projet bts
## Problème carte
* [1. Court-circuit entre le VIN et le GND](#1.-Court-circuit-entre-le VIN-et-le-GND)
* [1. Court-circuit entre le VIN et le GND](#1.-Court-circuit-entre-le VIN-et-le-GND)

## Phase de test
Tableau utiliser pour le dépannage.

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

## 1. Court-circuit entre le VIN et le GND
Lors de la mise en tension de la carte aucune led ne s'allume après plusieurs recherche il y avait un très léger filet d’étain entre le VIN et le GND comme sur la photo ci-dessous

![vinEtGnd](./DOC/schema/probleme/procedure-led-alim-1.png)

- Le probleme:
Dès que la carte est sous tension l'arduino se met en erreur et aucune led sur la platine ne s'allume

- Pour dépanner:
C'est simple j'ai brancher câble par câble pour trouver le court-circuit.
La panne n'a pas était retrouvé avec cette solution.

J'ai ensuite utilisé le multimètre et tester les continuités, j'ai fini par tomber sur le problème.
- Solution: Un coup de cuter entre les pistes.
