#include <LiquidCrystal.h>
#include <Servo.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int ldr = A0;
int led = 4;
int nilai;

Servo jendela1;
Servo jendela2;

void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(9600);
  jendela1.attach(2);
  jendela2.attach(3);
  jendela1.write(0);
  jendela2.write(0);
  lcd.begin(16,2);
 
}

void loop() {

  Serial.print("Nilai LDR : ");

  lcd.clear();
  nilai = analogRead(ldr);
  Serial.println(nilai);
  lcd.setCursor(4,0);
  lcd.print("Kecerahan");
  lcd.setCursor(7,1);
  lcd.print(nilai);

  if (nilai < 100){
    digitalWrite(led, HIGH);
    jendela1.write(0);
    jendela2.write(0);
  }
  else {
    digitalWrite(led, LOW);
    jendela1.write(90);
    jendela2.write(90);
  }
  delay(1000);

}
