#include <iostream>
#include <limits>
#include "getEmployee.hh"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

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

// función llamada en displayEmployeeMenu()
void registerEmployee(Employee *e)
{
    std::cout << "-------------------------------------------------------\n";
    std::cout << "Registro de un nuevo empleado:\n";

    // UPDATE: eliminamos idEmployee ya que es una copia de e->id
    std::string buffer;
    getFromCmd("ingrese su nombre: ", &e->name);  // inicializamos e.name con el input
    getFromCmd("ingrese su documento: ", &e->id); // inicializamos e.id con el input

    std::ifstream EmployeesIn;
    EmployeesIn.open("texts/Employees.txt", std::ios::in); // abrimos el archivo en modo lectura

    if (EmployeesIn.fail())
    {
        std::cout << "no se pudo abrir el archivo.\n";
    }

    while (getline(EmployeesIn, buffer)) // recorre línea por línea
    {
        std::vector<std::string> token{commaSeparatedText(buffer)};

        if (e->id.compare(token.at(1)) == 0) // si una línea coincide con el id recién ingresado:
        {
            std::cout << '\n';
            std::cout << "El dni ingresado ya le corresponde a una persona.\n";
            std::cout << "El dni que intentó ingresar es: " << e->id << '\n';
            std::cout << "Volver a escribir el dni?\n";
            std::cout << '\n';
            std::cout << "1. Sí. (corregir el dni ingresado)\n";
            std::cout << "2. No. (continuar con el inicio de sesión)\n";

            while (true)
            {
                std::string optionStr;
                std::cin >> optionStr;
                std::cout << '\n';

                int option = std::atoi(optionStr.c_str());
                switch (option)
                {
                case 1:
                    registerEmployee(e);
                    return;

                case 2:
                    EmployeesIn.close();
                    return;
                    // loginEmployee();

                default:
                    std::cout << "ingresá un caracter válido.\n";
                    break;
                }
            } // while (true) de corregir el dni ingresado

            // nunca se llega a ejecutar este pedazo de código, los return del while true salen de registerEmployee()

        } // if coincide el dni ingresado con uno ya escrito

    } // while (getline(EmployeesIn, buffer)) // recorre línea por línea

    EmployeesIn.close(); // si no hay coincidencias cierra el archivo de modo lectura

    std::ofstream EmployeesOut; // y abre uno en modo escritura (append)
    EmployeesOut.open("texts/Employees.txt", std::ios::app);

    if (EmployeesOut.fail())
    {
        std::cout << "no se pudo abrir el archivo.\n";
    }

    // UPDATE: en vez de usar el buffer, escribimos directamente
    EmployeesOut << e->name;
    EmployeesOut << ",";
    EmployeesOut << e->id;
    EmployeesOut << "\n";

    EmployeesOut.close(); // cierra el archivo

    // se imprimen los datos del empleado recién registrado
    std::cout << "el documento de " << e->name << " es: " << e->id << '\n';
    std::cout << e->name << " registrado con éxito como Empleado.\n";
    std::cout << '\n';

} // void registerEmployee(Employee *e)

