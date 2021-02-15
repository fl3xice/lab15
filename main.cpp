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
        cout << item << " | " << "Да" << endl;
    } else {
        cout << item << " | " << "Нет" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "");

    int version, year;
    string developer;

    question("Версия ПО", version);
    question("Год выпуска ПО", year);
    question("Имя Разработчика ПО", developer);
    cout << "-----------------" << endl;
    string filter;
    question("Выберете Драйвер или Операционная система (driver, os)", filter);
    cout << "-----------------" << endl;
    int N;
    question("Кол-во ПО (Размер массива)", N);
    cout << "-----------------" << endl;

    auto ** drivers = new driver*[N];
    auto ** oss = new os*[N];

    if (filter == "driver") {
        int id;
        string type, os_d;

        for (int i = 0; i < N; ++i) {
            question("Тип устройства", type);
            question("Операционная система", os_d);
            question("Индентификатор устройства", id);
            cout << "-----------------" << endl;
            drivers[i] = new driver(version, year, developer, type, os_d, id);
        }
    }



    if (filter == "os") {
        int bitness;
        string type_os, platform;
        bool multi_task;

        for (int i = 0; i < N; ++i) {
            question("Тип ОС", type_os);
            question("Платформа", platform);
            question("Есть ли много задачность?", multi_task);
            question("Разрядность", bitness);
            cout << "-----------------" << endl;
            oss[i] = new os(version, year, developer, type_os, platform, multi_task, bitness);
        }
    }

    if (filter != "os" && filter != "driver") {
        cout << "Вы ничего не выбрали, удачи!";
        return 0;
    }

    cout << endl;

    // Output

    for (int i = 0; i < N; ++i) {
        cout << "(" << i << ") >-----------" << endl;
        if (filter == "driver") {
            output_data("Версия ПО", drivers[i]->get_version());
            output_data("Год выпуска ПО", drivers[i]->get_year_of_issue());
            output_data("Имя Разработчика ПО", drivers[i]->get_developer_name());
            output_data("Тип устройства", drivers[i]->get_type_driver());
            output_data("Операционная система", drivers[i]->get_os_driver());
            output_data("Индентификатор устройства", drivers[i]->get_id_device_driver());
        }
        if (filter == "os") {
            output_data("Версия ПО", oss[i]->get_version());
            output_data("Год выпуска ПО", oss[i]->get_year_of_issue());
            output_data("Имя Разработчика ПО", oss[i]->get_developer_name());
            output_data("Тип ОС", oss[i]->get_type_os());
            output_data("Платформа", oss[i]->get_platform_os());
            output_data("Есть ли много задачность?", oss[i]->get_multi_task_os());
            output_data("Разрядность", oss[i]->get_bitness_os());
        }
        cout << "(" << i << ") -----------<" << endl;
    }


    system("pause");

    delete [] oss;
    delete [] drivers;

    return 0;
}
