#include <chrono>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>
#include <thread>
#include <future>
#include "central_manager.h"
#include "sensor.h"
#include "temp_sensor.h"
#include "actuator.h"
#include "heater_controller.h"
#include "camera.h"
#include "IO_interface.h"

/**
 * @brief Default constructor for CentralManager.
 */
CentralManager::CentralManager()
: system_ID(0), system_name("DefaultSystem")
{
    std::cout << "Default Constructor of central manager is called! " << std::endl;
}

/**
 * @brief Parameterized constructor for CentralManager.
 * 
 * @param username Username of the central manager.
 * @param password Password of the central manager.
 * @param user_ID_number User ID number of the central manager.
 */
CentralManager::CentralManager(std::string_view username, std::string_view password, int user_ID_number)
: username(username), password(password), user_ID_number(user_ID_number), system_ID(0), system_name("DefaultSystem"), is_programe_started(false)
{
    std::cout << "Parametred, Constructor of central manager is called! " << std::endl;

    // Call the initialization function and check its return value
    // if (!system_initial())
    // {
    //     // Throw an exception if the initialization failed
    //     throw std::runtime_error("Initialization failed in CentralManager");
    // }
}   



/**
 * @brief Performs initial analysis and setup: 
 * Initial all parts of system including sensors, actuator, camera and also memory and etc
 * 
 * @return true If the initial analysis is successful.
 * @return false If the initial analysis fails.
 * 
 * @future work: This function should be expanded to include all the necessary setup for the system before run.
 * 
 */
bool CentralManager::system_initial()
{
 
    // Check and set all sensors
    IOInterface::checkSensorAvailability(sensors);

    //check and set all actuators
    IOInterface::checkActuatorAvailability(actuators);

    
     
    // Analysis like check and set all input and also primary adjustment
    std::cout << "Primary analysis and settlement Done!" << std::endl;
    return true;
}


/**
 * @brief Starts the central manager.
 */
void CentralManager::letsGetStartApp()
{
    std::cout << " Program started ..." << std::endl;

    /**
     * @brief toggle the program start flag
     */
    is_programe_started = true;

    sensorsThread = std::thread(&CentralManager::sensorsTaskHandler, this);
}

/**
 * 
 * @brief 
 * 
 */

void CentralManager::sensorsTaskHandler(){

    std::cout << "Sensor Task Handler is called!" << std::endl;

    while (is_programe_started)
    {
        {
            std::unique_lock<std::mutex> lock(CM_mtx);
            for (auto &sensor : sensors)
            {
            sensor->startDataAcquisition();   
            }
    
        }
        /**
         * @brief need to collect sensors raw data each 1 second
         * 
         */
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        
    }
    
}

void CentralManager::actuatorsTaskHandler(){

    std::cout << "Actuator Task Handler is called!" << std::endl;

    while (is_programe_started)
    {
        {
            std::unique_lock<std::mutex> lock(CM_mtx);
            for (auto &actuator : actuators)
            {
            actuator->actuator_adjuster();    
            }
    
        }
        /**
         * @brief need to control actuators based on sensor latest collected data each 1 second
         * 
         */
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        
    }
    
}

void CentralManager::stopApp()
{
    std::cout << " Program stopped ..." << std::endl;

    /**
     * @brief toggle the program start flag
     */
    is_programe_started = false;

    sensorsThread.join();

}

/**
 * @brief Gets the current time.
 * 
 * @return std::string Current time in HH:MM:SS format.
 */
std::string CentralManager::getCurrentTime()
{
    // Get current time from system clock
    auto now = std::chrono::system_clock::now();

    // Convert to time_t for localtime
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_time_t);

    // Format time as HH:MM:SS
    std::ostringstream oss;
    oss << std::put_time(&now_tm, "%H:%M:%S");
    return oss.str();
}

/**
 * @brief Gets the current date.
 * 
 * @return std::string Current date in YYYY-MM-DD format.
 */
std::string CentralManager::getCurrentDate()
{
    // Get current time from system clock
    auto now = std::chrono::system_clock::now();

    // Convert to time_t for localtime
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_time_t);

    // Format date as YYYY-MM-DD
    std::ostringstream oss;
    oss << std::put_time(&now_tm, "%Y-%m-%d");
    return oss.str();
}


/**
 * @brief Destructor for CentralManager.
 * 
 * @future work: This function should be expanded to include all the necessary cleanup for the system before exit.
 * 
 */
CentralManager::~CentralManager()
{

    // Stop the program
    stopApp();

    // Delete all sensors
    for (auto &sensor : sensors)
    {
        delete sensor;
    }

    // Delete all actuators
    for (auto &actuator : actuators)
    {
        delete actuator;
    }

    std::cout << "Destructor of central manager is called! " << std::endl;

}