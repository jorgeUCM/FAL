
#include <iostream>
#include <fstream>
 // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(long long int num){
    
    if (num < 10) {
        return 1;
    }
    else {
        num = num / 10;
        
        return resolver(num) + 1;
    }
    
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    long long int num;
    std::cin >> num;
    if (!std::cin)  // fin de la entrada
        return false;

   int sol = 0;
 
    std::cout << resolver(num) << "\n";    // escribir sol

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
