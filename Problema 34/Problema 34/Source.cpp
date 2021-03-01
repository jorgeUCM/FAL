// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int>const &v, int ini, int fin) {

        int mitad = (ini + fin) / 2;
        if (ini + 1 == fin) {
            return v[ini];
        }
        else {
            if (v[mitad] <= v[0]) {
                resolver(v, mitad, fin);
            }
            else if (v[mitad] > v[0]) {
                resolver(v, ini, mitad);
            }
        }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam;
    std::cin >> tam;
    if (!std::cin)
        return false;
    std::vector<int>v(tam);
    for (int i = 0; i < tam; ++i) {
        std::cin >> v[i];
    }

        int sol = resolver(v, 0, v.size());
       std::cout << sol << "\n";
    
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


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}