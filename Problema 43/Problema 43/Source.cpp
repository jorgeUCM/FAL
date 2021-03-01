#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

struct datos {
    int max = 0;
    int min = 0;
    bool ordenado = true;
};
// función que resuelve el problema
datos resolver(std::vector<int>const &v, int ini, int fin) {
    datos d;
    int mitad = (ini + fin) / 2;
    if (ini == fin) {
        d.max = v[ini];
        d.min = v[ini];
            return d;
    }

    datos Iz = resolver(v, ini, mitad);
    datos Dr = resolver(v, mitad + 1, fin);

    if (Dr.max < Iz.max || Dr.min < Iz.min) {
        d.ordenado = false;
    }
    
    if (!Iz.ordenado || !Dr.ordenado) {
        d.ordenado = false;
    }
    d.max = std::max(Iz.max, Dr.max);
    d.min = std::min(Iz.min, Dr.min);
    return d;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int num;
    std::cin >> num;
    if (num == 0) {
        return false;
    }

    std::vector<int>v;
   while(num != 0) {
       v.push_back(num);
        std::cin >> num;
       
    }
    if (v.size() == 1) {
        std::cout << "SI" << "\n";
    }
    else {
        datos sol = resolver(v, 0, v.size() - 1);
        if (sol.ordenado) {
            std::cout << "SI" << "\n";
        }
        else {
            std::cout << "NO" << "\n";
        }
    }
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Texto.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 



    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}