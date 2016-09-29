        #include <SoftwareSerial.h>
        #include <NewPing.h>

        SoftwareSerial SSerial(9,10);
        NewPing sonar(11,12,200); // NewPing setup of pins and maximum distance.
        boolean run = false;

        void setup(){
          SSerial.begin(9600);
          Serial.begin(9600);
        }
        
        void loop() {
          delay(100);
          Serial.print(run);
          if(run){
            if(sonar.ping_cm()<20){
              SSerial.print("0x42");
            }
          }
          if(SSerial.available())
            switch( String(SSerial.read(),HEX)[0] ){
              case 'S':
                run = true;
              break;
              case 'E':
                run = false;
              break;
            }
        }
