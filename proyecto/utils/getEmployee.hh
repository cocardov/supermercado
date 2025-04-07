#ifndef GETEMPLOYEE_HH
#define GETEMPLOYEE_HH
#include <string>

void ignoreLine();

struct Employee //struct del compound data type Employee.
{
    int id{};
    int age{};
    std::string name{};
    double money{};
};

void getFromCmd(std::string_view msj, int* value);

void getFromCmd(std::string_view msj, std::string* value);

void getFromCmd(std::string_view msj, double* value);

void arise(Employee* someEmployee, int arise);

void getEmployee(Employee* e);

void displayOptions();


#endif