        #include <SoftwareSerial.h>
        SoftwareSerial SSerial (10,11);
        String inString = ""; 
        int PIN = 9;
        void setup() {
          // put your setup code here, to run once:
          SSerial.begin(9600);
          Serial.begin(9600);
        }

        void loop() {
          // put your main code here, to run repeatedly:
          inString="";
          if((SSerial.available())){
            while(SSerial.available()){
              inString += (char)SSerial.read();
            }
            analogWrite(PIN,inString.toInt());
          }
        }
