        void setup(){}
        void loop() {
        	analogWrite(A1,(analogRead(A0)<200)?random(1024):0);
        	delay(random(250,2000));
        }