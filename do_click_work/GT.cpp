#include "GT.h"

int gled = 9;
int tled = 6;

void GT::setup()
{
    pinMode(gled, OUTPUT);
    pinMode(tled, OUTPUT);
}

void GT::loop()
{
    digitalWrite(gled, HIGH);
    digitalWrite(tled, HIGH);

    delay(500);

    digitalWrite(gled, LOW);
    digitalWrite(tled, LOW);

    delay(500);
}