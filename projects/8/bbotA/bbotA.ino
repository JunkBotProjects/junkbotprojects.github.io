        #include <SoftwareSerial.h>
        #include <NewPing.h>

        SoftwareSerial SSerial(9,10);
        NewPing sonar(11,12,200);
        boolean run = false;
        char b[5];

        void setup(){
          SSerial.begin(9600);
          Serial.begin(9600);
          pinMode(13, OUTPUT);
        }
        
        void loop() {
          delay(100);
          Serial.print(run);
          if(run){
            if(sonar.ping_cm()<20){
              SSerial.print("A");
              tone(13,260,300);
              delay(500);
              tone(13,0,0);
            }
          }
          if(SSerial.available())
            switch(SSerial.readChar()){
              case 'S':
                run = true;
              break;
              case 'E':
                run = false;
              break;
          }
        }