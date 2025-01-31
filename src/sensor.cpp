#include <iostream>
#include "sensor.h"
#include <vector>

/**
 * @brief Triggers the power of the sensor.
 * 
 * @return true If the power is successfully triggered.
 * @return false If the power trigger fails.
 */
bool Sensor::power_trigger()
{
    return false;
}

/**
 * @brief Changes the operation state of the sensor.
 * 
 * @param new_state The new operation state.
 * @return true If the operation state is successfully changed.
 * @return false If the operation state change fails.
 */
bool Sensor::change_operation_state(int new_state)
{
    return false;
}

/**
 * @brief Default constructor for Sensor.
 */
Sensor::Sensor()
{
    std::cout << "Done!" << std::endl;
}

/**
 * @brief Parameterized constructor for Sensor.
 * 
 * @param name Name of the sensor.
 * @param order_number Order number of the sensor.
 * @param priority Priority of the sensor.
 * @param power_state Power state of the sensor.
 * @param operation_state Operation state of the sensor.
 */
Sensor::Sensor(std::string_view name, int order_number, int priority, bool power_state, short int operation_state)
    : name(name), order_number(order_number), priority(priority), power_state(power_state), operation_state(operation_state)
{
    std::cout << "Done!" << std::endl;
}

/**
 * @brief Destructor for Sensor.
 */
Sensor::~Sensor()
{
    std::cout << "Done!" << std::endl;
}

/**
 * @brief Starts the data reading process.
 */
void Sensor::start_data_reading()
{
    std::cout << this->name << " sensor start reading data :" << std::endl;
}

/**
 * @brief Provides sensor data.
 * 
 * @return std::vector<double> Vector containing sensor data.
 */
std::vector<double> Sensor::providing_data()
{
    return std::vector<double>();
}
