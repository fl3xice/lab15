#ifndef LAB15_OS_H
#define LAB15_OS_H

#include "iostream"
#include "software.h"

using namespace std;

class os : public software {
    public:
    // Constructor
        os();
        os(int version, int year, const string& developer, const string& type, const string& platform, bool multi_task, int bitness);
    // Getters
        string get_type_os();
        string get_platform_os();
        bool get_multi_task_os() const;
        int get_bitness_os() const;
    private:
    // Strings
        string type_os;
        string platform_os;
    // Booleans
        bool multi_task_os{};
    // Integers
        int bitness_os{};
};


#endif //LAB15_OS_H
