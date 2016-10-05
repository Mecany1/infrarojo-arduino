#include <IRremote.h>

int RECV_PIN = 2;
int led_pin = 3;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  
  pinMode(led_pin, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
    digitalWrite(led_pin, HIGH);
  } else {
    digitalWrite(led_pin, LOW);  
  }
  delay(100);
}
