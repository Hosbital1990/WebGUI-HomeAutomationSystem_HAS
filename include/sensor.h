#ifndef SENSOR_H
#define SENSOR_H

#include<iostream>
#include <string>
#include "vector"

class Sensor {
public:
Sensor();
Sensor(std::string_view name, int order_number, int priority, bool power_state, short int operation_state);
virtual ~Sensor();

std::string_view name;
int order_number;
int priority;
bool power_state;
short int operation_state;

virtual std::vector<double> providing_data();


protected:

virtual void startDataAcquisition();

virtual bool power_trigger();
virtual bool change_operation_state(int new_state);


private:

void sensor_manager(Sensor* sensor);


};

#endif // SENSOR_H
