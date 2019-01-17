#define motorPignonUp 23
#define motorPignonDown 24
void setup() {
  // put your setup code here, to run once:
  pinMode(motorPignonUp, OUTPUT);
  pinMode(motorPignonDown, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (motorPignonDown, HIGH);
  digitalWrite (motorPignonUp, LOW) ;
  delay(2000);
   digitalWrite (motorPignonDown, LOW);
  digitalWrite (motorPignonUp, LOW) ;
    delay(1000);
     digitalWrite (motorPignonDown, LOW);
  digitalWrite (motorPignonUp, HIGH) ;
    delay(2000);  

}
