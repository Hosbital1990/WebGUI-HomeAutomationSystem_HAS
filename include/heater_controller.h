#ifndef HEATER_CONTROLLER_H
#define HEATER_CONTROLLER_H

#include<iostream>
#include <string>
#include "vector"

#include "actuator.h"

class Heater_Controller : public Actuator{

public:

Heater_Controller();
Heater_Controller(std::string_view name, int order_number, int priority, bool power_state, short int operation_state, Sensor* sensor);
~Heater_Controller();

virtual void actuator_adjuster(Sensor* sensor) override;

private:

std::string_view name;
int order_number;
int priority;
bool power_state;
short int operation_state;

std::mutex heater_mtx;
std::jthread heater_adjuster_thread;

};

#endif // HEATER_CONTROLLER_H