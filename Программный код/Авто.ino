void setup()
{
  pinMode(3, OUTPUT);pinMode(4, OUTPUT);pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);pinMode(7, OUTPUT);pinMode(8, OUTPUT); pinMode(13, OUTPUT);
  
}
void go(int L,int R){
  if(L>0){digitalWrite(4, 1); digitalWrite(5, 0);}
  else {digitalWrite(4, 0); digitalWrite(5, 1);}
  if(R>0){digitalWrite(7, 1); digitalWrite(8, 0);}
  else {digitalWrite(7, 0); digitalWrite(8, 1);}
  analogWrite(3, abs(L)); 
  analogWrite(6, abs(R));
}



void loop()
{
  
 
   go(255, 255);
   delay(750);
   go(0, 0);
   delay(20000);
   go(-255, -255);
   delay(750);
   go(0, 0);
   delay(20000);
  
}
