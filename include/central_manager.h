//Include Guard
#ifndef CENTRAL_MANAGER_H
#define CENTRAL_MANAGER_H

// Manage all general duties


#include <iostream>
#include <vector>


#include "sensor.h"
#include "actuator.h"


class CentralManager {

public:

    CentralManager();

    CentralManager(std::string_view username, std::string_view password, int user_ID_number);

    ~CentralManager();

int system_ID;
std::string system_name;

//Initial entire system
bool system_initial();

// program starts from here
void letsGetStartApp();



std::string getCurrentTime(); 
std::string getCurrentDate();


protected:
struct Version{

    std::string system_version{"V01.0.0"};
    std::string release_date{"Aug 01, 2024"};
    int order_number {1000};

};

private:

void sensorsTaskHandler();
void actuatorsTaskHandler();
void cameraTaskHandler();




std::string_view username;
std::string_view password;
int user_ID_number;

std::vector<Sensor*> sensors;
std::vector<Actuator*> actuators;
std::mutex CM_mtx;   // CM refers to Central Manager

bool is_programe_started;

};


#endif  // CENTRAL_MANAGER_H