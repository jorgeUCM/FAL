// Jorge Millán García
// E51

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Explicación del algoritmo utilizado
//La funcion resolver recibe el vector de la altura d edificios, la altura de la nave, la posicion inicial y la final.
//recorremos todo el vector y comprobamos si cada edificio es mas alto que la nave, de ser asi incrementamos el contador(secuencia de edificios mas altos que la nave),
//despues comprobamos si la secuencia es mas larga que la maxima y modificanmos la posicion inicial y la final.


// Coste del algoritmo utilizado
//Coste de la función O(N) siendo N el numero de elementos del vector de entrada ya que dentro del bucle for las operaciones son de coste constante.


// La función recibe un vector con las alturas de los edificios, y la altura de la nave que realizará el rescate
// Devuelve las posiciones de inicio y fin del segmento máximo encontrado.
void resolver(std::vector<int> const& v, int alturaNave, int& posIni, int& posFin) {
    int cont = 0, max = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > alturaNave) {
            cont++;

            if (cont > max) {
                max = cont;
                posFin = i;
                posIni = i - (cont - 1);
            }

        }
        else {
            cont = 0;
        }
    }

}

// Funcion que lee de la entrada, 
// LLama a la función que resuelve el problema
// Escribe la salida
void resuelveCaso() {
    // Lectura de los datos de entrada
    int numElem, alturaNave;
    std::cin >> numElem >> alturaNave;
    std::vector<int> v(numElem);
    for (int& i : v) std::cin >> i;
    // LLamada a la función resolver
    int p, q;
    resolver(v, alturaNave, p, q);
    // Escribir el resultado
    std::cout << p << ' ' << q << "\n";
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
    for (int i = 0; i < numCasos; ++i) resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
