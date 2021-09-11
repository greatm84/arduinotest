#include "TestBase.h"
#include "WaterSensor.h"

TestBase *test;

void setup()
{
  // PadMelody padMelody;
  WaterSensor waterSensor;

  test = &waterSensor;
  test->setup();
}

void loop()
{
  test->loop();
}