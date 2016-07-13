#include <NewPing.h>
void setup() {
  // put your setup code here, to run once:
  SSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(SSerial.available()){
    switch ( SSerial.read ) {
      case 'L' :
        motor1.run(FORWARD);
        motor2.run(BACKWARD);
      break;
      case 'R' :
        motor1.run(BACKWARD);
        motor2.run(FORWARD);
      break;
      case 'F' :
        motor1.run(FORWARD);
        motor2.run(FORWARD);
      break;
      case 'B' :
        motor1.run(BACKWARD);
        motor2.run(BACKWARD);
      break;
      case 'S' :
        motor1.run(RELEASE);
        motor2.run(RELEASE);
      break;
    }
  }
}
