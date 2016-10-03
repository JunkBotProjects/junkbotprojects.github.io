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
          if(SSerial.available()){
            SSerial.readString().toCharArray(b,5);
            analogWrite(PIN,(strtoul(b, 0, 16)+1)*25);
          }
        }
