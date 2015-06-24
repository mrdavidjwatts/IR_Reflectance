int led = 3;           // the pin that the LED is attached to
int brightness = 0;    // how bright the LED is
int lastSensor = 0;
int sensorStart = 0;
int lastBrightness = 0;
const long interval = 10;  
unsigned long previousMillis = 0;   
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  for(int i = 0; i < 10; i++){
    sensorStart = sensorStart + analogRead(A0);
    delay(10);
  }
  sensorStart = sensorStart / 10;
  sensorStart = sensorStart + 30;

}

void loop() {
  Serial.println(lastBrightness);
  unsigned long currentMillis = millis();
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  if(sensorValue > (sensorStart + 20)){
  brightness = map(sensorValue, sensorStart, 360, 0, 255);
  analogWrite(led, brightness);
  lastBrightness = brightness;
  }
  else{
    if(lastBrightness > 0){
      if(currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED 
       previousMillis = currentMillis;   
       lastBrightness--;
       analogWrite(led, lastBrightness);
  }
      
     
    }
    else{      
    analogWrite(led, 0);
    }
  } 
}
