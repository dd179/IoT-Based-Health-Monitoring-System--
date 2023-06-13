#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
wifi_name = " "
wifi_pswrd = " "
# At Line 96 change the your_api_key part with the API key from ThingSpeak
String network_name = wifi_name;
String network_pswrd= wifi_pswrd;
int rx_pin = 9;
int tx_pin = 10;
String ip ="184.106.153.149";
SoftwareSerial esp(rx_pin,tx_pin);

int lm35Pin = A1;
int pulsePin = A0;
int led = 7;

int time =200;
int read_value =0;
float temp_voltage = 0;
float temp =0;
int bpm = 0;


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);

lcd.clear();
lcd.setCursor(0,0);
lcd.print(" Patient Health");
lcd.setCursor(0,1);
lcd.print(" Monitoring ");
delay(4000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Initializing....");
delay(5000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Getting Data....");


pinMode(led,OUTPUT);
Serial.begin(9600);
Serial.println("Started");
esp.begin(115200);
esp.println("AT");
Serial.println("AT has been sent");

while(!esp.find("OK")){
  esp.println("AT");
  Serial.println("ESP8266 has not found");
}

Serial.println("OK has been recieved");
esp.println("AT+CWMODE=1");
while(!esp.find("OK")){
  esp.println("AT+CWMODE=1");
  Serial.println("Waiting for the connection....");
}
Serial.println("Has been setup as client");
Serial.println("Connecting to network...");
esp.println("AT+CWJAP=\""+network_name+"\",\""+network_pswrd+"\"");
while(!esp.find("OK"));
Serial.println("Connected to network.");
delay(1000);


}

void loop() {
  // put your main code here, to run repeatedly:
  esp.println("AT+CIPSTART=\"TCP\",\""+ip+"\",80");
  if(esp.find("Error")){
    Serial.println("AT+CIPSTART Error");
  }
  read_value = analogRead(lm35Pin);
  temp_voltage =(read_value/1023.0)*5000.0;
  temp = temp_voltage / 10.0;
  bpm = analogRead(pulsePin);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("BPM :");
  lcd.setCursor(7,0);
  lcd.print(bpm);
  lcd.setCursor(0,1);
  lcd.print("Temp.:");
  lcd.setCursor(7,1);
  lcd.print(temp);
  lcd.setCursor(13,1);
  lcd.print("C");
  digitalWrite(led,LOW);
  String data = "GET https://api.thingspeak.com/update?api_key=your_api_key";
  data += "&field1=";
  data += String(temp);
  data += "&field2=";
  data += String(bpm);
  data += "\r\n\r\n";
  esp.print("AT+CIPSEND=");
  esp.println(data.length()+2);
  delay(2000);
  if(esp.find(">")){
    esp.print(data);
    Serial.println(data);
    Serial.println("Data has been sent");
    digitalWrite(led,HIGH);
    delay(1000);
  }
  Serial.println("Connection Closed");
   
  
  esp.println("AT+CIPCLOSE");
  delay(1000);

 
  
}
