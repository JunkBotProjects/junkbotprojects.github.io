        #include <NewPing.h>
        #define TRIGGER_PIN  9
        #define ECHO_PIN     12
        #define MAX_DISTANCE 200
        NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

        int timeout = 750;
        int fade  = 250;
        int lastseen = timeout+fade+fade-1;
        int i;
        void setup(){
          
        }

        void loop() {
          delay(20);
          if(sonar.ping_cm()<10){
            lastseen = 0;
          }
          if(lastseen<(timeout+(2*fade)))
            lastseen ++;
          if(lastseen<=fade){
            analogWrite(10,map(lastseen,0,fade,0,255));
            Serial.println(map(lastseen,0,fade,0,255));
          }
          if(lastseen>fade && (lastseen<(timeout+fade))){
            analogWrite(10,255);
            Serial.println("255");
          }
          if(lastseen>=(timeout+fade)){
            analogWrite(10, map(lastseen-(timeout+fade),0,fade,255,0) );
            Serial.println(map(lastseen-(timeout+fade),0,fade,255,0));
          }
        }
