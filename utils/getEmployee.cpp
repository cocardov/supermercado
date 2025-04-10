#include <iostream>
#include <limits>
#include "getEmployee.hh"

bool exitMyProgram = false;

// función para limpiar el buffer.
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// overload de funciones para el input de datos
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

// imprime texto y toma datos del empleado
void getEmployee(Employee *e)
{
    getFromCmd("ingrese su nombre: ", &e->name);
    getFromCmd("ingrese su documento: ", &e->id);
    // se imprimen los distintos volores.
    std::cout << "el documento de " << e->name << " es: " << e->id << '\n';
    std::cout << e->name << " registrado con éxito como Empleado.\n";
    std::cout << '\n';
}

// imprime texto y toma los datos del cliente
void getCustomer(Customer *c)
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

// imprime un switch de las opciones que puede realizar la persona
void displayOptions()
{
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "\tBIENVENIDO AL SUPERMERCADO SUPERSOL\n";
    std::cout << '\n';
    std::cout << "ingrese el número de la acción que desea realizar.\n";
    std::cout << '\n';
    std::cout << "1. Registro o inicio de sesión como empleado.\n";
    std::cout << "2. Registro o inicio de sesión como comprador.\n";
    std::cout << "3. Salir.\n";
    std::cout << '\n';
    std::cout << "-------------------------------------------------------\n";
    std::cout << '\n';

    while (true)
    {
        int option{};
        std::cin >> option;
        std::cout << '\n';

            switch (option)
        {
        case 1:
            displayEmployeeMenu();
            return;

        case 2:
            displayCustomerMenu();
            return;

        case 3:
            std::cout << '\n'; // caso 3, exit
            std::cout << '\n';
            std::cout << "esperamos haya disfrutado la experiencia\n";

            exitMyProgram = true; // para cerrar el while de main()
            return;

        default:
            std::cout << '\n';
            std::cout << "ingresá un caracter válido.\n";
            break;

        } // fin del switch

        // Employee e y Customer c se van fuera de scoop acá.

    } // fin del while (true).

    // nunca se llega a ejecutar este pedazo de código.

} // void displayOptions();


// función para imprimir las opciones que tiene un empleado luego de que se elija "opciones para empleados"
void displayEmployeeMenu()
{
    std::cout << "Opciones para empleados:\n";
    std::cout << '\n';
    std::cout << "1. Registrar.\n";
    std::cout << "2. Iniciar Sesión.\n";
    std::cout << "3. Volver.\n";
    std::cout << "4. Salir.\n";
    std::cout << "\n";

    while (true)
    {
        int option{};
        std::cin >> option;
        Employee e{};

        switch (option)
        {
        case 1:
            getEmployee(&e);
            // leer Employees.txt, si concuerda el dni ingresado, proceder con iniciar sesión.
            return;

        case 2:

            // aceptar un dni de entrada, si el dni no concuerda con ninguno de Employees.txt, proceder con registrar.
            return;

        case 3:
            // vuelve al while (true) de main.cpp, sin salir de él.
            return;

        case 4:
            std::cout << '\n'; // caso 4, exit. Sale del while (true) de main.cpp.
            std::cout << '\n';
            std::cout << "esperamos haya disfrutado la experiencia\n";

            exitMyProgram = true;
            return;

        default:
            std::cout << '\n';
            std::cout << "ingresá un caracter válido.\n";
            break;
        } // fin del switch

    } // fin del while (true)

    // nunca se llega a ejecutar este pedazo de código.

} // void displayEmployeeMenu()



// función para imprimir las opciones que tiene un cliente luego de que se elija "opciones para clientes"
void displayCustomerMenu()
{
    std::cout << "Opciones para clientes:\n";
    std::cout << '\n';
    std::cout << "1. Registrar.\n";
    std::cout << "2. Iniciar Sesión.\n";
    std::cout << "3. Volver.\n";
    std::cout << "4. Salir.\n";
    std::cout << "\n";

    while (true)
    {
        int option{};
        std::cin >> option;
        Customer c{};

        switch (option)
        {
        case 1:
            getCustomer(&c);
            // leer Customers.txt, si concuerda el dni ingresado, proceder con iniciar sesión.
            return;

        case 2:

            // aceptar un dni de entrada, si el dni no concuerda con ninguno de Customers.txt, proceder con registrar.
            return;

        case 3:
            // vuelve al while (true) de main.cpp, sin salir de él.
            return;

        case 4:
            std::cout << '\n'; // caso 4, exit. Sale del while (true) de main.cpp.
            std::cout << '\n';
            std::cout << "esperamos haya disfrutado la experiencia\n";

            exitMyProgram = true;
            return;

        default:
            std::cout << '\n';
            std::cout << "ingresá un caracter válido.\n";
            break;
        } // fin del switch

    } // fin del while (true)

    // nunca se llega a ejecutar este pedazo de código.

} // void displayCustomerMenu()