#include "conf.h"
int val1; // A BOUGER
int val2; // A BOUGER
int CAMdetection;  //A BOUGER


void loop() {
  // put your main code here, to run repeatedly:
  /*programme moteurs dÃ©placement*/
 if ((WET==LOW)&& (pump==LOW) && (MoteurPignonFront==LOW) && (MoteurPignonBack==LOW)) 
  {
 void movingForward
 }  
 else 
 {
 void movingBack
}


/* Selon l'humiditÃ©, dÃ©finir un certain temps d'arrosage (pompe allumÃ©e) -> arbitraire avant les tests
    tant que le robot ne dÃ©tecte pas une tomate, ou n'arrose pas, il doit continuer Ã  avancer (2 moteurs de dÃ©placement)
  moteur pignon crÃ©maillÃ¨re dÃ©clenchÃ© Ã  chaque fois qu'une bonne plante est dÃ©tectÃ©e par la camÃ©ra
  capteur fin de course activÃ© -> on arrÃªte le moteur pignon crÃ©maillÃ¨res puis on remonte aprÃ¨s
  la dÃ©tecction du capteur humiditÃ© (+-5sec), puis on redÃ©marre le moteur, arrÃªt lorsque le 2Ã¨me capteur fin de course est activÃ©
  comment faire un arduino qui peut lire un autre programme, rÃ©cupÃ©rer les donnÃ©es : 3channels serial sur la arduino mega. Multithread.
*/

