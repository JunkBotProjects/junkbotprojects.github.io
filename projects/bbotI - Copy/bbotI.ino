        #include <SoftwareSerial.h>
        #include <NewPing.h>
        #define TRIGGER_PIN  9  // Arduino pin tied to trigger pin on the ultrasonic sensor.
        #define ECHO_PIN     12  // Arduino pin tied to echo pin on the ultrasonic sensor.
        #define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
        SoftwareSerial SSerial(10,11);
        boolean run = false;
        NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
        
        void setup(){
          SSerial.begin(9600);
          Serial.begin(9600); 
        }
        
        void loop() {
          delay(50);
          Serial.print(run);
          if(run){
            if(sonar.ping_cm()<20){
              SSerial.print("ALERT");
            }
          }else{
            //SSerial.print("NR");
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
