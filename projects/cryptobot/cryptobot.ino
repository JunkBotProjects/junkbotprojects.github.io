        //Install and use the AESLib available at https://github.com/DavyLandman/AESLib
        #include <AESLib.h>
        uint8_t key[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
        char data[] = "Athul is Nice !";
        void pw2key(String pw){
          pw.toLowerCase();
          pw.trim();
          String pwl = "";
          while(pwl.length()<32){
            pwl.concat(pw);
          }
          pwl = pwl.substring(0,32);
          Serial.println(pwl);
          for(int i=0;i<32;i++){
            key[i]=pwl[i]-'a';
            Serial.print(key[i]);
            Serial.print(",");
          }
          Serial.println(data);
          aes256_enc_single(key, data);
          Serial.println(data);
          aes256_dec_single(key, data);
          Serial.println(data);
        }
        void setup(){
          Serial.begin(115200);
          /*
          aes256_enc_single(key, data);
          Serial.print("encrypted:");
          Serial.println(data);
          aes256_dec_single(key, data);
          Serial.print("decrypted:");
          Serial.println(data);
          */
        }
        void loop(){
          if(Serial.available())
            pw2key(Serial.readString());
          
        }
