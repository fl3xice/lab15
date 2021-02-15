#include "driver.h"

// Constructors
driver::driver() = default;

driver::driver(int version, int year, const string &developer, const string &type, const string &os, int id_device) {
    this->set_version(version);
    this->set_developer_name(developer);
    this->set_year_of_issue(year);
    this->type_driver = type;
    this->os_driver = os;
    this->id_device_driver = id_device;
}

// Getters
string driver::get_type_driver() {
    return this->type_driver;
}

string driver::get_os_driver() {
    return this->os_driver;
}

int driver::get_id_device_driver() const {
    return this->id_device_driver;
}

