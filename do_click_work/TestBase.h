#pragma once
#include "Arduino.h"

class TestBase{
public :
    ~TestBase(){}
    virtual void setup();
    virtual void loop();
};