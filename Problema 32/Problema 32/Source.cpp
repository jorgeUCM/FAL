//*****************
// IMPORTANTE
//
// Nombre y apellidos del alumno
// Usuario del juez de examen que has utilizado en la prueba de hoy
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>

//*******************************
// Explicacion del algoritmo utilizado
// Coste de la solucion. Recurrencia y orden de complejidad
//*******************
int resolver(std::vector<int> const& vA, std::vector<int> const& vB, int ini, int fin) {
    if (ini + 1 == fin) {
              
            return vA[ini + 1];
        
    }
    else {
        int mitad = (ini + fin) / 2;
        if (vA[mitad] == vB[mitad]) {
           return resolver(vA, vB, mitad, fin);
        }
        else {
           return resolver(vA, vB, ini, mitad);
        }
    }
}

void resuelveCaso() {
    int numA, n;
    // lectura del vector A
    std::cin >> numA;
    std::vector<int> vA(numA);
    for (int i = 0; i < numA; ++i)
        std::cin >> vA[i];
    // lectura del vector B
    std::vector<int> vB(numA - 1);
    for (int j = 0; j < numA - 1; ++j)
        std::cin >> vB[j];

    if (vA.size() == 1) {
        std::cout << vA[0] << "\n";
    }
    else if (vA.size() == 2) {
        if (vA[0] == vB[0]) {
            std::cout << vA[1] << "\n";
        }
        else {
            std::cout << vA[0] << "\n";
        }
    }
    else {
        if (vA[0] != vB[0]) {
            std::cout << vA[0] << "\n";
        }
        else if (vA[vA.size() - 1] != vB[vB.size() - 1]) {
            std::cout << vA[vA.size() - 1] << "\n";
        }
        else {
            n = resolver(vA, vB, 0, vA.size());
            std::cout << n << '\n';
        }
    }

}


int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("Texto.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int casos;
    std::cin >> casos;
    for (int i = 0; i < casos; ++i)
        resuelveCaso();

    // Para restablecer entrada.
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
