#include "temp_sensor.h"
#include <thread>
#include <chrono>
#include <random>
#include <chrono>
#include "heater_controller.h"

/**
 * @brief Default constructor for Heater_Controller.
 */
Heater_Controller::Heater_Controller()
{
    std::cout << "Defualt constructor of Actuator is called" << std::endl;
}

/**
 * @brief Parameterized constructor for Heater_Controller.
 * 
 * @param name Name of the heater controller.
 * @param order_number Order number of the heater controller.
 * @param priority Priority of the heater controller.
 * @param power_state Power state of the heater controller.
 * @param operation_state Operation state of the heater controller.
 * @param sensor Pointer to the associated sensor.
 */
Heater_Controller::Heater_Controller(std::string_view name, int order_number, int priority, bool power_state, short int operation_state)
    : name(name), order_number(order_number), priority(priority), power_state(power_state), operation_state(operation_state)
{
    std::cout << "Second constructor of Heater_controller is called" << std::endl;
   
}

/**
 * @brief Destructor for Heater_Controller.
 */
Heater_Controller::~Heater_Controller()
{
    std::cout << "Destructor of Heater controller called!" << std::endl;
}

/**
 * @brief Adjusts the actuator based on sensor data.
 * 
 * @param sensor Pointer to the associated sensor.
 */
void Heater_Controller::actuator_adjuster(Sensor* sensor)
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}
