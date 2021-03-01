#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>

struct solu {
	std::vector<int>cantCol;
	std::vector<int>sol;
};

// Escribe una solucion
void escribirSolucion(std::vector <int> const& v) {
	for (char c : v) {
		if (c == 0) {
			std::cout << "azul ";
		}
		if (c == 1) {
			std::cout << "rojo ";
		}
		if (c == 2) {
			std::cout << "verde ";
		}
	}
	std::cout << '\n';
}
bool esValida(int tam, int k, int i, solu &sol, std::vector<int> colores) {

	if (sol.sol[k - 1] == 2 && i == 2 ) {
		return false;
	}
	if (sol.cantCol[2] > sol.cantCol[0]) {
		return false;
	}
	
	return true;
}
void variaciones(int tam, int k, solu &sol, std::vector<int> colores, bool &cierto) {
	
	for (char i = 0; i < colores.size(); ++i) {
		if (colores[i] > 0) {
	
			sol.cantCol[i]++;
			colores[i]--;
			if (esValida(tam, k, i, sol, colores)) {
				sol.sol[k] = i;
				if (k == tam - 1) { // Es solucion
					if (sol.cantCol[1] > sol.cantCol[0] + sol.cantCol[2]) {
						escribirSolucion(sol.sol);
						cierto = true;
					}
				}
				if (k < tam - 1) { // Genera el resto de la solucion
					variaciones(tam, k + 1, sol, colores, cierto);
				}
			}
			sol.cantCol[i]--;
			colores[i]++;
			
		}


	}
}
// Resuelve un caso de prueba , leyendo de la entrada la
// configuracion , y escribiendo la respuesta
bool resuelveCaso() {
	int m, azules, rojos, verdes;
	bool cierto = false;
	std::cin >> m;
	if (m == 0) return false;
	solu sol;
	std::vector<int>solucion(m);
	std::vector<int>cantidadColores(3);
	sol.sol = solucion;
	sol.cantCol = cantidadColores;
	std::vector<int> colores(3);
	std::cin >> azules;
	std::cin >> rojos;
	std::cin >> verdes;
	if (m == 0 && azules == 0 && rojos == 0 && verdes == 0) {
		return false;
	}
	else {
		colores[0] = azules;
		colores[1] = rojos;
		colores[2] = verdes;
		if (colores[1] == 0) {
			std::cout << "SIN SOLUCION" << "\n";
		}
		else {
			sol.sol[0] = 1;
			sol.cantCol[1]++;
			colores[1]--;
			variaciones(m, 1, sol, colores, cierto);
			if (!cierto) {
				std::cout << "SIN SOLUCION" << "\n";
			}
		}
		
		std::cout << '\n';
	}
	return true;
}
int main() {
# ifndef DOMJUDGE
	std::ifstream in("Texto.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std :: cin to casos . txt
# endif
	while (resuelveCaso()) {} // Resolvemos todos los casos
# ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system(" PAUSE ");
# endif
	return 0;
}