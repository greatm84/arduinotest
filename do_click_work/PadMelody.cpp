#include "PadMelody.h"
#include "pitches.h"
#include <Keypad.h>

// notes in the melody:
int melody[] = {
    NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4,
    NOTE_GS4, NOTE_A5, NOTE_AS5, NOTE_B5, NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5};

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
    {'0', '1', '2', '3'},
    {'4', '5', '6', '7'},
    {'8', '9', 'A', 'B'},
    {'C', 'D', 'E', 'F'}};
byte rowPins[ROWS] = {5, 4, 3, 2};   //connect to the row pinouts of the keypad
byte colPins[COLS] = {11, 10, 7, 6}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void PadMelody::setup()
{
    Serial.begin(9600);
}

void PadMelody::loop()
{
    char customKey = customKeypad.getKey();

    if (customKey)
    {
        int piano = 0;
        switch (customKey)
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            piano = customKey - '0';
            break;
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
            piano = customKey - 'A';
            break;

        default:
            break;
        }
        tone(8, melody[piano], 50);
        Serial.println(customKey);
        delay(50);
    }
}