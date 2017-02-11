const int PinR = 3, PinG = 6, PinB = 5;
int temp = 5; 
int v = 1;
long int c = 190568851; //001011010110111101100110010011
boolean r = true, g = false, b = false;

void setup() {
  Serial.begin(9600);
  pinMode(PinR, OUTPUT);
  pinMode(PinG, OUTPUT);
  pinMode(PinB, OUTPUT);
  pinMode(4, OUTPUT);
  aumenta(PinR);    //001
}

void loop() {
    Serial.print("RED:"); Serial.println (c&1);
    if ((c&1) == true && r == false){aumenta(PinR); r = true;} else if ((c&1) == false && r == true) {diminuisci(PinR); r = false;}
    c = c >> 1;
    Serial.print("GREEN:"); Serial.println (c&1);
    if ((c&1) == true && g == false){aumenta(PinG); g = true;} else if ((c&1) == false && g == true) {diminuisci(PinG); g = false;}
    c = c >> 1;
    Serial.print("BLUE:"); Serial.println (c&1);
    if ((c&1) == true && b == false){aumenta(PinB); b = true;} else if ((c&1) == false && b == true) {diminuisci(PinB); b = false;}
    c = c >> 1;
    if (c == 0){c = 190568851;}
  }
                       //BGR
  /*aumenta   (PinG);    //011
  diminuisci(PinR);    //010
  aumenta   (PinB);    //110
  diminuisci(PinG);    //100
  aumenta   (PinR);    //101
  aumenta   (PinG);    //111
  diminuisci(PinR);    //110
  diminuisci(PinB);    //010
  aumenta   (PinR);    //011
  diminuisci(PinG);    //001
}*/

void aumenta(int pin) {
 for (int i = 0; i < 255; i+=v){
      analogWrite(pin,i);
      delay(temp);
      }
}

void diminuisci(int pin) {
 for (int i = 255; i >= 0; i-=v){
      analogWrite(pin,i);
      delay(temp);
      }
}









