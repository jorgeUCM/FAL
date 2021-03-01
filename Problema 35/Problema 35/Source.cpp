
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector<int>const &v, int ini, int fin, int valor) {
    int mitad = (ini + fin) / 2;
    if (ini >= fin) {
        return -1;
    }
    else {
  
        if (v[mitad] > valor + mitad) {
            return resolver(v, ini, mitad, valor);
        }
        else if(v[mitad] < valor + mitad){
            return resolver(v, mitad + 1, fin, valor);
        }
        else{return v[mitad];}
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tam, valor;
    std::cin >> tam >> valor;
    std::vector<int> v(tam);
    for (int i = 0; i < tam; ++i) {
        std::cin >> v[i];
    }
   int sol = resolver(v, 0, v.size(), valor);
    // escribir sol
   if (sol == -1) {
       std::cout << "NO" << "\n";
   }
   else {
       std::cout << sol << "\n";
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