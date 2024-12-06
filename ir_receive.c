#define power       0xE0E040BF    //for receiver

#include <IRremote.h>             // http://arcfn.com 

//raw data for IR Tx;
unsigned int powerIRout[] = {
  4550,4400,600,1650,550,1650,600,1650,550,550,600,500,
  600,550,550,550,600,500,600,1650,600,1600,600,1650,550,550,600,500,600,550,
  600,500,600,500,650,450,650,1600,600,500,650,450,650,500,600,500,600,500,600,
  550,600,1600,600,500,650,1600,650,1550,650,1600,650,1550,650,1600,650,1600,600};

IRrecv irrecv(11);
decode_results results;
IRsend irsend;

void setup () {
  Serial.begin (9600);
  irrecv.enableIRIn();      // Start the IR receiver
  pinMode (3, OUTPUT);      //IR LED
}

void loop (){
  if (irrecv.decode(&results))   //read IR    
  {    
      sendIR ();
  }
  irrecv.resume();           // Resume decoding (necessary!) 
  delay (200);               
}   

void sendIR ()   //function to output "POWER" code to IR diodes. 
{  
  Serial.println ("send IR out");

  irsend.sendRaw(powerIRout,68,38); 

  Serial.println ("sent");
}