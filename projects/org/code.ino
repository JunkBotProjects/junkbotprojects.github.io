        #include <SoftwareSerial.h>
        SoftwareSerial SSerial(9,10);
        char inp;
        void setup(){
          SSerial.begin(9600);
          while (!SSerial) {
            ;
          }
        }
        
        void loop() {
          if(SSerial.available()){
            Keyboard.begin();
            while(SSerial.available()){
              Keyboard.write(SSerial.read());
            }
            Keyboard.end();
          }
          delay(100);
        }
