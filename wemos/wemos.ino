#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include <LiquidCrystal_I2C.h>

#define FIREBASE_HOST "https://gasgasgas-c19c6-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "b2tSkJxipbFQA4j5aX5Jdnt6iJoqSCMymYUhhHgq"
#define WIFI_SSID "A"
#define WIFI_PASSWORD "12345678"

LiquidCrystal_I2C lcd(0x27, 16, 2);
FirebaseData firebaseData;

int P1= D4;
int P2= D5;
int P3= D6;
int P4= D7;

void send2FBP1(){
  if(digitalRead(P1)==LOW){
    Firebase.setString(firebaseData,"/Hasil_Pembacaan/P1", "Dipakai");
  }
  else{
    Firebase.setString(firebaseData,"/Hasil_Pembacaan/P1", "Kosong");
  }
}

void send2FBP2(){
  if(digitalRead(P2)==LOW){
    Firebase.setString(firebaseData,"/Hasil_Pembacaan/P2", "Dipakai");
  }
  else{
    Firebase.setString(firebaseData,"/Hasil_Pembacaan/P2", "Kosong");
  }
}

void send2FBP3(){
  if(digitalRead(P3)==LOW){
    Firebase.setString(firebaseData,"/Hasil_Pembacaan/P3", "Dipakai");
  }
  else{
    Firebase.setString(firebaseData,"/Hasil_Pembacaan/P3", "Kosong");
  }
}

void send2FBP4(){
  if(digitalRead(P4)==LOW){
    Firebase.setString(firebaseData,"/Hasil_Pembacaan/P4", "Dipakai");
  }
  else{
    Firebase.setString(firebaseData,"/Hasil_Pembacaan/P4", "Kosong");
  }
}

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  pinMode(P1, INPUT);
  pinMode(P2, INPUT);
  pinMode(P3, INPUT);
  pinMode(P4, INPUT);
}

