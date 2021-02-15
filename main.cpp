#include <iostream>
#include "driver.h"
#include "os.h"

using namespace std;

// Questions for string types
void question(const string& quest, string &answer) {
    cout << quest << " |string|: ";
    cin >> answer;
}

// Questions for integer types
void question(const string& quest, int &answer) {
    cout << quest << " |int|: ";
    cin >> answer;
}

// Questions for bool types
void question(const string& quest, bool &answer) {
    cout << quest << " |bool|: ";
    cin >> answer;
}

void output_data(const string& item, const string& value) {
    cout << item << " | " << value << endl;
}

void output_data(const string& item, const int& value) {
    cout << item << " | " << value << endl;
}

void output_data(const string& item, const bool& value) {
    if (value) {
        cout << item << " | " << "��" << endl;
    } else {
        cout << item << " | " << "���" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "");

    int version, year;
    string developer;

    question("������ ��", version);
    question("��� ������� ��", year);
    question("��� ������������ ��", developer);
    cout << "-----------------" << endl;
    string filter;
    question("�������� ������� ��� ������������ ������� (driver, os)", filter);
    cout << "-----------------" << endl;
    int N;
    question("���-�� �� (������ �������)", N);
    cout << "-----------------" << endl;

    auto ** drivers = new driver*[N];
    auto ** oss = new os*[N];

    if (filter == "driver") {
        int id;
        string type, os_d;

        for (int i = 0; i < N; ++i) {
            question("��� ����������", type);
            question("������������ �������", os_d);
            question("�������������� ����������", id);
            cout << "-----------------" << endl;
            drivers[i] = new driver(version, year, developer, type, os_d, id);
        }
    }



    if (filter == "os") {
        int bitness;
        string type_os, platform;
        bool multi_task;

        for (int i = 0; i < N; ++i) {
            question("��� ��", type_os);
            question("���������", platform);
            question("���� �� ����� ����������?", multi_task);
            question("�����������", bitness);
            cout << "-----------------" << endl;
            oss[i] = new os(version, year, developer, type_os, platform, multi_task, bitness);
        }
    }

    if (filter != "os" && filter != "driver") {
        cout << "�� ������ �� �������, �����!";
        return 0;
    }

    cout << endl;

    // Output

    for (int i = 0; i < N; ++i) {
        cout << "(" << i << ") >-----------" << endl;
        if (filter == "driver") {
            output_data("������ ��", drivers[i]->get_version());
            output_data("��� ������� ��", drivers[i]->get_year_of_issue());
            output_data("��� ������������ ��", drivers[i]->get_developer_name());
            output_data("��� ����������", drivers[i]->get_type_driver());
            output_data("������������ �������", drivers[i]->get_os_driver());
            output_data("�������������� ����������", drivers[i]->get_id_device_driver());
        }
        if (filter == "os") {
            output_data("������ ��", oss[i]->get_version());
            output_data("��� ������� ��", oss[i]->get_year_of_issue());
            output_data("��� ������������ ��", oss[i]->get_developer_name());
            output_data("��� ��", oss[i]->get_type_os());
            output_data("���������", oss[i]->get_platform_os());
            output_data("���� �� ����� ����������?", oss[i]->get_multi_task_os());
            output_data("�����������", oss[i]->get_bitness_os());
        }
        cout << "(" << i << ") -----------<" << endl;
    }


    system("pause");

    delete [] oss;
    delete [] drivers;

    return 0;
}
