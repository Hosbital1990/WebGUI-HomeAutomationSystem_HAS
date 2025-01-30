
// This program outputs the message "Hello Web GUI" to the console.
#include <iostream>
#include "sensor.h"
#include "actuator.h"
#include "central_manager.h"
#include "temp_sensor.h"
#include "heater_controller.h"
#include "camera.h"

int main(int argc, char const *argv[])
{

    std::cout << "Hello Web GUI" << std::endl;

    try
    {
        /* code */
            CentralManager central_manager;
            central_manager.start_point();  
            
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    


    return 0;
}
