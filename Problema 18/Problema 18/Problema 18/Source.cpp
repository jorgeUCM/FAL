
// IMPORTANTE
//
// Nombre y apellidos del alumno
// Usuario del juez de clase
// Usuario del juez de examen que has utilizado en la prueba de hoy
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>

// Aqui la función implementada por el alumno para resolver el problema

void resolver(std::vector<int> v, const int longitudTramo) {
    int maximo = 0, ini = 0, fin = 0, pos = 0, contMax = 0;
    for (int i = 0; i < longitudTramo; ++i) {
        maximo += v[i];
        pos = i;
    }
    pos++;
    int aux = maximo;
    while (pos < v.size()) {
        aux = aux + v[pos] - v[pos - longitudTramo];
        if (aux > maximo) {
            maximo = aux;
            ini = pos - longitudTramo + 1;
            
       }
        if (aux == maximo) {
            fin = pos - longitudTramo + 1;
            contMax++;
        }
        pos++;
    }
    std::cout << maximo << " ";
    std::cout << ini << " ";
    std::cout << fin << "\n";
 
}

// Resuelve cada caso de la entrada
bool resuelveCaso() {
    // Lectura de los datos
    int numKilometros, longitudTramo;
    std::cin >> numKilometros >> longitudTramo;
    if (numKilometros == 0 && longitudTramo == 0) return false;
    std::vector<int> v(numKilometros); // nombre y altura
    for (int& n : v) {
        std::cin >> n;
    }
    // LLamada a la funcion que resuelve el problema
    resolver(v, longitudTramo);


    // Escribir el resultado

    return true;
}


int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("Texto.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

    // Para restablecer entrada. 
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}

