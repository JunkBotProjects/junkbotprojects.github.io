        #include <SoftwareSerial.h>
        SoftwareSerial SSerial (9,10);
        char b[5];
        int speed=255;
        int lp = 3;
        int ln = 5;
        int rp = 6;
        int rn = 11;
        void setup() {
          // put your setup code here, to run once:
          SSerial.begin(9600);
        }

        void loop() {
          // put your main code here, to run repeatedly:
          if(SSerial.available()){
            switch(SSerial.read()){
              case 'L' :
                analogWrite(lp,0);
                analogWrite(ln,speed);
                analogWrite(rp,speed);
                analogWrite(rn,0);
              break;
              case 'R' :
                analogWrite(rp,0);
                analogWrite(rn,speed);
                analogWrite(lp,speed);
                analogWrite(ln,0);
              break;
              case 'F' :
                analogWrite(lp,0);
                analogWrite(ln,speed);
                analogWrite(rp,0);
                analogWrite(rn,speed);
              break;
              case 'B' :
                analogWrite(lp,speed);
                analogWrite(ln,0);
                analogWrite(rp,speed);
                analogWrite(rn,0);
              break;
              case 'S' :
                analogWrite(lp,0);
                analogWrite(ln,0);
                analogWrite(rp,0);
                analogWrite(rn,0);
              break;
            }
            //set speed
            speed = (SSerial.read()-'0') * 25;
          }
        }
