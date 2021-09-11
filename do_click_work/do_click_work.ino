#include "TestBase.h"
#include "PadMelody.h"

TestBase* test;

void setup(){
  PadMelody padMelody;

  test = &padMelody;
  test->setup();
}

void loop(){
  test->loop();
}