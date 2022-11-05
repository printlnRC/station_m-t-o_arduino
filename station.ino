#include <LiquidCrystal.h>;
#include <SimpleDHT.h >;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int pinDHT22 = 10;
SimpleDHT22 dht22;
int mesure;
void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  pinMode(6, OUTPUT); // LED ROUGE
  pinMode(7, OUTPUT); // LED JAUNE
  pinMode(8, OUTPUT); // LED VERTE
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
 
}
void loop() {
  mesure = analogRead(A0);
  byte temperature = 0;
  byte humidity = 0;
 lcd.setCursor(0, 0);
 int err = SimpleDHTErrSuccess;
  if ((err = dht22.read(pinDHT22, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) 
  {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }

  lcd.print((int)temperature);
  lcd.print(" DEGRE C");
  lcd.setCursor(0,1);
  lcd.print((int)humidity);
  lcd.print("% HUMIDITE");
  delay(3000);
  lcd.clear();
  

  lcd.setCursor(7,1);
  lcd.print(mesure);
  lcd.setCursor(2,0);
  lcd.print("qualite  air");
  delay(3000);
  lcd.clear();

  if (mesure <80 ) {
digitalWrite(8, HIGH);
digitalWrite(7, LOW);
digitalWrite(6, LOW);
}
else
{
if (mesure < 140 ) {
digitalWrite(8, LOW);
digitalWrite(7, HIGH);
digitalWrite(6, LOW);
}
else
{

digitalWrite(8, LOW);
digitalWrite(7, LOW);
digitalWrite(6, HIGH);
}
}

}
