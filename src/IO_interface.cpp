#include "IO_interface.h"
#include "temp_sensor.h"
#include "heater_controller.h"

namespace IOInterface {



    bool checkSensorAvailability(std::vector<Sensor*>& sensors){

        sensors.push_back(new Temp_Sensor("LivingRoomTemp", 1, 10, true, 3));
        sensors.push_back(new Temp_Sensor("BedRoomTemp", 2, 10, true, 3));

        return true;
    }

    bool checkActuatorAvailability(std::vector<Actuator*>& actuators){

        actuators.push_back(new Heater_Controller("LivingRoomHeaterController", 1, 100, true, 2));
        actuators.push_back(new Heater_Controller("BedRoomHeaterController", 2, 100, true, 2));


        return true;
    }

}
