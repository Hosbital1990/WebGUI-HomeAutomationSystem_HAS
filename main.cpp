
// This program outputs the message "Hello Web GUI" to the console.
#include <iostream>
#include "sensor.h"
#include "actuator.h"

int main(int argc, char const *argv[])
{
    /* code */
    std::cout << "Hello Web GUI \n";
        std::cout << "2Rood Web GUI \n";

    DoSom doSomObj;
    doSomObj.doSM();

    Actuator actuatorObj;
    actuatorObj.turnOn();
    actuatorObj.turnOff(); 

    


    return 0;
}
