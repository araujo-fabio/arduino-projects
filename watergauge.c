//Water gauge via Arduino
//Made by Fabio H. Araujo
//araujofabio@airmail.cc
//more projects at: https://github.com/araujo-fabio/arduino-projects

#define trig 11 //trigger
#define echo 12 //receiver
#define BB1 7 //botao
#define BZ1 2 //buzzer

//config do US
void trigPuls ();
float pulse;
float dist_cm;

int distmax; //variavel da distancia maxima
int VV1; //porcentagem
int EB1 = 0; //variavel do botao  

void setup () {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(BB1, INPUT);
  
  digitalWrite(trig, LOW);
  
  Serial.begin(9600);
}

void loop() {
  
  trigPuls();
  pulse = pulseIn(echo, HIGH);
  dist_cm = pulse/58.82;
  
  delay(500);
  
  EB1 = digitalRead(BB1);
  if(EB1 == HIGH) {
    VV1 = dist_cm;
    long distmax = VV1;
    Serial.print("Distancia maxima calculada (em porcentagem):");
    Serial.println(VV1);
    delay(1000);
  }

  int vmap = map(dist_cm, 0, VV1, 0, 100); 
  Serial.print("vmap:");
  Serial.println(vmap);
  
  if(vmap <= 20) {
    //acionar buzzer
    Serial.println("Buzzer acionado");
    tone(BZ1, 1000);       
    delay(100);       
  } else {
    noTone(BZ1);
  }
  delay(500);
}

void trigPuls()
{
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
}
