
#include <iostream>
#include <fstream>

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
long long int resolver(long long int num) {
      if (num < 10) {
        if (num % 2 == 0) {
            return 0;
        }
        else {
            return num;
        }
 }
    else {
     
        if (num % 2 == 0){
            return resolver(num / 10);
        }
        else {
            return resolver(num / 10) * 10 + (num % 10);
        }
       
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    long long int num;
    std::cin >> num;
    if (!std::cin)  // fin de la entrada
        return false;
    long long int sol;
   sol =  resolver(num);

    std::cout << sol << "\n";

    // escribir sol

    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("Texto.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
