

int error = 11;
int fan = 6; // fan controller

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(4, OUTPUT);  // light on / off
  pinMode(6, OUTPUT); // fan on / off
  pinMode(11, OUTPUT); //error
}

void loop() {

  int TemperatureRead = analogRead(A3) - 43;
        // I neded to substrac 43 because of the real value read on the input
        // You may need to elemimnate that - 43
        
        
        // read the input analog pin 3
        // makes an aritmetic value to convert to milivolts and
        float voltage = (TemperatureRead * 5.00) / 1024;
        
        // make the arduino input recognized in the value of volts

  float Celsius = (voltage - 0.5) * 100;  // 500mV/1024=.48828125
      
        //1.Sub routine for the TEMPVOLT sensor to work on pin ,
        //2.it recieves the signal on the analogRead
        //3. The voltage converted raw value is from analog to digital
        //4.writed to the TEMp Pin on arduino to give a HIGH or LOW

//TEMP Sensor Sub Routine
  
//Convertion to Ferenheit:
  float  Ferenheit = (Celsius * 9) / 5 + 32;


  if (Ferenheit > 81 ) {
    digitalWrite(5, LOW); // low temp
    digitalWrite(4, HIGH); // Sends messege to PIN 4 To turn ONN
    digitalWrite(11, HIGH);
    digitalWrite(6, HIGH);
  }
  else if (Ferenheit <= 80) {

    digitalWrite(5, HIGH);// turns pin 6 off,
    digitalWrite(4, LOW); // turn fan on to elminate heat


  }


  Serial.println("Temperature Read");
  Serial.println(TemperatureRead);
  Serial.println("________________");
  delay(1000);
  Serial.println("Voltage");
  Serial.println(voltage);
  Serial.println("________________");
  delay(1000);
  Serial.println("Celsius");
  Serial.println(Celsius);
  Serial.println("________________");
  delay(1000);
  Serial.println("Farenheit");
  Serial.println(Ferenheit);
  Serial.println("________________");
  delay(1000);
  

}
