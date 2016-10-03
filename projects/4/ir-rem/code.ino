        #include <SoftwareSerial.h>
        #include <IRremote.h>
        SoftwareSerial BTMod (2,3);
        int RECV_PIN = 11;
        IRrecv irrecv(RECV_PIN);

        decode_results R1, R2;

        void setup() {
          // put your setup code here, to run once:
          BTMod.begin(9600);
          
        }

        void loop() {
          if(irrecv.decode(&results)){  
          translateIR(); 
          irrecv.resume(); // receive the next value
        } 
        }