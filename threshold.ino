int pinMicro = A0;
int volatile valueMicro = 0; // value given by the sensor
void setup() {
  // put your setup code here, to run once:
  pinMode(pinMicro,INPUT);
  Serial.begin(9600);
}

void loop() {

valueMicro = analogRead(pinMicro);  // reading and recording the measured sound level
Serial.println(valueMicro);
delay(100);
}
