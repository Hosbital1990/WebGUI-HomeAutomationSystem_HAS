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
: username(username), password(password), user_ID_number(user_ID_number)
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
 * @brief Destructor for CentralManager.
 */
CentralManager::~CentralManager()
{
}

/**
 * @brief Performs initial analysis and setup.
 * 
 * @return true If the initial analysis is successful.
 * @return false If the initial analysis fails.
 */
bool CentralManager::system_initial()
{
 
    // Initial all parts of system including sensors, actuator, camera and also memory and etc
    std ::vector<Sensor*> sensors;
    IOInterface::checkSensorAvailability(sensors);

    std::vector<Actuator*> actuators;
    IOInterface::checkActuatorAvailability(actuators);


    
 
    // Analysis like check and set all input and also primary adjustment
    std::cout << "Primary analysis and settlement Done!" << std::endl;
    return true;
}


/**
 * @brief Starts the central manager.
 */
void CentralManager::start_point()
{
    std::cout << " Program started ..." << std::endl;

    // Start the main loop
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