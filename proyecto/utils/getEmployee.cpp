#include <iostream>
#include <limits>
#include "getEmployee.hh"

 //función para limpiar el buffer.
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}



void getFromCmd(std::string_view msj, int* value)
{
    std::cout << '\n';
    std::cout << msj;
    std::cin >> (*value);
    ignoreLine();
}

void getFromCmd(std::string_view msj, std::string* value)
{
    std::cout << '\n';
    std::cout << msj;
    std::getline(std::cin >> std::ws, *value);
}

void getFromCmd(std::string_view msj, double* value)
{
    std::cout << '\n';
    std::cout << msj;
    std::cin >> (*value);
}

//le asigna un aumento default de $1000 al empleado, esto puede cambiar.
void arise(Employee* someEmployee, int arise = 1000)
{
    std::cout << someEmployee->name << " recibió un aumento de $" << arise << ".\n";
    someEmployee->money += arise;
}

void getEmployee(Employee* e)
{
    getFromCmd("ingrese su documento: ", &e->id) ;
    getFromCmd("ingrese su nombre: ", &e->name);
    getFromCmd("ingrese su edad: ", &e->age);
    getFromCmd("ingrese su presupuesto: $", &e->money);
    //se imprimen los distintos volores.
    std::cout << "la edad de e es: " << e->age << '\n';
    std::cout << "el documento de e es: " << e->id << '\n';
    std::cout << "el nombre completo de e es: " << e->name << '\n';
    std::cout << "el presupuesto de e es: $" << e->money << '\n';
}