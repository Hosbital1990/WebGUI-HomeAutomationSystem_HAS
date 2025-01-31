
// This program outputs the message "Hello Web GUI" to the console.
#include <iostream>
#include "sensor.h"
#include "actuator.h"
#include "central_manager.h"
#include "temp_sensor.h"
#include "heater_controller.h"
#include "camera.h"

int main(int argc, char const *argv[])


    std::cout << "Hello Web GUI" << std::endl;

    try
    {
        /* code */

            /**
             * @brief By creating an object of CentralManager, It tries to setting up the whole system to start.
             * 
             * @param parameter-name description
             * 
             */
            CentralManager central_manager("admin", "admin", 1001);
            central_manager.system_initial();
            central_manager.start_point();  
            
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    


    return 0;
}
