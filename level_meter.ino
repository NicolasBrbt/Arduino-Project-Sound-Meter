int pinMicro = A0;
int ledPin[]={2,3,4,5,6,7,8,9,10}; // array of led pin
int volatile valueMicro = 0; // value given by the sensor
int volatile realValue = 0; // real value after treatment with the threshold
int threshold = 548;     // measured detection threshold
int numberLed = 9;      
int i=0;
int j=0;
  
  void setup(){
  for(i=0;i<numberLed;i++){
    pinMode(ledPin[i],OUTPUT);      //Loop that assigns each pin of each led to a digital output
  }                             
   pinMode(pinMicro,INPUT);         // initialization of the microphone input
   Serial.begin(9600);
}
void loop() {

  valueMicro = analogRead(pinMicro);    // reading and recording the measured sound level
  realValue = abs(valueMicro - threshold);  //processing of the real sound value using the threshold
   
  if(realValue<5){
    for(j=0;j<numberLed;j++){
      digitalWrite(ledPin[j],LOW);
    }
  }
  
  else if((realValue<12)&&realValue>5){
    for(j=0;j<numberLed;j++){
      if(j>0){
        digitalWrite(ledPin[j],LOW);
      }
      else
        digitalWrite(ledPin[j],HIGH);
    }
  }

  else if((realValue>12)&&(realValue<24)){    // All these loops are conditions of lighting of LED according to the value of realValue.                                      
    for(j=0;j<numberLed;j++){                 // Thus we turn 9 times in a loop and we light the LED which interests us thanks to the index of the LED stored in the array
      if(j>1){
        digitalWrite(ledPin[j],LOW);
      }
      else
        digitalWrite(ledPin[j],HIGH);
    }
  }

  else if((realValue>24)&&(realValue<36)){
    for(j=0;j<numberLed;j++){
      if(j>2){
        digitalWrite(ledPin[j],LOW);
      }
      else
        digitalWrite(ledPin[j],HIGH);
    }
  }

  else if((realValue>36)&&(realValue<48)){
    for(j=0;j<numberLed;j++){
      if(j>3){
        digitalWrite(ledPin[j],LOW);
      }
      else
        digitalWrite(ledPin[j],HIGH);
    }
  }

 else if((realValue>48)&&(realValue<60)){
    for(j=0;j<numberLed;j++){
      if(j>4){
        digitalWrite(ledPin[j],LOW);
      }
      else
        digitalWrite(ledPin[j],HIGH);
    }
  }

  else if((realValue>60)&&(realValue<74)){
    for(j=0;j<numberLed;j++){
      if(j>5){
        digitalWrite(ledPin[j],LOW);
      }
      else
        digitalWrite(ledPin[j],HIGH);
    }
  }

  else if((realValue>74)&&(realValue<86)){
    for(j=0;j<numberLed;j++){
      if(j>6){
        digitalWrite(ledPin[j],LOW);
      }
      else
        digitalWrite(ledPin[j],HIGH);
    }
  }

  else if((realValue>86)&&(realValue<98)){
    for(j=0;j<numberLed;j++){
      if(j>7){
        digitalWrite(ledPin[j],LOW);
      }
      else
        digitalWrite(ledPin[j],HIGH);
    }
  }

   else if(realValue>100){
    for(j=0;j<numberLed;j++){
      if(j>8){
        digitalWrite(ledPin[j],LOW);
      }
      else
        digitalWrite(ledPin[j],HIGH);
    }
  }
 
  Serial.println(realValue,DEC);
  delay(35);                    // The dalay allows the LEDs to follow the music in real time.
                                //If the delay is too long the sound meter is not in rhythm and if the delay is too short you don't have time to see the LEDs light up.
}
