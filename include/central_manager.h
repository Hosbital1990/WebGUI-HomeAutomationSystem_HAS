//Include Guard
#ifndef CENTRAL_MANAGER_H
#define CENTRAL_MANAGER_H

// Manage all general duties


#include <iostream>


class CentralManager {

public:

    CentralManager();

    CentralManager(std::string_view username, std::string_view password, int user_ID_number);

    ~CentralManager();

int system_ID;
std::string system_name;

// program starts from here
void start_point();

bool initial_analysis();


std::string getCurrentTime(); 
std::string getCurrentDate();


protected:
struct Version{

    std::string system_version{"V01.0.0"};
    std::string release_date{"Aug 01, 2024"};
    int order_number {1000};

};

private:


};


#endif  // CENTRAL_MANAGER_H