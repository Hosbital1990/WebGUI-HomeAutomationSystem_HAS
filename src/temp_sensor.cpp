#include<thread>
#include <random>
#include <chrono>
#include "memory_interface.h"
#include "temp_sensor.h"

/**
 * @brief Default constructor for Temp_Sensor.
 */
Temp_Sensor::Temp_Sensor() {}

/**
 * @brief Parameterized constructor for Temp_Sensor.
 * 
 * @param name Name of the sensor.
 * @param order_number Order number of the sensor.
 * @param priority Priority of the sensor.
 * @param power_state Power state of the sensor.
 * @param operation_state Operation state of the sensor.
 */
Temp_Sensor::Temp_Sensor(std::string_view name, int order_number, int priority, bool power_state, short int operation_state)
    : name(name), order_number(order_number), priority(priority), power_state(power_state), operation_state(operation_state)
{
    // Call temp data reading thread as soon as temp object is created
    std::cout << "Done Temp sensor!" << std::endl;
    temp_data_reading_thread = std::jthread(&Temp_Sensor::startDataAcquisition, this);
}

/**
 * @brief Destructor for Temp_Sensor.
 */
Temp_Sensor::~Temp_Sensor()
{
    std::cout << "Distruted Temp!" << std::endl;
}

/**
 * @brief Provides temperature data.
 * 
 * @return std::vector<double> Vector containing temperature data.
 */
std::vector<double> Temp_Sensor::providing_data()
{
    std::unique_lock<std::mutex> lock(temp_mtx);
    cv.wait(lock, [this] { return (data_is_ready && raw_temp_data.size()); });  // Wait for data reading to provide new data
    data_is_ready = false;
    return raw_temp_data;
}

/**
 * @brief Starts the data reading process.
 */
void Temp_Sensor::startDataAcquisition()
{
    std::cout << "Hello from Start data reading!" << std::endl;

    while (true)
    {
        std::unique_lock<std::mutex> lock(temp_mtx);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(27, 38);
        raw_temp_data.push_back(dis(gen));
        data_is_ready = true;
        if (raw_temp_data.size() == db_bunch_size)
        {
            MemoryInterface::write_data(raw_temp_data, "temp_storage.csv");
            MemoryInterface::Insert_DataBase(this, raw_temp_data);  // Potential to std::async execution
            raw_temp_data.clear();
        }
        lock.unlock();  // Explicitly unlock early if needed
        cv.notify_one();  // Notify the waiting thread
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

/**
 * @brief Gets the database name.
 * 
 * @return std::string Database name.
 */
std::string Temp_Sensor::get_DataBase_name()
{
    return DataBase_name;
}
