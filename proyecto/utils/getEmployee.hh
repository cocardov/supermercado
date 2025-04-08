#ifndef GET_EMPLOYEE_HH
#define GET_EMPLOYEE_HH

#include <string>
#include <string_view>

// Estructuras para almacenar datos
struct Employee
{
    std::string name;
    std::string id;
};

struct Customer
{
    std::string name;
    std::string id;
    double money;
};

// Funciones de entrada desde la consola
void getFromCmd(std::string_view msj, int* value);
void getFromCmd(std::string_view msj, std::string* value);
void getFromCmd(std::string_view msj, double* value);

// Funciones específicas del programa
void getEmployee(Employee* e);
void getCustomer(Customer* c);
void displayOptions();

// Variable de control global
extern bool exitMyProgram;

#endif
