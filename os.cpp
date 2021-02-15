#include "os.h"

// Constructors
os::os() = default;

os::os(int version, int year, const string &developer, const string &type, const string &platform, bool multi_task,
       int bitness) {
    this->set_version(version);
    this->set_developer_name(developer);
    this->set_year_of_issue(year);
    this->type_os = type;
    this->platform_os = platform;
    this->multi_task_os = multi_task;
    this->bitness_os = bitness;
}

// Getters
string os::get_type_os() {
    return this->type_os;
}

string os::get_platform_os() {
    return this->platform_os;
}

bool os::get_multi_task_os() const {
    return this->multi_task_os;
}

int os::get_bitness_os() const {
    return this->bitness_os;
}
