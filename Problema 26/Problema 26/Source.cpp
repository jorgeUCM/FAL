
#include <iostream>
#include <fstream>
// propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

int resolver(long long int num, long long int newNum) {
    if (num < 10) {
        return newNum * 10 + num % 10;
    }
    return resolver(num / 10, 10 * newNum + (num % 10));
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    long long int num;
    std::cin >> num;
    if (num == 0)  // fin de la entrada
        return false;

    long long int sol = resolver(num, 0);
    std::cout << sol << "\n";    // escribir sol

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
