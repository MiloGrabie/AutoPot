int LeftMotorFront = 38 ;
int LeftMotorBack = 37 ;
int RightMotorFront = 29 ;
int RightMotorBack = 30 ;

void setup() {
  // put your setup code here, to run once:
pinMode (LeftMotorFront,OUTPUT);
pinMode (LeftMotorBack,OUTPUT);
pinMode (RightMotorFront,OUTPUT);
pinMode (RightMotorBack,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LeftMotorFront, HIGH) ;
  digitalWrite(LeftMotorBack, LOW);
  digitalWrite(RightMotorFront, HIGH);
  digitalWrite(RightMotorBack, LOW);
 
 // digitalWrite(RightMotorFront, HIGH);
//  digitalWrite(RightMotorBack, LOW);
}
