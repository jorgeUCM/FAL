// Jorge Millán García
// E51

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>

// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado



// Recibe un vector con los datos de entrada del problema
// Debe contar el número de veces que aparece cada valor usando un vector auxiliar.
// Devuelve un vector con los valores que se repiten el número máximo de veces
// para que la función resuelveCaso solo tenga que escribirlos. 
// Si solo hay un valor que se repite el número máximo de veces el vector de salida
// tendrá solo ese valor 
std::vector<int> resolver(std::vector<int> const& v, int maximoValores) {

    int max = 0;
    std::vector<int> aux(maximoValores + 1);
    std::vector<int> resul;
    if (v.size() == 1) {
        resul.push_back(v[0]);
 }
    else {
        for (int i = 0; i < v.size(); i++) {
            
                aux[v[i]] = aux[v[i]] + 1;
               if (max < aux[v[i]]) {
                    max = aux[v[i]];
                }
            
        }
        for (int i = 0; i < aux.size(); i++) {
            if (aux[i] == max) {
                resul.push_back(i);
            }
        }
    }
    return resul;
}

// Entrada y salida de datos
bool resuelveCaso() {
    int numTiradas, valorMax;
    std::cin >> numTiradas >> valorMax;
    if (numTiradas == -1) return false;  // Entrada con centinela
    std::vector<int> v(numTiradas);
    for (int& i : v) std::cin >> i;
    // LLamada a la funcion resolver para calcular los valores que 
    // aparecen más veces
   std::vector<int> resul = resolver(v, valorMax);
                // Codigo
   for (int i = resul.size() - 1; i >= 0; i--) {
    
       std::cout << resul[i];
       if (i > 0) {
           std::cout << " ";
       }
   }
   std::cout <<  "\n";
   

                // Codigo

    return true;
}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("Texto.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt    
#endif

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}

