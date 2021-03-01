
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

//Recursion Final con coste O(n) siendo n el numero de digitos del numero 'num'.
int resolverFinal(int num, int sol, int pot) {
    sol = (num%10)*(pot*10) + num%10*pot + sol;

    if (num < 10) {
        return sol;
    }
    return resolverFinal(num / 10, sol, pot*100);

}
//Recursion No Final con coste O(n) siendo n el numero de digitos del numero 'num'.
int resolverNoFinal(int num) {

    if (num < 10) {
        return num * 10 + num;
    }

    return resolverNoFinal(num / 10) * 100 + ((num % 10 * 10) + num%10);
    

}


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num;

    std::cin >> num;
    int sol1 = resolverFinal(num, 0, 1);
    int sol2 = resolverNoFinal(num);
    std::cout << sol1 << " " << sol2 << "\n";
   
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
