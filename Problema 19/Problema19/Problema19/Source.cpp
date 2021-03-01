
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema

void resolver(std::vector<int> v, int L) {
    int numLlanos = 0, longLlano = 1;
    bool Llano = true;
    std::vector<int> ini;
    for (int i = 0; i < v.size() - 1; ++i) {
        if (v[i] - v[i + 1] >= -1 && v[i] - v[i + 1] <= 1) {
            longLlano++;
            if (longLlano >= L && Llano) {
                ini.push_back(i - L + 2);
                numLlanos++;
                Llano = false;
            }
        }
        else {
            longLlano = 1;
            Llano = true;
        }
    }
    std::cout << numLlanos;
    for (int i = 0; i < ini.size(); ++i) {
        std::cout << " " << ini[i];
    }
    std::cout << "\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int N, L;
    std::cin >> N >> L;
    std::vector<int> v(N);
    if (N == 0)
        return false;
    for (int &x : v) {
        std::cin >> x;
    }
    resolver(v, L);

    // escribir sol

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
