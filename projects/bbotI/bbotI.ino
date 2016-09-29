        #include <SoftwareSerial.h>
        #include <NewPing.h>

        SoftwareSerial SSerial(9,10);
        NewPing sonar(11,12,200); // NewPing setup of pins and maximum distance.
        boolean run = false;
        char b[5];

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
            SSerial.readString().toCharArray(b,5);
            switch((char)strtoul(b, 0, 16)){
              case 'S':
                run = true;
              break;
              case 'E':
                run = false;
              break;
            }
        }
