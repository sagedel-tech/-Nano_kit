#define rain A1
#define buzzer 5
int value;
int set=10;
void setup() {
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(rain,INPUT);
  }	
void loop() {
  
 value = analogRead(rain);
 Serial.println("Rain Detector is ON");
 Serial.println(value);
 value = map(value,0,1023,225,0);
 Serial.println(value);
 if(value>=set){
  Serial.println("Rain has came");
  digitalWrite(buzzer,HIGH);
 }
 else{
  digitalWrite(buzzer,LOW);
 }
 delay(200);
}