// Nombre y apellidos del alumno
// Usuario del juez de clase

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

// Coste del algoritmo utilizado: al ser un bucle for está el coste en O(N), 
// primera linea de codigo de la función son 3 asignaciones O(3)
//bucle for siempre es O(N), siendo N el nuemro de elementos del vector ya que siempre se llega hasta el final del vector
// dentro del bucle for tenemos 2 ifs 3 asignaciones y 2 operaciones aritmeticas, en total seria un coste de O(6)
// fuera del for hay 2 asignaciones y 2 operaciones aritmeticas, en total o(4)

// coste total = 6N + 7 que pertenece al orden O(N).
struct tValor { // struct que almacenara los valores finales de la funcion resolver
    int cont;
    int suma;
};

// Función que resuelve el problema
// Recibe un vector con los datos
// Devuelve suma de los valores y número de sumandos de la suma
tValor resolver(std::vector<int> v) {
    int min = v[0], contMin = 1, suma = v[0]; // min sera el valor minimo del vector, contMin sera las veces que se repite el minimo, suma sera la suma de todos los elementos del vector
    tValor info;
   
    for (int i = 1; i < v.size(); ++i) {// bucle que recorre el vector, sumando todos sus elementos y guatdando el minimo del vector y las veces que se repite.
        
        suma = suma + v[i];
        if (v[i] < min) { // si encuentra un elemento menor, el contador se resetea y el minimo pasa a ser ese elemento
            min = v[i];
            contMin = 1;
        }
        else if (v[i] == min) {// si encuentra un valor igual al minimo, aumenta el contador de minimos.
            contMin++;
        }
    }


    info.cont = v.size() - contMin; // es el numero de elementos sumados que es igual al tamaño del vector menos el contador de minimos.
    info.suma = suma - (contMin * min); // la suma total, es la suma de todos los elementos del vector menos el minimo por las veces que se repite.
    return info;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // Lectura de los datos
    int numElem;
    std::cin >> numElem;
    std::vector<int> v(numElem);
    for (int& i : v) std::cin >> i;
    // LLamar a la función resolver
     tValor s = resolver(v);
    // Escribir los resultados
    std::cout << s.suma << ' ' << s.cont << '\n';
}

int main() {
    // Para la entrada por fichero. Comentar para mandar a acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Texto.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();

    // Para restablecer entrada. Comentar para mandar a acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
