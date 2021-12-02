#include <BluetoothSerial.h>
BluetoothSerial BT;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  BT.begin("TestEsp32");//請改名
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(27, OUTPUT);
}
int m =0;
int n =0;
void loop() {
  // put your main code here, to run repeatedly:
  while (BT.available()) {
    //讀取藍芽資料
    String BTdata=BT.readString();
    //顯示在序列視窗
    Serial.println(BTdata);
    if(BTdata=="p1 gets one point!"){
      m+=1;
      }
     if(m ==1){
      digitalWrite(13,HIGH);
      }
      if(m ==2){
      digitalWrite(14,HIGH);
      m=0;
      }
      if(BTdata=="p2 gets one point!"){
      n+=1;
      }
     if(n ==1){
      digitalWrite(12,HIGH);
      }
      if(n ==2){
      digitalWrite(27,HIGH);
      n=0;
      }
      if(BTdata=="restart"){
        digitalWrite(13,LOW);
        digitalWrite(14,LOW);
        digitalWrite(12,LOW);
        digitalWrite(27,LOW);
        }
  }
    delay(1);
  }
 
