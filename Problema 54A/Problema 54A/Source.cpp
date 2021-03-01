#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

struct tDatos {
	int costeMax;
	std::vector < std::pair <int, int > > costeSuperf;
};
// Para ordenar los objetos hacemos una clase comparador que
// sobrecarga el operador parentesis
class comparador {
public:
	bool operator ()(std::pair <int, int > p1, std::pair <int, int > p2) {
		return (float)p1.second / p1.first > (float)p2.second / p2.first;
	}
};
// Para escribir la solucion
std::ostream& operator << (std::ostream& salida, std::vector <bool > const& v) {
	for (int i = 0; i < v.size(); ++i)
		if (v[i]) std::cout << i << " ";
	std::cout << "\n";
	return salida;
}
// Para estimar la mayor superficie que se puede conseguir desde este momento
int estimar(tDatos const& datos, int costeAct, int k) {
	int i = k + 1; int sumaCoste = costeAct; int sumaSuperf = 0;
	while (i < datos.costeSuperf.size() &&
		sumaCoste + datos.costeSuperf[i].first <= datos.costeMax) {
		sumaCoste += datos.costeSuperf[i].first;
		sumaSuperf += datos.costeSuperf[i].second;
		++i;
	}
	// La parte que queda sin completar
	if (i < datos.costeSuperf.size() && sumaCoste < datos.costeMax)
		sumaSuperf += datos.costeSuperf[i].second * (datos.costeMax - sumaCoste) / (float)datos.costeSuperf[i].first + 1;
	return sumaSuperf;
}
// Parametros
// datos - datos de entrada
// k - etapa
// sol - vector de dimension el numero de adornos , guarda la solucion actual
// costeAct - coste de la solucion actual
// superficieAct - Superficie de la solucion actual
// solMejor - solucion mejor hasta este momento
// superficieMejor - superficie de la solucion mejor
void resolver(tDatos const& datos, int k, std::vector <bool >& sol, int costeAct,
	int superficieAct, std::vector <bool >& solMejor, int& superficieMejor) {
	// Compra el objeto
	sol[k] = true;
	costeAct += datos.costeSuperf[k].first;
	superficieAct += datos.costeSuperf[k].second;
	if (costeAct <= datos.costeMax) { // Si es valida
		if (k == sol.size() - 1) { // Es solucion
				if (superficieAct > superficieMejor) { // Solucion mejor
					superficieMejor = superficieAct;
					solMejor = sol;
				}
		}
		else {
			resolver(datos, k + 1, sol, costeAct, superficieAct, solMejor, superficieMejor);
		}
	}
	costeAct -= datos.costeSuperf[k].first; // Recupera el valor
	superficieAct -= datos.costeSuperf[k].second; // Recupera el valor
	// No compra el objeto
	sol[k] = false;
	// Siempre es valido
	if (k == sol.size() - 1) { // Es solucion
		if (superficieAct > superficieMejor) { // Solucion mejor
			superficieMejor = superficieAct;
			solMejor = sol;
		}
	}
	else {
		if (estimar(datos, costeAct, k) + superficieAct > superficieMejor)
			resolver(datos, k + 1, sol, costeAct, superficieAct, solMejor, superficieMejor);
	}
}
int inicializarSuperficie(tDatos const& Obj, int costeMax) {
	int i = 0; int sumaSuperficie = 0; int sumaCoste = 0;
	while (i < Obj.costeSuperf.size() && sumaCoste + Obj.costeSuperf[i].first <= costeMax) {
		sumaSuperficie += Obj.costeSuperf[i].second;
		sumaCoste += Obj.costeSuperf[i].first;
		++i;
	}
	return sumaSuperficie;
}
bool resuelveCaso() {
	int numObjetos;
	std::cin >> numObjetos;
	if (!std::cin) return false;
	tDatos datos;
	std::cin >> datos.costeMax;
	// Lee el coste y la superficie de cada adorno
	for (int i = 0; i < numObjetos; ++i) {
		int coste, superficie;
		std::cin >> coste >> superficie;
		datos.costeSuperf.push_back({ coste , superficie });
	}
	// ordena los datos por superficie por unidad de coste
	std::sort(datos.costeSuperf.begin(), datos.costeSuperf.end(), comparador());
	std::vector <bool > sol(numObjetos);
	int costeAct = 0; int superficieAct = 0;
	int superficieMejor = inicializarSuperficie(datos, datos.costeMax);
	std::vector <bool > solMejor;
	resolver(datos, 0, sol, costeAct, superficieAct, solMejor, superficieMejor);
	// std :: cout << solMejor ;
	std::cout << superficieMejor << "\n";
	return true;
}
int main() {
# ifndef DOMJUDGE
	
		std::ifstream in("Texto.txt ");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
# endif
	while (resuelveCaso()) {} // Resolvemos todos los casos
# ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system(" PAUSE ");
# endif
	return 0;
}
