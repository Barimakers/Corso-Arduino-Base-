const long int info = 190568851; // 190568851 = 001 011 010 110 111 101 100 110 010 011
String    nome[] = {" R: ", " G: ", " B: "};
const int Pin [] = { 3   ,  6   ,  5   };
boolean   val [] = {true , false, false};

long int c;

int temp = 1, v = 1;

void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  for (int i = 0; i<3; i++){ pinMode(Pin[i], OUTPUT); }   
  c = info;
  aumenta(Pin[0]);    //001
}

void loop() {
  for (int i = 0; i<3; i++){
    Serial.print (nome[i]); Serial.print(c&1);
    if      ((c&1) == true  && val[i] == false) { aumenta   (Pin[i]); val[i] = true ; }
    else if ((c&1) == false && val[i] == true ) { diminuisci(Pin[i]); val[i] = false; }
    c = c >> 1;
  }
  Serial.println(' ');
  
  if (c == 0){c = info; Serial.println("___Fine ciclo___");}
}

void aumenta(int pin) {
  for (int i = 0; i <=255; i+=v){
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






