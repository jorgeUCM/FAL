#include <iostream>
#include <fstream>
#include <vector>

// Funcion que resuelve el problema
int resolver(std::vector <int> const& valla, int metrosTela) {
	// Inicializar los valores con el primer intervalo
	int cont = 0; // Numero de metros que hay que arreglar en un intervalo
	int pos = 0; // posicion donde hay que empezar a arreglar
	bool aux = true; // para que guarde la primera posicion
	int max = 0; // maximo intervalo de metros de valla a arreglar

	for (int i = 0; i < metrosTela; ++i) { // Primer intervalo de la valla.
		if (valla[i] == 0) {
			++cont;
		}
		max = cont;
	}

	for (int j = metrosTela; j < valla.size(); ++j) { // avanza el intervalo una posicion
	// Elimina un metro de la valla
		if (valla[j - metrosTela] == 0) --cont;
		// Anade un metro de la valla
		if (valla[j] == 0) ++cont;

		if (cont == max) {
			pos = j - metrosTela + 1;
		}
		else if (cont > max) {
			max = cont;
			pos = j - metrosTela + 1;
		}
	}
	if (max == 0){
		pos = -1;
	}
	return pos;
}
// Resuelve un caso de prueba , leyendo de la entrada la
// configuracion , y escribiendo la respuesta
bool resuelveCaso() {
	
	int metrosValla, metrosTela;
	std::cin >> metrosValla;
	if (metrosValla == 0) return false;
	std::vector<int> valla(metrosValla);
	std::cin >> metrosTela;
	for (int& i : valla) std::cin >> i;
	int pos = resolver(valla, metrosTela);
	if (pos == -1) {
		std::cout << "No hace falta" << '\n';
	}
	else {
		std::cout << pos << '\n';
	}
	return true;
}
int main() {
	// Para la entrada por fichero .
# ifndef DOMJUDGE
	std::ifstream in("Texto.txt ");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
# endif
	// Entrada con centinela
	while (resuelveCaso())
		;
	// Para restablecer entrada .
# ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system(" PAUSE ");
# endif
	return 0;
}