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
    // Call the initialization function and check its return value
    // if (!system_initial())
    // {
    //     // Throw an exception if the initialization failed
    //     throw std::runtime_error("Initialization failed in CentralManager");
    // }

    std::cout << "Parametred Constructor of central manager is called! " << std::endl;

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

    // Create and start Object of Temp sensor -> Temp sensor data reading start
    Sensor* sensor = new Temp_Sensor("Temperature", 1, 10, true, 3);
    std::cout << "Temp sensor starts working ... " << std::endl;

    // Call actuator adjuster
    Actuator* actuator = new Heater_Controller("Heater", 2, 100, true, 2, sensor);
    std::cout << "Temp sensor starts working ... " << std::endl;

    // Handle Camera Read frame, show on display and also save-> jthread handle this task
    // std::jthread camera_thread (Camera::camera_start, 0);

    // Asynchronous parallelism handle this task
    // std::future<bool> camera_future;
    // camera_future = std::async(std::launch::async, Camera::camera_setup );
    // camera_future.get();  // Main thread stays here to get a bool result from camera

    if (!Camera::camera_setup())
    {
        std::cout << " There is a problem with Camera driving!" << std::endl;
    }
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