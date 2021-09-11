#pragma once

class TestBase{
public :
    ~TestBase(){}
    virtual void setup();
    virtual void loop();
};