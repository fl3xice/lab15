#ifndef LAB15_DRIVER_H
#define LAB15_DRIVER_H

#include "iostream"
#include "software.h"

using namespace std;

class driver : public software {
    public:
    // Getters
        string get_type_driver();
        string get_os_driver();
        int get_id_device_driver() const;
    // Constructor
        driver();
        driver(int version, int year, const string& developer, const string& type, const string& os, int id_device);
    private:
    // Strings
        string type_driver;
        string os_driver;
    // Integers
        int id_device_driver{};
};


#endif //LAB15_DRIVER_H