// función llamada en displayCustomerMenu()
void registerCustomer(Customer *c)
{
    std::cout << "-------------------------------------------------------\n";
    std::cout << "Registro de un nuevo cliente:\n";

    // UPDATE: eliminamos idCostumer porque es una copia de c->id
    std::string buffer{};
    getFromCmd("ingrese su nombre: ", &c->name);
    getFromCmd("ingrese su documento: ", &c->id);
    getFromCmd("ingrese su presupuesto: $", &c->money);

    std::ifstream CustomersIn;
    CustomersIn.open("texts/Customers.txt", std::ios::in); // abrimos el archivo en modo lectura

    if (CustomersIn.fail())
    {
        std::cout << "no se pudo abrir el archivo.\n";
    }

    while (getline(CustomersIn, buffer)) // recorre línea por línea
    {
        std::vector<std::string> token{commaSeparatedText(buffer)};

        if (c->id.compare(token.at(1)) == 0) // si una línea coincide con el id recién ingresado:
        {
            std::cout << '\n';
            std::cout << "El dni ingresado ya le corresponde a una persona.\n";
            std::cout << "El dni que intentó ingresar es: " << c->id << '\n';
            std::cout << "Volver a escribir el dni?\n";
            std::cout << '\n';
            std::cout << "1. Sí. (corregir el dni ingresado)\n";
            std::cout << "2. No. (continuar con el inicio de sesión)\n";

            while (true)
            {
                std::string optionStr;
                std::cin >> optionStr;
                std::cout << '\n';

                int option = std::atoi(optionStr.c_str());
                switch (option)
                {
                case 1:
                    registerCustomer(c);
                    return;

                case 2:
                    return;

                    // loginCustomer();
                default:
                    std::cout << "ingresá un caracter válido.\n";
                    break;
                }

            } // while (true) de corregir el dni ingresado

            // nunca se llega a ejecutar este pedazo de código, los return del while true salen de registerCustomer()

        } // if coincide el dni ingresado con uno ya escrito

    } // while (getline(CustomersIn, buffer))

    CustomersIn.close(); // si no hay coincidencias cierra el archivo de modo lectura

    std::ofstream CustomersOut;
    CustomersOut.open("texts/Customers.txt", std::ios::app);

    if (CustomersOut.fail())
    {
        std::cout << "no se pudo abrir el archivo.\n";
    }

    // UPDATE: en vez de escribir al buffer, escribimos directamente al archivo
    CustomersOut << c->name;
    CustomersOut << ",";
    CustomersOut << c->id;
    CustomersOut << ",";
    CustomersOut << std::to_string(c->money);
    CustomersOut << "\n";

    CustomersOut.close();

    // se imprimen los distintos volores.
    std::cout << "el documento de " << c->name << " es: " << c->id << '\n';
    std::cout << "el presupuesto de " << c->name << " es: $" << c->money << '\n';
    std::cout << c->name << " registrado con éxito como Cliente.\n";
    std::cout << '\n';

} // void registerCustomer(Customer *c)

// función llamada en main()
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
        std::string optionStr;
        std::cin >> optionStr;
        std::cout << '\n';

        int option = std::atoi(optionStr.c_str());

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
            return;               // vuelve al main()

        default:
            std::cout << '\n';
            std::cout << "ingresá un caracter válido.\n";
            break;

        } // fin del switch

        // Employee e y Customer c se van fuera de scoop acá.

    } // fin del while (true) de displayOptions().

    // nunca se llega a ejecutar este pedazo de código porque los return salen de displayOptions(), vuelven al main, pero sin salir, a menos de que se use exitMyProgram

} // void displayOptions();

// función llamada en displayOptions()
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
        std::string optionStr;
        std::cin >> optionStr;
        std::cout << '\n';

        int option = std::atoi(optionStr.c_str());
        Employee e{};

        switch (option)
        {
        case 1:
            registerEmployee(&e);
            return;

        case 2:
            loginEmployee(&e);
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

    } // fin del while (true) de displayEmployeeMenu()

    // nunca se llega a ejecutar este pedazo de código porque los return salen de displayEmployeeMenu()

} // void displayEmployeeMenu()

// función llamada en displayOptions()
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
        std::string optionStr;
        std::cin >> optionStr;
        std::cout << '\n';

        int option = std::atoi(optionStr.c_str());
        Customer c{};

        switch (option)
        {
        case 1:
            registerCustomer(&c);
            return;

        case 2:
            loginCustomer(&c);
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

    } // fin del while (true) de displayCostumersMenu()

    // nunca se llega a ejecutar este pedazo de código porque los return del while(true) salen de displayCustomerMenu()

} // void displayCustomerMenu()

// devuelve un vector con los tokens (datos) separados después de cada coma
std::vector<std::string> commaSeparatedText(std::string buffer)
{
    std::stringstream ss(buffer);
    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(ss, token, ',')) // busca en el buffer y escribe hasta encontrar una ",". guarda lo que encontró en el índice correspondiente
    {
        tokens.push_back(token); // mete un elemento en el indice correspondiente, arrancando de 0.
    };

    return tokens;
}

