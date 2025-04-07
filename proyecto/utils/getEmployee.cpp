#include <iostream>
#include <limits>
#include "getEmployee.hh"

// función para limpiar el buffer.
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void getFromCmd(std::string_view msj, int *value)
{
    std::cout << '\n';
    std::cout << msj;
    std::cin >> (*value);
    ignoreLine();
}

void getFromCmd(std::string_view msj, std::string *value)
{
    std::cout << '\n';
    std::cout << msj;
    std::getline(std::cin >> std::ws, *value);
}

void getFromCmd(std::string_view msj, double *value)
{
    std::cout << '\n';
    std::cout << msj;
    std::cin >> (*value);
}

// le asigna un aumento default de $1000 al empleado, esto puede cambiar.
void arise(Employee *someEmployee, int arise = 1000)
{
    std::cout << someEmployee->name << " recibió un aumento de $" << arise << ".\n";
    someEmployee->money += arise;
}

//imprime y toma datos del empleado
void getEmployee(Employee *e)
{
    getFromCmd("ingrese su documento: ", &e->id);
    getFromCmd("ingrese su nombre: ", &e->name);
    getFromCmd("ingrese su edad: ", &e->age);
    getFromCmd("ingrese su presupuesto: $", &e->money);
    // se imprimen los distintos volores.
    std::cout << "la edad de " << e->name << " es: " << e->age << '\n';
    std::cout << "el documento de " << e->name << " es: " << e->id << '\n';
    std::cout << "el nombre completo de " << e->name << " es: " << e->name << '\n';
    std::cout << "el presupuesto de " << e->name << " es: $" << e->money << '\n';
}

//imprime un switch de las opciones que puede realizar la persona.
void displayOptions()
{
    std::cout << "APLICACIÓN PARA SUPERMERCADO SUPERSOL\n";
    std::cout << '\n';
    std::cout << "menú principal:\n";
    std::cout << '\n';
    std::cout << "ingrese el número de la acción que desea realizar.\n";
    std::cout << "1. Registrar como empleado.\n";
    std::cout << "2. Salir.\n";
    std::cout << '\n';
    
    while (true)
    {
        int opción{};
        std::cin >> opción;
        Employee e{};
        switch (opción)
        {
            case 1:
            getEmployee(&e);
            return;
        case 2:
            std::cout << "gracias por salir.\n";
            return;
        default:
            std::cout << "ingresá un caracter válido.\n";
            break;
        }
    }

    //nunca se llega a ejecutar este pedazo de código.

}//void displayOptions();