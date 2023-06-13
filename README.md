# IoT-Based-Health-Monitoring-System--
We are getting the patient pulse and their body temperature with ESP8266 Wi-Fi module that connects to Wi-Fi and sends the data to IoT device server. The IoT server used here is Thingspeak. Finally, the data can be monitored from any part of the world by logging into the Thingspeak channel. Dont'forget to change wi-name and wifi-password with yours. And the API key which you will get from the ThingSpeak. 


![image](https://github.com/dd179/IoT-Based-Health-Monitoring-System--/assets/130001604/85d00d54-a051-411f-abd3-340ebbf414d1)
![image](https://github.com/doganalpppp/IoT-Based-Health-Monitoring-System--/assets/130001604/c5a2e911-fcb9-4b55-ae08-d9416ac8f0b6)

Connections 

Connections of LCD:
1. Connect Pin 1,5,16 of LCD to GND.
2. Connect Pin 2,15 of LCD to VCC.
3. Connect Pin 4,6 of LCD to Digital Pin12,11 of Arduino.
4. Connect Pin 11,12,13,14 of LCD to Digital Pin 5,4,3,2 of Arduino.
5. Connect Pin 3 of LCD to middle leg of potantiometer. This connection for make the contrast settings for LCD. 

Connections of ESP8266:
1. The RX pin of ESP8266 works on 3.3V or less and it will not communicate with the Arduino when we will connect it directly to the Arduino. So, we will have to make a voltage divider for it which will convert the 5V into 3V. This can be done by connecting the 2.2K & 1.5K resistor. Thus the RX pin of the ESP8266 is connected to pin 10 of Arduino through the resistors.
2. Connect the TX pin of the ESP8266 to pin 9 of the Arduino.

Other Connections:
1. Connect Pulse Sensor output pin to A0 of Arduino and other two pins to VCC & GND.
2. Connect LM35 Temperature Sensor output pin to A1 of Arduino and other two pins to VCC & GND.
3. Connect the LED to Digital Pin 7 of Arduino


If you have any question with connections of the arduino and the ESP module or the code. Feel free to ask via my email. 
doganalp179@gmail.com
