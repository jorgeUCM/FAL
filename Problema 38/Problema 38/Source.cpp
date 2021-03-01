

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tdatos {
    int cont = 0;
    int resul = 0;
};

tdatos resolver(std::vector<int>const &jugadores,int ronda, int ini, int fin,int &rondaAct) {
   tdatos sol;
    if (ini + 1 == fin) {
        rondaAct = 1;
        if (jugadores[ini] == 0 && jugadores[ini + 1] == 0) {
            sol.resul = 0;
        }
        else if (jugadores[ini] == 1 && jugadores[ini + 1] == 1) {
            sol.resul = 1;
            sol.cont++;
        }
        else {
            sol.resul = 1;
        }
        
    }
    else {
        int medio = (ini + fin) / 2;

        tdatos izq = resolver(jugadores, ronda, ini, medio,rondaAct);
        tdatos der = resolver(jugadores, ronda, medio + 1, fin, rondaAct);
        if (ronda > rondaAct) {
            if (izq.resul == 0 && der.resul == 0) {
                sol.resul = 0;
                sol.cont = izq.cont + der.cont;
            }
            else if (izq.resul == 1 && der.resul == 1) {
                sol.resul = 1;
                sol.cont = izq.cont + der.cont + 1;
            }
            else {
                sol.resul = 1;
                sol.cont = izq.cont + der.cont;
            }
            rondaAct++;
        }
        else {
            sol.cont = izq.cont + der.cont;
        }
        
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam, ronda, rondaAct;
    std::string jug;
    std::cin >> tam >> ronda;
    if (!std::cin)
        return false;
    std::vector<int> jugadores(tam);
    for (int i = 0; i < tam; i++) {
        std::cin >> jug;
        if (jug == "NP") {
            jugadores[i] = 0;
        }
        else {
            jugadores[i] = 1;
        }
    }
    
   tdatos sol = resolver(jugadores,ronda, 0, tam - 1, rondaAct);

   std::cout << sol.cont << "\n";


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Texto.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}