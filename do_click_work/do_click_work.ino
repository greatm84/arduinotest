#include "TestBase.h"
#include "GT.h"

TestBase *test;

void setup()
{
  // PadMelody padMelody;
  GT gt;

  test = &gt;
  test->setup();
}

void loop()
{
  test->loop();
}