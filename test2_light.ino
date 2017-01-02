
//Change this if you have a separate LED connected to another pin
const int error = 11; // the output for the humidity sensor
int lsPin = 4;
int relay2 = 7;//light sensor PIN
int val = 0;

void setup() {
   Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(4, OUTPUT); // light
  pinMode(7, OUTPUT); //relay
  pinMode(11, OUTPUT);// error
}

void loop() {

float val = analogRead(0);   // read the input analog pin 0
float voltage = val * 5.00;; // makes an arithmetic value to convert to millivolts and
// make the arduino input recognize the value
voltage /= 1024;

  if (voltage >= 1) {
    digitalWrite(4, 1);
    digitalWrite(7, 0);
    
  }
  else {
    digitalWrite(4, 0);
    digitalWrite(7, 1);// turns pin 7 HIGH, and this is the light
  }
  Serial.println(" Light sensor output in volt");
  Serial.print(" -------------------\n");
  Serial.print(voltage);
  Serial.print(" Analog Voltage\n");
 
  delay(1000);


} 