void loop(){ 
  lcd.setCursor(0, 0);
  lcd.print("  Slot  Parkir  ");
  lcd.setCursor(0, 1);
  if(digitalRead(P1)==LOW&&digitalRead(P2)==LOW&&digitalRead(P3)==LOW&&digitalRead(P4)==LOW){
    Serial.print("FULL");
    Serial.println("");
    lcd.print("FULL");
    Firebase.setString(firebaseData,"/Hasil_Pembacaan/status", "FULL");
  }
  else if(digitalRead(P1)==LOW&&digitalRead(P2)==HIGH&&digitalRead(P3)==HIGH&&digitalRead(P4)==HIGH){
    Serial.print("P2, P3, P4 Kosong");
    Serial.println("");
    lcd.print("P2,P3,P4 Kosong");
    Firebase.setString(firebaseData,"/Hasil_Pembacaan/status", "_");
  }
  else if(digitalRead(P1)==HIGH&&digitalRead(P2)==LOW&&digitalRead(P3)==HIGH&&digitalRead(P4)==HIGH){
    Serial.print("P1, P3, P4 Kosong");
    Serial.println("");
    lcd.print("P1,P3,P4 Kosong");
    Firebase.setString(firebaseData,"/Hasil_Pembacaan/status", "_");
  }
  else if(digitalRead(P1)==HIGH&&digitalRead(P2)==HIGH&&digitalRead(P3)==LOW&&digitalRead(P4)==HIGH){
    Serial.print("P1, P2, P4 Kosong");
    Serial.println("");
    lcd.print("P1,P2,P4 Kosong");
    Firebase.setString(firebaseData,"/Hasil_Pembacaan/status", "_");
  }
  else if(digitalRead(P1)==HIGH&&digitalRead(P2)==HIGH&&digitalRead(P3)==HIGH&&digitalRead(P4)==LOW){
    Serial.print("P1, P2, P3 Kosong");
    Serial.println("");
    lcd.print("P1,P2,P3 Kosong");
    Firebase.setString(firebaseData,"/Hasil_Pembacaan/status", "_");
  }
  else if(digitalRead(P1)==HIGH&&digitalRead(P2)==HIGH&&digitalRead(P3)==HIGH&&digitalRead(P4)==HIGH){
    Serial.print("P1, P2, P3, P4 Kosong");
    Serial.println("");
    lcd.print("Semua Kosong");
    Firebase.setString(firebaseData,"/Hasil_Pembacaan/status", "EMPTY");
  }
  else if(digitalRead(P1)==LOW&&digitalRead(P2)==LOW&&digitalRead(P3)==HIGH&&digitalRead(P4)==HIGH){
    Serial.print("P3, P4 Kosong");
    Serial.println("");
    lcd.print("P3, P4 Kosong");
    Firebase.setString(firebaseData,"/Hasil_Pembacaan/status", "_");
  }
  else if(digitalRead(P1)==LOW&&digitalRead(P2)==HIGH&&digitalRead(P3)==LOW&&digitalRead(P4)==HIGH){
    Serial.print("P2, P4 Kosong");
    Serial.println("");
    lcd.print("P2, P4 Kosong");
    Firebase.setString(firebaseData,"/Hasil_Pembacaan/status", "_");
  }
  else if(digitalRead(P1)==LOW&&digitalRead(P2)==HIGH&&digitalRead(P3)==HIGH&&digitalRead(P4)==LOW){
    Serial.print("P2, P3 Kosong");
    Serial.println("");
    lcd.print("P2, P3 Kosong");
    Firebase.setString(firebaseData,"/Hasil_Pembacaan/status", "_");
  }
  else if(digitalRead(P1)==HIGH&&digitalRead(P2)==LOW&&digitalRead(P3)==LOW&&digitalRead(P4)==HIGH){
    Serial.print("P1, P4 Kosong");
    Serial.println("");
    lcd.print("P1, P4 Kosong");
    Firebase.setString(firebaseData,"/Hasil_Pembacaan/status", "_");
  }
  else if(digitalRead(P1)==HIGH&&digitalRead(P2)==LOW&&digitalRead(P3)==HIGH&&digitalRead(P4)==LOW){
    Serial.print("P1, P3 Kosong");
    Serial.println("");
    lcd.print("P1, P3 Kosong");
    Firebase.setString(firebaseData,"/Hasil_Pembacaan/status", "_");
  }
  else if(digitalRead(P1)==HIGH&&digitalRead(P2)==HIGH&&digitalRead(P3)==LOW&&digitalRead(P4)==LOW){
    Serial.print("P1, P2 Kosong");
    Serial.println("");
    lcd.print("P1, P2 Kosong");
    Firebase.setString(firebaseData,"/Hasil_Pembacaan/status", "_");
  }
  else if(digitalRead(P1)==HIGH&&digitalRead(P2)==LOW&&digitalRead(P3)==LOW&&digitalRead(P4)==LOW){
    Serial.print("P1 Kosong");
    Serial.println("");
    lcd.print("P1 Kosong");
    Firebase.setString(firebaseData,"/Hasil_Pembacaan/status", "_");
  }
  else if(digitalRead(P1)==LOW&&digitalRead(P2)==HIGH&&digitalRead(P3)==LOW&&digitalRead(P4)==LOW){
    Serial.print("P2 Kosong");
    Serial.println("");
    lcd.print("P2 Kosong");
    Firebase.setString(firebaseData,"/Hasil_Pembacaan/status", "_");
  }
  else if(digitalRead(P1)==LOW&&digitalRead(P2)==LOW&&digitalRead(P3)==HIGH&&digitalRead(P4)==LOW){
    Serial.print("P3 Kosong");
    Serial.println("");
    lcd.print("P3 Kosong");
    Firebase.setString(firebaseData,"/Hasil_Pembacaan/status", "_");
  }
  else if(digitalRead(P1)==LOW&&digitalRead(P2)==LOW&&digitalRead(P3)==LOW&&digitalRead(P4)==HIGH){
    Serial.print("P4 Kosong");
    Serial.println("");
    lcd.print("P4 Kosong");
    Firebase.setString(firebaseData,"/Hasil_Pembacaan/status", "_");
  }
  send2FBP1();
  send2FBP2();
  send2FBP3();
  send2FBP4();
  lcd.clear();
  delay(300);  
}