// inicia sesión a un empleado mediante el dni
void loginEmployee(Employee *e)
{
    std::cout << "-------------------------------------------------------\n";
    std::cout << "Inicio de sesión de un empleado:\n";

    std::string buffer;
    getFromCmd("ingrese su documento: ", &e->id); // inicializamos e.id con el input

    std::ifstream EmployeesIn;
    EmployeesIn.open("texts/Employees.txt", std::ios::in); // abrimos el archivo en modo lectura

    if (EmployeesIn.fail())
    {
        std::cout << "no se pudo abrir el archivo.\n";
    }

    while (getline(EmployeesIn, buffer)) // recorre línea por línea
    {
        std::vector<std::string> token{commaSeparatedText(buffer)}; // copia la línea en el buffer

        if (e->id.compare(token.at(1)) == 0) // si el dni recién ingresado es el mismo al de la línea leída
        {
            std::cout << "El dni ingresado le corresponde a " << token.at(0) << '\n';
            std::cout << "Iniciando sesión.\n";
            printEmployeeOptions();
            EmployeesIn.close();
            return; // vuelve al main()
        }

        else // si no encuentra coincidencia, sigue a la siguiente línea
            continue;

    } // while (getline(EmployeesIn, buffer)) // recorre línea por línea

    if (EmployeesIn.eof()) // si llega al fin del archivo sin encontrar ninguna coincidencia:
    {
        std::cout << "el dni ingresado no coincidió con ninguno de la base de datos.\n";
        std::cout << "el dni que intentaste ingresar fue: " << e->id << "\n";
        std::cout << "Volver a escribir el dni?\n";
        std::cout << '\n';
        std::cout << "1. Sí. (corregir el dni ingresado)\n";
        std::cout << "2. No. (continuar con el registro)\n";

        while (true)
        {
            std::string optionStr;
            std::cin >> optionStr;
            std::cout << '\n';

            int option = std::atoi(optionStr.c_str());
            switch (option)
            {
            case 1:
                EmployeesIn.close();
                loginEmployee(e);
                return; // vuelve al main()

            case 2:
                EmployeesIn.close();
                registerEmployee(e);
                return; // vuelve al main()

            default:
                std::cout << "ingresá un caracter válido.\n";
                break;

            } // switch(option)

        } // while(true) de corregir el dni recién ingresado

        // nunca se llega a ejecutar este pedazo de código, los return del while true salen de loginEmployee()

    } // if (EmployeesIn.eof())

    EmployeesIn.close(); // si no hay coincidencias cierra el archivo de modo lectura

} // loginEmployee(Employee* e)

