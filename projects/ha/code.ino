        #include <SoftwareSerial.h>
        SoftwareSerial SSerial (2,3);

        int PIN = 4;

        void setup() {
          // put your setup code here, to run once:
          SSerial.begin(9600);
          Serial.begin(9600);
          pinMode(PIN, OUTPUT);
        }

        void loop() {
          // put your main code here, to run repeatedly:
          if(SSerial.available()){
            switch ( SSerial.read ) {
              case '1' :
                digitalWrite(PIN, HIGH);
              break;
              case '0' :
                digitalWrite(PIN, LOW);
              break;
              default :
                Serial.print("403")
              break;
            }
          }
        }