// Jorge Millán García
// 51
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//siendo N el numero de elementos del vector:
//coste final del programa: 2N, el cual está en O(N), ya que el primer for de insertar tiene coste O(n) y los otros 2 for tienen coste O(N) entre los 2, en total 2N

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tam, pos, max;
    bool resul = true;

    std::cin >> tam >> pos;
    std::vector<int> v(tam);

    for (int& num : v) // inserción de los elementos en el vector coste O(n), siendo N = tam
        std::cin >> num;

    if (pos == tam - 1) {
       std::cout << "SI\n"; // si la posicion "P" esta al final del vector, siempre es SI
    }

    else {
        max = v[0];
        for (int i = 0; i <= pos; i++) { // guardamos el valor máximo de la parte izquierda del vector [0..p], coste O(P), siendo P el numero de elementos desde 0 hasta p
            if (v[i] > max) {
                max = v[i];
            }
        }
        for (int j = pos + 1; j < tam; j++) {// comprobamos que el valor maximo de la parte izquierda, es menor que cualquier elemento de la parte derecha del vector [p+1..tam-1], coste O(G) siendo G el numero de elementos desde p hasta tam - 1
            if (v[j] <= max) {
                resul = false;
            }
        }


        if (resul) {
            std::cout << "SI\n";
        }
        else {
            std::cout << "NO\n";
        }
    }
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
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}