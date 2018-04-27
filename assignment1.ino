#include <IRremote.h>

int RECV_PIN = 7;
int relay_control1 = 12;
int relay_control2 = 11;

boolean state1 = false;
boolean state2 = false;
boolean state3 = false;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(relay_control1, OUTPUT);
  pinMode(relay_control2, OUTPUT);
  digitalWrite(relay_control1,LOW);
  digitalWrite(relay_control2,LOW);
}

void loop()
{
  if(irrecv.decode(&results)){
    if(results.value == 0xFD08F7){ // 1
      if(!state1) {
        Serial.println("Light Bulb 1 On");
        digitalWrite(relay_control1, HIGH); 
        state1 = true; 
      } else {
        Serial.println("Light Bulb 1 Off");
        digitalWrite(relay_control1, LOW);
        state1 = false;
      }
      irrecv.resume();
    }
    else if(results.value == 0xFD8877){ // 2
      if(!state2) {
        Serial.println("Light Bulb 1 On");
        digitalWrite(relay_control2, HIGH);  
        state2 = true;
      } else {
        Serial.println("Light Bulb 1 Off");
        digitalWrite(relay_control2, LOW);
        state2 = false;
      }
      irrecv.resume();
    }
    else if(results.value == 0xFD48B7){ // 3
      if(!state3) {
        Serial.println("Both Light Bulb 1 and Light Bulb 2 On");
        state1 = true;
        state2 = true;
        state3 = true;
        digitalWrite(relay_control1, HIGH);
        digitalWrite(relay_control2, HIGH);
      } else {
        Serial.println("Both Light Bulb 1 and Light Bulb 2 Off");
        state1 = false;
        state2 = false;
        state3 = false;
        digitalWrite(relay_control1, LOW);
        digitalWrite(relay_control2, LOW);
      }
      irrecv.resume();
    }
  }
}
