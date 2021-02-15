#include "software.h"

// Setters

void software::set_developer_name(string developerName) {
    this->developer_name = std::move(developerName);
}

void software::set_year_of_issue(int yearOfIssue) {
    this->year_of_issue = yearOfIssue;
}

void software::set_version(int i) {
    this->version = i;
}

// Getters

string software::get_developer_name() {
    return this->developer_name;
}

int software::get_year_of_issue() const {
    return this->year_of_issue;
}

int software::get_version() const {
    return this->version;
}
