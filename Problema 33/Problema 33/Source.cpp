
#include <iostream>
#include <fstream>
#include <vector>
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(std::vector<int>v, int ini, int fin) {

        int mitad = (ini + fin) / 2;
        if (v.size() == 0 || v.size() == 1) {
            return v[0];
        }
        else {
            if (mitad - 1 >= 0 && v[mitad - 1] < v[mitad]) {
                return resolver(v, ini, mitad - 1);
            }
            else if(mitad + 1 < v.size() && v[mitad] > v[mitad + 1]){
                return resolver(v, mitad + 1, fin);
            }
            else {
                return v[mitad];
            }
        }
    }
    


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    int num, tam;
   
    std::cin >> tam;
    if (!std::cin) {
        return false;
    }
    std::vector<int>v(tam);
    for (int i = 0; i < v.size(); ++i) {
        std::cin >> num;
        v[i] = num;
    }
        int sol = resolver(v, 0, v.size());
        std::cout << sol << "\n";
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("Texto.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
        while(resuelveCaso());
    

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}