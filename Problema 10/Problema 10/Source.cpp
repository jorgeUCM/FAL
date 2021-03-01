
// Jorge Mill�n Garc�a
// E51

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Explicaci�n del algoritmo utilizado
//La funci�n resolver recibe el vector de datos y recorre el vector comprobando si los numeros son pares.
//Si son pares los inserta en la posici�n cont que empieza siendo 0) y luego lo incrementa, de este modo
//se quedan todos los pares a la izqueirda y los impares a la derecha, tras esto modificamos el tama�o del vector para quedarnos solo con los pares.


// Coste del algoritmo utilizado
// el coste del algoritmo es O(N) siendo N el numero de datos que tiene el vector v, ya que el for recorre el vector entero,
// y las operaciones de dentro del for son de coste unitario.


// Esta funci�n recibe un vector con los n�meros de matricula de los alumnos
// Modifica el vector de entrada eliminando los valores impares
void resolver(std::vector<int>& v) {
    int cont = 0;
    for (int i = 0; i < v.size(); i++){
        if (v[i] % 2 == 0) {
            v[cont] = v[i];
            cont++;
        }
}
    v.resize(cont);
}

// Funcion que lee de la entrada, 
// LLama a la funci�n que resuelve el problema
// Escribe la salida
bool resuelveCaso() {
    // Leer datos de entrada
    int numElem;
    std::cin >> numElem;
    if (numElem == -1) return false;
    std::vector<int> v(numElem);
    for (int i = 0; i < numElem; ++i) {
        std::cin >> v[i];
    }
    // LLamada a la funci�n resolver
    resolver(v);
    // Escribir el vector resultado
    if (v.size() > 0) std::cout << v[0];
    for (int i = 1; i < v.size(); ++i)
        std::cout << ' ' << v[i];
    std::cout << '\n';
    return true;
}

int main() {
    // Para la entrada por fichero. Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Texto.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
