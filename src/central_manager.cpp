

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

CentralManager::CentralManager(){

    std::cout << "Defulat Constructor of central manager is called! " << std::endl; 
}

CentralManager::CentralManager(std::string_view username, std::string_view password, int user_ID_number){

    // Call the initialization function and check its return value
    if (!initial_analysis()) {
        // Throw an exception if the initialization failed
        throw std::runtime_error("Initialization failed in CentralManager");
    }

    std::cout << "CentralManager successfully initialized." << std::endl;

}

CentralManager::~CentralManager()
{
}

void CentralManager::start_point(){

std::cout << " Program started ..." << std::endl;

// create and start Object of Temp sensor -> Temp sensor data reading start
Sensor* sensor = new Temp_Sensor("Temperature", 1 , 10, true, 3);
std::cout << "Temp sensor starts working ... " << std::endl;

// call actuator adjuster
Actuator* actuator = new Heater_Controller("Heater", 2, 100, true, 2, sensor);
std::cout << "Temp sensor starts working ... " << std::endl;

// Handle Camera Read frame, show on display and aslo save-> jthread handle this task
//std::jthread camera_thread (Camera::camera_start, 0);

//Asynch parallelism handle this task
//std::future<bool> camera_future;
// camera_future = std::async(std::launch::async, Camera::camera_setup );
// camera_future.get();  //Main thread stays here to get a boo result from camera

if (!Camera::camera_setup()){

    std::cout <<" There is a problem with Camera driving!" <<std::endl;
}



}

bool CentralManager::initial_analysis()
{
    //Analysis like check and set all input and also primary adjustment
    std::cout << "Primary analysis and settlment Done!" << std::endl;
    return true;
}

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

std::string CentralManager::getCurrentDate() {
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