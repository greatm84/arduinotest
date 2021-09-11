#include "WaterSensor.h"
#include "pitches.h"

// https://deneb21.tistory.com/223

int analogPin = 0;
int led = 11;
int buzz = 12;
int val = 0;

void WaterSensor::setup()
{
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void WaterSensor::loop()
{
    val = analogRead(analogPin);

    if (val > 100)
    {
        digitalWrite(led, HIGH);
        tone(buzz, NOTE_A5, 20);
    }
    else
    {
        digitalWrite(led, LOW);
    }

    Serial.println(val);
    delay(500);
}