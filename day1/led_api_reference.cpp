#include <iostream>
using namespace std;

class Led
{
    bool status;  

public:
    Led(bool s = true) : status(s) {}

    bool getStatus() const
    {
        return status;
    }

    void turnOn()
    {
        cout << "LED is ON" << endl;
    }

    void turnOff()
    {
        cout << "LED is OFF" << endl;
    }
};

void controlLed(const Led &l);

int main()
{
    Led l1(true); 
    controlLed(l1);

    return 0;
}

void controlLed(const Led &l)
{
    if (l.getStatus())
        l.turnOn();
    else
        l.turnOff();
}

