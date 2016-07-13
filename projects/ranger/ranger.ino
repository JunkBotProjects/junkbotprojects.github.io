        #include <SoftwareSerial.h>
        #include <NewPing.h>
        #define TRIGGER_PIN  9  // Arduino pin tied to trigger pin on the ultrasonic sensor.
        #define ECHO_PIN     12  // Arduino pin tied to echo pin on the ultrasonic sensor.
        #define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
        int tonePin = 13;
        SoftwareSerial SSerial(10,11);
        boolean run = false;
        NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
        
        void setup(){
          SSerial.begin(9600);
          Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
          pinMode(tonePin, OUTPUT);
        }
        
        void loop() {
          delay(50);
          Serial.print(run);
          if(run){
            if(sonar.ping_cm()<20){
              SSerial.print("BURGLAR");
              tone(13,260,300);
              delay(500);
              tone(13,0,0);
            }
          }else{
            SSerial.print("NR");
          }
          if(SSerial.available())
          switch(SSerial.read()){
            case 'S':
              run = true;
            break;
            case 'E':
              run = false;
            break;
          }
        }