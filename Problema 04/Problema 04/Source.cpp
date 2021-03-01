// Nombre del estudiante. 
// Usuario del juez.

#include <iostream>
#include <fstream>
#include <vector>

// Coste del algoritmo utilizado:

// en el caso peor, entraria en el primer while, el coste es de O(N) siendo N la suma de los valores de los vectores v1 y v2.

//en la primera linea de codigo tenemos 3 asignaciones O(3)
// el coste del interior del bucle es constante, ya que se trata de asignaciones y comparaciones, el coste del bucle depende del numero de valores de v1 y de v2.
// dentro del bucle tenemos 4 comparaciones, 3 asignaciones (push_back) y 4 operaciones aritmeticas

// coste total: 11N + 3 siendo N = v1.size() + v2.size(), está en el orden de O(n)


std::vector<int> resolver(std::vector<int>const& v1, std::vector<int>const& v2) {
    // Declaración de variables
    // Codigo del alumno
    int i = 0, j = 0, x = 0;
    std::vector<int> sol;

    while (i < v1.size() && j < v2.size()) { // si los 2 vectores tienen componentes, los recorre comparando sus valores e insertandolos en el vector sol.

        if (v1[i] < v2[j]) { // en caso de que el valor del primer vector sea menor, lo inserta en sol, y aumenta el contador del vector v1
            sol.push_back(v1[i]);
            i++;
        }
        else if(v1[i] > v2[j]){ // en caso de que el valor del segundo vector sea menor, lo inserta en sol y aumenta el contador del vector v2
            sol.push_back(v2[j]);
            j++;
        }
        else { // en caso de que sean los valores iguales, inserta el de v1 (podria ser el de v2) y aumenta los 2 contadores.
            sol.push_back(v1[i]);
            i++;
            j++;
        }
        x++;

    }
    while (i < v1.size()) {// si solo el vector i tiene componentes las insertamos todas directamente
       
        sol.push_back(v1[i]);
        i++;

    }
    while (j < v2.size()) {// si solo el vector j tiene componentes las insertamos todas directamente
        sol.push_back(v2[j]);
        j++;


    }
    return sol;
}


void resuelveCaso() {
    // Lectura de los datos de entrada
    int n1, n2;
    std::cin >> n1 >> n2;
    std::vector<int> v1(n1);
    std::vector<int> v2(n2);
    for (int& i : v1) std::cin >> i;
    for (int& j : v2) std::cin >> j;
    // LLamada a la función que resuelve el problema
    std::vector<int> sol = resolver(v1, v2);
    // Escribir los resultados
    if (!sol.empty()) {
        std::cout << sol[0];
        for (int i = 1; i < sol.size(); ++i)
            std::cout << ' ' << sol[i];
    }
    std::cout << '\n';
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto

#ifndef DOMJUDGE
    std::ifstream in("Texto.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }

    // Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}