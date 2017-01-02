int MoisturePin = 7; //moist sensor PIN
int analogMoisture = A1; 
int Moistureval = 0;
int error = 11;


void setup() {
  // put your setup code here, to run once:
 
  Serial.begin(9600);
  pinMode(4,OUTPUT); // light 
  pinMode(7,OUTPUT);// moisture
  pinMode(11,OUTPUT);//error
  

}

void loop() {
  Moistureval = analogRead(analogMoisture);   // read the input analog pin 1
  float Moisturevoltage = Moistureval *5.0; //The byte Value Recived is multiplued by 5 in other to create the convertion
  Moisturevoltage /= 1024; // makes an aritmetic value to convert to milivolts and

  // 1.Sub routine for the Moisturevoltage sensor to work on pin ,
  //2.it recieves the signal on the analogRead
  //3. The voltage converted raw value is from analog to digital
  //4.writed to the MoisturePin 12 on arduino to give a HIGH or LOW
  
  //Moisture Sensor Sub Routine
  if (Moisturevoltage >= 3 ) {
    
    digitalWrite(7, LOW); // HIGH moisture dont add water
    digitalWrite(4,HIGH);
    digitalWrite(11,HIGH);
  }
  else {
    
    digitalWrite(MoisturePin, HIGH);// turns light pin LOW, add water the light
     digitalWrite(4,LOW);  // high moisture, turn light
  }
      //Prints the Voltage Value in the Sensor: 
      Serial.println("Analog Read 1 in Volts:");
      Serial.println(Moisturevoltage);
      
      delay(1000);
}
