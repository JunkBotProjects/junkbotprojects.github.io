        #include <SoftwareSerial.h>
        SoftwareSerial SSerial (9,10);
        #include <AFMotor.h>
        AF_DCMotor motor1(1);
        AF_DCMotor motor2(2);
        char ch;
        void setup() {
          // put your setup code here, to run once:
          SSerial.begin(9600);
          motor1.setSpeed(200);
          motor2.setSpeed(200);
        }

        void loop() {
          // put your main code here, to run repeatedly:
          if(SSerial.available()){
            ch = SSerial.read();
            Serial.println(ch);
            switch ( ch ){
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
            ch = SSerial.read();
            motor1.setSpeed(20 * (int(ch)+1) );
            motor2.setSpeed(20 * (int(ch)+1) );
          }
        }
