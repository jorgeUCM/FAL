#include <iostream>
#include <fstream>
#include <vector>
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(std::vector<int> const &presos, int ini, int fin) {
  
    if (ini + 2 == fin) {
        return presos[ini];
    }
    else {
        int mitad = (ini + fin) / 2;
        if (presos[mitad] - presos[ini] > mitad - ini) {
            return resolver(presos, ini, mitad+1);
        }
        else {
           return resolver(presos, mitad, fin);
        }
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    char ini = ' ', fin = ' ', letra = ' ';
    std::vector<int> presos;
    std::cin >> ini >> fin;
    int elems = int(fin) - int(ini);
    for(int i = 0; i < elems; i++) {
        std::cin >> letra;
        presos.push_back(int(letra));
    }

    int sol;
    if (presos[0] != int(ini)) {
        std::cout << ini << "\n";
    }
    else if (presos[presos.size() - 1] != int(fin)) {
        std::cout << fin << "\n";
    }
    else {
        sol = resolver(presos, 0, presos.size());
        std::cout << char(sol + 1) << "\n";
    }
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("Texto.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int casos;
    std::cin >> casos;
    for (int i = 0; i < casos; i++) {
        resuelveCaso();
    }

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
