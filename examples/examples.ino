#include "Pressure.h"

Pressure P1(A0);
void setup() {
  // put your setup code here, to run once:
  P1.Init();
  Serial.begin(115200);
}

void loop() {
  Serial.println(P1.Get(MPX5010,PSI));
}
