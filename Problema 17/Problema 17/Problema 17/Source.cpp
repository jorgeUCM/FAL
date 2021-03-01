//*****************
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
#include <algorithm>


//*******************************
// Aqui especificación de la función que resuelve el problema. 
//
//
//
// Aqui la justificación del coste de la función que resuelve el problema
// 
// 
// 
//*******************************



// Aqui la función implementada por el alumno

struct piso {
    std::string id;
    int alturaE;
    int alturaP;
 
};

std::vector<std::string> resolver(std::vector<piso> piso) {
    int alturaMax = -1;
    std::vector<std::string> resul;
    for (int i = piso.size() - 1 ; i >= 0; --i) {
        if (piso[i].alturaP > alturaMax) {
            resul.push_back(piso[i].id);
        }
        if (piso[i].alturaE > alturaMax) {
            alturaMax = piso[i].alturaE;
        }
        
    }
    return resul;
}

bool resuelveCaso() {
    int numEdificios, alturaPiso, alturaEdificio;
    std::string id;

    std::cin >> numEdificios;
    if (numEdificios == 0) return false;
    std::vector<piso> pisos(numEdificios);
    piso piso;
    for (int i = 0; i < numEdificios; ++i) {
        std::cin >> piso.id >> piso.alturaE >> piso.alturaP;
        pisos[i] = piso;
        
   }


   std::vector<std::string> resultado = resolver(pisos);

 
   if (resultado.size() == 0) {
       std::cout << "Ninguno" << "\n";
   }
   else {
       std::cout << resultado.size() << "\n";
       std::cout << resultado[0];
       for (int i = 1; i < resultado.size(); ++i) {
           std::cout << " " << resultado[i];
       }
       std::cout << "\n";
   }
    return true;
}


int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("Texto.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // Para restablecer entrada. 
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
