//Measuring temperature via Arduino
//Used for testing thermistors
//Made by Fabio Araujo
//araujofabio@airmail.cc
 
int x = 0;
int T1 = A0; //100k thermistor
int T2 = A1; //10k thermistor
int V1;
int V2;
float R1 = 10000;
float logR2, R2, TC1, TT1;
float R3 = 10000;
float logR4, R4, TC2, TT2;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
 
  void setup() {
    Serial.begin(9600);
  }
 
  void loop () {
    V1 = analogRead(T1);
    V2 = analogRead(T2);
     
        //T1
        R2 = R1 * (1023.0 / (float)V1 - 1.0);
        logR2 = log(R2);
        TT1 = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
        TC1 = TT1 - 273.15;    
        //T2
        R4 = R3 * (1023.0 / (float)V2 - 1.0);
        logR4 = log(R4);
        TT2 = (1.0 / (c1 + c2*logR4 + c3*logR4*logR4*logR4));
        TC2 = TT2 - 273.15;
       
        Serial.print("Temperature 1:");
        Serial.print(TC1);
        Serial.print("Temperature 2:");      
        Serial.println(TC2);
        delay(1000);                  
    }
