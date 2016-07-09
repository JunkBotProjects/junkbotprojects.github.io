        #include <SoftwareSerial.h>
        SoftwareSerial SSerial (2,3);

        #include <AFMotor.h>
        AF_DCMotor motor1(1, MOTOR12_64KHZ);
        AF_DCMotor motor2(2, MOTOR12_64KHZ);

        void setup() {
          // put your setup code here, to run once:
          SSerial.begin(9600);
          motor1.setSpeed(200);
          motor2.setSpeed(200);
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