#include <iostream>
#include <limits>
#include "getEmployee.hh"

bool exitMyProgram = false;

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


// imprime y toma datos del empleado
void getEmployee(Employee *e)
{
    getFromCmd("ingrese su nombre: ", &e->name);
    getFromCmd("ingrese su documento: ", &e->id);
    // se imprimen los distintos volores.
    std::cout << "el documento de " << e->name << " es: " << e->id << '\n';
    std::cout << e->name << " registrado con éxito como Empleado.\n";
    std::cout << '\n';
    
}

void getCustomer(Customer* c)
{
    getFromCmd("ingrese su nombre: ", &c->name);
    getFromCmd("ingrese su documento: ", &c->id);
    getFromCmd("ingrese su presupuesto: $", &c->money);
    // se imprimen los distintos volores.
    std::cout << "el documento de " << c->name << " es: " << c->id << '\n';
    std::cout << "el presupuesto de " << c->name << " es: $" << c->money << '\n';
    std::cout << c->name << " registrado con éxito como Cliente.\n";
    std::cout << '\n';

}

// imprime un switch de las opciones que puede realizar la persona.
void displayOptions()
{
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "APLICACIÓN PARA SUPERMERCADO SUPERSOL\n";
    std::cout << '\n';
    std::cout << "menú principal:\n";
    std::cout << '\n';
    std::cout << "ingrese el número de la acción que desea realizar.\n";
    std::cout << "1. Registrar como empleado.\n";
    std::cout << "2. Registrar como comprador.\n";
    std::cout << "3. Salir.\n";
    std::cout << '\n';

    while (true)
    {
        int opción{};
        std::cin >> opción;
        Employee e{};
        Customer c{};
        switch (opción)
        {
        case 1:
            getEmployee(&e);
            
            return;

        case 2:
            getCustomer(&c);
            return;

        case 3:
            std::cout << '\n';
            std::cout << '\n';
            std::cout << "esperamos haya disfrutado la experiencia\n";

            exitMyProgram = true;
            return;
            
        default:
            std::cout << "ingresá un caracter válido.\n";
            break;
        }

        //Employee e y Customer c go out of scoop here.
        
    } //while (true).

    // nunca se llega a ejecutar este pedazo de código.

} // void displayOptions();