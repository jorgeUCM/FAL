// Nombre del estudiante. 
// Usuario del juez.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int resolver(std::vector<int> km) {
    std::sort(km.begin(), km.end());
    int cont = 1, max = 1, valor = km[0], sol = valor;
    for (long long int i = 1; i < km.size(); ++i) {
        if (km[i] == valor) {
            cont++;
        }
        else{ 
            cont = 1;
        }
        if (cont > max) {
            max = cont;
            sol = valor;
        }
       
        valor = km[i];
    }

    return sol;
}

bool resuelveCaso() {
    long long int accidentes;
    int resul;

    std::cin >> accidentes;
    if (accidentes == -1) {
        return false;
    }

    std::vector<int> km(accidentes);
    
    for (int& x : km) {
        std::cin >> x;
    }
    resul = resolver(km);

    std::cout << resul << "\n";

    return true;
}



int main() {

#ifndef DOMJUDGE
    std::ifstream in("Texto.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {} //Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
