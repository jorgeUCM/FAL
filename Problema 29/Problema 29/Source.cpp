
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

//Recursion Final con coste O(n) siendo n el numero de digitos del numero 'num'.
int resolverFinal(int num, int sol) {
    sol = sol * 10 + num % 10;

    if (num < 10) {
        return sol;
    }
    return resolverFinal(num / 10, digito, sol);

}
//Recursion No Final con coste O(n) siendo n el numero de digitos del numero 'num'.
/*int resolverNoFinal(long long int num) {
   
    if (num < 10) {
        if (num%10 == digito) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        int sol;
        if (num % 10 == digito){
            sol = 1;
            }
        else {
            sol = 0;
        }
        return resolverNoFinal(num / 10, digito) + sol;
    }

}*/


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num;
    
    std::cin >> num;
    int sol1 = resolverFinal(num, 0);
 //   int sol2 = resolverNoFinal(num);
    std::cout << sol1 << "\n"; 
    //std::cout << sol2 << "\n";
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
