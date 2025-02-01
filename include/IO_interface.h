#ifndef IO_INTERFACE_H
#define IO_INTERFACE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "sensor.h"
#include "actuator.h"

#define MAX_SENSOR 10
#define MAX_ACTUATOR 10

/**
 * @brief Namespace for handling In/Out interfaces like GPIO, I2C, SPI, UART, etc.
 * 
 * This namespace provides all related access to In/Out interfaces such as GPIO, I2C, SPI, UART, etc.
 * 
 * @date 2025-02-01
 * @version 1.0
 */
namespace IOInterface {

    /**
     * @brief Check out GPIO to determine which Sensors are connected.
     *  Accordingly, create and push an object of related sensor into the vector.
     * 
     * @param sensors A vector of pointers to Sensor objects.
     * @return bool True, if procedure done well.
     */
    bool checkSensorAvailability(std::vector<Sensor*>& sensors);

    /**
     * @brief Check out GPIO to determine which Actuators are connected.
     *  Accordingly, create and push an object of related actuator into the vector.
     * 
     * @param actuators A vector of pointers to Actuator objects.
     * @return bool True, if procedure done well.
     */ 
    bool checkActuatorAvailability(std::vector<Actuator*>& actuators);

}

#endif // IO_INTERFACE_H