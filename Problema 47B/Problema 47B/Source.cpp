#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
struct col {
	char azul = 'a';
	char rojo = 'r';
	char verde = 'v';
};
struct tSol {
	std::vector <char > sol;
};
// Escribe una solucion
void escribirSolucion(std::vector <char > const& v) {
	for (char c : v) {
		if (c == 'a') {
			std::cout << "azul ";
		}
		if (c == 'r') {
			std::cout << "rojo ";
		}
		if (c == 'v') {
			std::cout << "verde ";
		}
	}
	std::cout << '\n';
}
bool esValida(int tam, int k, int i, tSol& s, std::vector<char> colores) {
	
		if (s.sol[k-1] == 'v' && colores[i] == 'v') {
			return false;
		}
	return true;
}
void variaciones(int tam, int k, tSol& s, std::vector<char> colores) {
	
	for (char i = 0; i < 3; ++i) {
		
		if (esValida(tam, k, i, s, colores)) {
			s.sol[k] = colores[i];
			if (k == tam - 1) { // Es solucion
				escribirSolucion(s.sol);
			}
			if (k < tam - 1) { // Genera el resto de la solucion
				variaciones(tam, k + 1, s, colores);
			}
		}
		
		
		
	}
}
// Resuelve un caso de prueba , leyendo de la entrada la
// configuracion , y escribiendo la respuesta
bool resuelveCaso() {
	int m; std::cin >> m;
	if (m == 0) return false;
	tSol s;
	s.sol.resize(m);
	std::vector<char> colores;
	colores.push_back('a');
	colores.push_back('r');
	colores.push_back('v');
	s.sol[0] = 'r';
	if (s.sol.size() == 1) {
		std::cout << "rojo";
		std::cout << '\n';
	}
	else {
		variaciones(m, 1, s, colores);
	}
		std::cout << '\n';
	
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