// inicia sesión a un cliente mediante el dni
void loginCustomer(Customer *c)
{
    std::cout << "-------------------------------------------------------\n";
    std::cout << "Inicio de sesión de un cliente:\n";

    std::string buffer;
    getFromCmd("ingrese su documento: ", &c->id); // inicializamos c.id con el input

    std::ifstream CustomersIn;
    CustomersIn.open("texts/Customers.txt", std::ios::in); // abrimos el archivo en modo lectura

    if (CustomersIn.fail())
    {
        std::cout << "no se pudo abrir el archivo.\n";
    }

    while (getline(CustomersIn, buffer)) // recorre línea por línea
    {
        std::vector<std::string> token{commaSeparatedText(buffer)}; // copia la línea al buffer

        if (c->id.compare(token.at(1)) == 0) // si el dni recién ingresado coincide con el de la línea:
        {
            std::cout << "El dni ingresado le corresponde a " << token.at(0) << '\n';
            std::cout << "Iniciando sesión.\n";
            // printCustomerOptions();
            CustomersIn.close();
            return; // vuelve al main()
        }
        else // sino, continúa
            continue;
    } // while (getline(CustomersIn, buffer)) // recorre línea por línea

    if (CustomersIn.eof()) // si llega al fin del archivo sin encontrar ninguna coincidencia:
    {
        std::cout << "el dni ingresado no coincidió con ninguno de la base de datos.\n";
        std::cout << "el dni que intentaste ingresar fue: " << c->id << "\n";
        std::cout << "Volver a escribir el dni?\n";
        std::cout << '\n';
        std::cout << "1. Sí. (corregir el dni ingresado)\n";
        std::cout << "2. No. (continuar con el registro)\n";

        while (true)
        {
            std::string optionStr;
            std::cin >> optionStr;
            std::cout << '\n';

            int option = std::atoi(optionStr.c_str());
            switch (option)
            {
            case 1:
                CustomersIn.close();
                loginCustomer(c);
                return; // vuelve al main()

            case 2:
                CustomersIn.close();
                registerCustomer(c);
                return; // vuelve al main()

            default:
                std::cout << "ingresá un caracter válido.\n";
                break;
            } // switch(option)

        } // while(true) de corregir el dni recién ingresado

        // nunca se llega a ejecutar este pedazo de código, los return del while true salen de loginCustomer()

    } // if (CustomersIn.eof())

    CustomersIn.close(); // si no hay coincidencias cierra el archivo de modo lectura
} // loginCustomer(Customer* c)

void printEmployeeOptions()
{
    
    
    Product p{}; // inicializamos un struct Product p para almacenar los datos del producto
    
    while (true)
    {
        std::cout << '\n';
        std::cout << "-------------------------------------------------------\n";
        std::cout << "Opciones de empleado:\n";
        std::cout << '\n';
        std::cout << "1. Cargar un nuevo producto.\n";
        std::cout << "2. Imprimir lista de productos.\n";
        std::cout << "3. Log Out (volver al menú principal).\n";
        std::cout << "4. Salir.\n";
        std::cout << '\n';
        
        std::string optionStr;
        std::cin >> optionStr;
        std::cout << '\n';
        
        int option = std::atoi(optionStr.c_str());
        switch (option)
        {
        case 1:
            writeProducts(&p);
            break;

        case 2:
            printProducts(&p);
            break;

        case 3:
            return;

        case 4:
            exitMyProgram = true;
            return;

        default:
            std::cout << "ingresá un caracter válido.\n";
            break;

        } // switch(option)

    } // while (!exit)

} // printEmployeeOptions()

void printCustomerOptions()
{
}

// función que toma datos de un producto y los escribe en Products.txt
void writeProducts(Product *p)
{
    std::cout << '\n';
    std::cout << "-------------------------------------------------------\n";
    getFromCmd("Ingrese el nombre del producto: ", &p->name);
    getFromCmd("Ingrese la cantidad de productos: ", &p->amount);
    getFromCmd("Ingrese el precio del producto [incluya el signo '$']: ", &p->price);

    std::ofstream ProductsOut; // y abre uno en modo escritura (append)
    ProductsOut.open("texts/Products.txt", std::ios::app);

    if (ProductsOut.fail())
    {
        std::cout << "no se pudo abrir el archivo.\n";
    }

    // UPDATE: en vez de usar el buffer, escribimos directamente
    ProductsOut << p->name;
    ProductsOut << ",";
    ProductsOut << p->amount;
    ProductsOut << ",";
    ProductsOut << p->price;
    ProductsOut << '\n';

    ProductsOut.close(); // cierra el archivo

} // void writeProducts(Product* p)

void printProducts(Product *p)
{
    std::string buffer;
    std::ifstream ProductsIn;
    ProductsIn.open("texts/Products.txt", std::ios::in); // abrimos el archivo en modo lectura

    if (ProductsIn.fail())
    {
        std::cout << "no se pudo abrir el archivo.\n";
    }

    while (getline(ProductsIn, buffer)) // recorre línea por línea
    {
        std::cout << buffer << '\n';
    }

    if (ProductsIn.eof())
        ProductsIn.close();

    ProductsIn.close();
} // voidreadProducts(Product* p)