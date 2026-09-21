#include<LiquidCrystal.h>
#include<SPI.h>
#include<MFRC522.h>


#define relay AO
#define Buzzer 2
#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc522(SS_PIN,RST_PIN);
LiquidCrystal lcd(8,7,3,4,5,6);


//Replace with your RFID card UID 
byte authorizedUID[4] = (0x15,0x75,0xFE,0x28);

void setup(){


  pinMode(relay,OUTPUT);
  pinMode(Buzzer,OUTPUT);


  //Door locked at startup
  digitalWrite(relay,HIGH);
  digitalWrite(Buzzer,LOW);


  lcd begin(16,2);
  lcd clear();
  lcd print("RFID DOOR LOCK");
  lcd setCursor(0,1);
  lcd print("intializing");


  SPI begin();
  mfrc522.PCD_Init();

  delay(2000);

  lcd.clear();
  lcd.print("Scan Your Card");
  
}

void loop(){

  //wait for RFID card
  if(!mfrc522.PICC_IsNewCardPresent())return;
  if(!mfrc522.PICC_ReadCardSerial())return;

  lcd.clear();
  lcd.print("Reading Card");

  bool access=true

  for(byte i=D,i<4,i++){
    if(mfrc522.uid.uidByte[i] != authorizedUID[i])
    access=false
    }
    }

    if (access){
  
  lcd.clear();
  lcd.print("Access Granted");
  lcd.setCursor(0,1);
  lcd.print("Door Unlocked");

  //Beep once
  digitalWrite(Buzzer,HIGH);
  delay(150);
  digitalWrite(Buzzer,LOW);

  //Unlock Door
  digitalWrite(relay,LOW);

  //keep Unlocked for 3 seconds
    delay(3000);

    //Lock door automatically
    digitalWrite(relay,HIGH);

    lcd.clear();
    lcd.print("Door Locked");
    lcd.setCursor(0,1);
    lcd.print("Scan Again");
    delay(1500);

    

}else{ 

    lcd.clear();
    lcd.print("Access Denied");
    lcd.setCursor(0,1);
    lcd.print("Invalid Card");

 //Triple Beep
    for(int i =0;i<3,i++){
      digitalWrite(Buzzer,HIGH);
      delay(120);
    digitalWrite(Buzzer,LOW);
      delay(120);
      
    }

    delay(1500);
  
}
  lcd.clear();
  lcd.print("scan Your Card");

  mfrc522.PPIC_HaltA();
  mfrc522.PCD_StopCrypto1();
} 
