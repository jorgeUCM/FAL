// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
struct sol {
    int pruebas = 0;
    int ini = 0;
};

// función que resuelve el problema
sol resolver(std::vector<int>v) {
    sol sol;
    int marca = v[0];
    int pruebas = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] <= marca) {
            pruebas++;
          
            if (sol.pruebas <= pruebas) {
                sol.pruebas = pruebas;
                sol.ini = i - sol.pruebas + 1;
            }
        }
        else {
            pruebas = 0;
            marca = v[i];
        }
    }
    if (sol.pruebas == 0) {
        sol.ini = v.size();
    }
    
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num, aux;
    std::cin >> num;
    if (num == 0) {
        return false;
    }
    std::vector<int>v(num);
    for(int i = 0; i < num; i++){
        std::cin >> aux;
        v[i] = aux;
    }
    sol sol = resolver(v);
    std::cout << sol.pruebas << " " << sol.ini << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Texto.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


      while(resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}