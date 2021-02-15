#ifndef LAB15_SOFTWARE_H
#define LAB15_SOFTWARE_H

#include <iostream>

using namespace std;

class software {
    public:
    // Setters
        void set_developer_name(string developerName);
        void set_year_of_issue(int yearOfIssue);
        void set_version(int i);
    // Getters
        string get_developer_name();
        int get_year_of_issue() const;
        int get_version() const;
    private:
    // String
        string developer_name;
    // Integers
        int year_of_issue;
        int version;
};


#endif //LAB15_SOFTWARE_H
