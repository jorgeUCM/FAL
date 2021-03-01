// Jorge Millán García
// E51

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// Devuelve las posiciones de inicio y fin del segmento máximo encontrado.
void resolver(std::vector<int> const& v, int const& l) {
    int cont = 1, valorMax = v[v.size() - 1], valor = v[v.size() - 1], secMax = 0, llanos = 0;
    std::vector<int> pos;
    for (int i = v.size() - 2; i >= 0; --i) {
        if (v[i] == valor) {
            cont++;
        }
        else {
            cont = 1;
        }
        if (v[i] > valorMax) {
            valorMax = v[i];
        }
        if (cont == l) {
            if (v[i] >= valorMax) {
                pos.push_back(i + l - 1);
                llanos++;
            }
        }
        if (cont > secMax) {
            if(!pos.empty())
            secMax = cont;
        }
        valor = v[i];
    }
    std::cout << secMax << " " << llanos;
    for (int i = 0; i < pos.size(); i++) {
        std::cout << " " << pos[i];
    }
    std::cout << "\n";
    
}

// Funcion que lee de la entrada, 
// LLama a la función que resuelve el problema
// Escribe la salida
bool resuelveCaso() {
    int datos, l;
    std::cin >> datos >> l;
    if (!std::cin) {
        return false;
    }
    std::vector<int> v(datos);
    for (int& x : v) {
        std::cin >> x;
    }
    resolver(v, l);
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Texto.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


        while(resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
