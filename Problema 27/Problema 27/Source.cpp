// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(int num, int suma) {
    if (suma > 0 && suma % (num % 10) != 0) {
        return 0;
    }
    if (num < 10) {
        return num;
    }

    suma = num % 10 + suma;
    resolver(num / 10, suma);
    return 1;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    int num;
    std::cin >> num;
    int sol = resolver(num, 0);
    if (sol == 1) {
        std::cout << "SI" << "\n";
    }
    else {
        std::cout << "NO" << "\n";
    }
    // escribir sol

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
    for (int i = 0; i < casos; ++i) {
        resuelveCaso();
    }

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
