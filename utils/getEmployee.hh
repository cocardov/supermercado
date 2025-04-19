#ifndef GET_EMPLOYEE_HH
#define GET_EMPLOYEE_HH

#include <string>
#include <string_view>
#include <vector>

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

struct Product
{
    std::string name;
    std::string amount;
    std::string price;
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
void loginEmployee(Employee* e);
void loginCustomer(Customer* c);
std::vector<std::string> commaSeparatedText(std::string buffer);
void printEmployeeOptions();
void printCustomerOptions();
void writeProducts(Product* p);
void printProducts(Product* p);


// Variable de control global
extern bool exitMyProgram;

#endif
