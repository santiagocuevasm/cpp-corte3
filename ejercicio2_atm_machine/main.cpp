#include <iostream>
#include <string>
#include <vector>

#include "ATM.h"

void imprimir(const std::string& titulo, const std::vector<int>& v) {
    std::cout << titulo << ": [";
    for (std::size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << (i + 1 < v.size() ? ", " : "");
    }
    std::cout << "]\n";
}

int main() {
    ATM cajero;

    cajero.deposit({0, 0, 1, 2, 1});
    imprimir("Retiro 600", cajero.withdraw(600));

    cajero.deposit({0, 1, 0, 1, 1});
    imprimir("Retiro 600", cajero.withdraw(600));
    imprimir("Retiro 550", cajero.withdraw(550));

    // Prueba extra: quedan 3 billetes de 200
    imprimir("Retiro 400", cajero.withdraw(400));
    return 0;
}
