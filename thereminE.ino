int transistor=0;
int trnsstrMin=1023;
int trnsstrMax=0;
int thePitch=0;
int maxPitch=2093;

void toSerial(){
  Serial.print(trnsstrMin);
  Serial.print(' ');
  Serial.print(trnsstrMax);
  Serial.print(' ');
  Serial.println(transistor);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT); digitalWrite(13,1);
  while(millis()<5000){
    transistor=analogRead(8); toSerial();
    if(transistor>trnsstrMax)trnsstrMax=transistor;
    if(transistor<trnsstrMin)trnsstrMin=transistor;}
  digitalWrite(13,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  transistor=analogRead(8); toSerial();
  thePitch=map(transistor,trnsstrMax,trnsstrMin,31,maxPitch);
  if(thePitch<maxPitch)tone(8,thePitch,20);
}
