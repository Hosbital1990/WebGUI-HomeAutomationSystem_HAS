#include "temp_sensor.h"
#include<thread>
#include <random>
#include <chrono>


#include "heater_controller.h"

Heater_Controller::Heater_Controller()
{
        std::cout << "Defualt constructor of Actuator is called"<<std::endl;

}

Heater_Controller::Heater_Controller(std::string_view name, int order_number, int priority, bool power_state, short int operation_state, Sensor* sensor)
:name(name), order_number(order_number), priority(priority), power_state(power_state), operation_state(operation_state)

{
         std::cout << "Secon constructor of Heater_controler is called"<<std::endl;
         heater_adjuster_thread = std::jthread(&Heater_Controller::actuator_adjuster,this,sensor);   
}

Heater_Controller::~Heater_Controller()
{
            std::cout << "Desructur of Heater controller called!"<<std::endl;

}

void Heater_Controller::actuator_adjuster(Sensor *sensor)
{   
    while(true){
         auto sensor_data = sensor->providing_data();
         std::cout << "Read value from Heater controller:     " << sensor_data.back() << std::endl;
             //std::this_thread::sleep_for(std::chrono::seconds(2));

    }
}
