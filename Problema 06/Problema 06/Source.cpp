// Jorge Millán García
// E51

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using lli = long long int;
// Calcula un vector con los valores acumulados
std::vector<lli> resolver(std::vector<int> const& a, std::vector<lli>& v)
{
    v[0] = a[0];
    lli sum = v[0];
    for (int i = 1; i < v.size(); i++) {
        sum = sum + a[i];
        v[i] = sum;
  }
    return v;

}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // Lee las dos fechas entre las que tenemos datos
    int a1, a2;
    std::cin >> a1 >> a2;
    if (a1 == 0 && a2 == 0) return false;

   
    std::vector<int> a(a2 - a1 + 1);

    for (int i = 0; i < a.size(); i++) {
        std::cin >> a[i];
  }
    std::vector<lli> aux(a2 - a1 +1);
    std::vector<lli> v = resolver(a, aux);

    // Lectura de las preguntas
    int m; 
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int f1, f2;
        lli suma;

        std::cin >> f1 >> f2;
        if (f1 == f2) {
            suma = a[f1 - a1];
       }
        else if (f1 == a1) {
            suma = v[f2 - a1];
        }
        else {
            suma = v[f2 - a1] - v[f1 - a1 - 1];
        }
       
        std::cout << suma << "\n";

        // Aqui codigo del estudiante
    }
    std::cout << "---\n";

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


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}

