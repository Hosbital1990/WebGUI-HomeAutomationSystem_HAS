
#include<thread>
#include <random>
#include <chrono>
#include "memory_interface.h"
#include "temp_sensor.h"

Temp_Sensor::Temp_Sensor(){}
Temp_Sensor::Temp_Sensor(std::string_view name, int order_number, int priority, bool power_state, short int operation_state)
:name(name), order_number(order_number), priority(priority), power_state(power_state),operation_state(operation_state)
{
    //call temp data reading thread as soon as temp object ct=reated
    std::cout << "Done Temp sensor!" << std::endl;

    temp_data_reading_thread= std::jthread(&Temp_Sensor::start_data_reading,this);
}

Temp_Sensor::~Temp_Sensor()
{
    std::cout << "Distruted Temp!" << std::endl;
}


std::vector<double> Temp_Sensor::providing_data() {

    std::unique_lock<std::mutex> lock(temp_mtx);

    cv.wait(lock, [this]{return (data_is_ready && raw_temp_data.size()) ;});  // wait for data reading to provide new data

  // std::vector<int> data_copy = raw_temp_data;
    data_is_ready=false;
    //lock.unlock();  // Explicitly unlock early if needed
    //std::this_thread::sleep_for(std::chrono::seconds(2));
    return raw_temp_data;
}

void Temp_Sensor::start_data_reading(){

 std::cout << "Hello from Start data reading!" << std::endl;

    while (true) {
        std::unique_lock<std::mutex> lock(temp_mtx);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(27, 38);
        raw_temp_data.push_back(dis(gen));
        //std::cout << raw_temp_data.back() << "  " <<std::endl;
        data_is_ready=true;
        if( raw_temp_data.size() == db_bunch_size){

          MemoryInterface::write_data(raw_temp_data, "temp_storage.csv");
          MemoryInterface::Insert_DataBase(this, raw_temp_data);   // potencial to std::asynch execution
          raw_temp_data.clear();
        }


      //  std::cout << "Value of Temp: " << raw_temp_data.back() << std::endl;
        lock.unlock();  // Explicitly unlock early if needed
        cv.notify_one(); // Notify the waiting thread

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

std::string Temp_Sensor::get_DataBase_name(){

  return DataBase_name ;

}
