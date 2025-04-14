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
    int money;
};

// Funciones de entrada desde la consola
void getFromCmd(std::string_view msj, int* value);
void getFromCmd(std::string_view msj, std::string* value);
void getFromCmd(std::string_view msj, double* value);

// Funciones específicas del programa
void registerEmployee(Employee* e);
void registerCustomer(Customer* c);
void displayOptions();
void displayEmployeeMenu();
void displayCustomerMenu();

// Variable de control global
extern bool exitMyProgram;

#endif
