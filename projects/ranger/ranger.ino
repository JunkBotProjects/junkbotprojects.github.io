        //Libraries
        #include <SoftwareSerial.h>
        #include <NewPing.h>

        //Variables
        SoftwareSerial SSerial(9,10);
        boolean run = false;
        char b[5];
        NewPing sonar(11,12,200); // NewPing setup of pins and maximum distance.
        
        void setup(){
          SSerial.begin(9600);
          Serial.begin(9600);
        }
        
        void loop() {
          delay(100);
          if(run)
            Serial.println('Sensor is On');
          else
            Serial.println('Sensor is Off');
          if(run){
            SSerial.print("0x3"+sonar.ping_cm()/10);            
            SSerial.println("0x3"+sonar.ping_cm()%10);
            delay(900);
          }
          else
            SSerial.println("Sensor Disabled");
          
          if(SSerial.available())
          SSerial.readString().toCharArray(b,5);
          switch((char)strtoul(b, 0, 16)){
            case 'S':
              run = true;
            break;
            case 'E':
              run = false;
            break;
            default:
              SSerial.println("0x340x300x34");
          }
        }