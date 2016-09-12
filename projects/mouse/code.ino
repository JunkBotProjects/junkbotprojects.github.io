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
            Mouse.begin();
            while(SSerial.available()){
              switch(SSerial.read()){
                case'U':
                  Mouse.move(0, -40);
                break;
                case'D':
                  Mouse.move(0, 40);
                break;
                case'L':
                  Mouse.move(-40, 0);
                break;
                case'R':
                  Mouse.move(40, 0);
                break;
                case'l':
                  Mouse.click(MOUSE_LEFT);
                break;
                case'r':
                  Mouse.click(MOUSE_RIGHT);
                break;
              }
            }
            Mouse.end();
          }
          delay(100);
        }