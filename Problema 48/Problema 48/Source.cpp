#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
struct tDatos {
	std::vector <int > tiposAbrigos;
	std::vector <int > probPrecipitacion;
};
bool es_valida(int k, int i, tDatos const& d, std::vector <int> const& sol,
	std::vector <int> const& marcas) {
	// El abrigo soporta la cantidad de lluvia que va a caer
	if (d.tiposAbrigos[i] < d.probPrecipitacion[k]) return false;
	// No llevo dos dias seguidos el mismo abrigo
	if (k > 0 && sol[k] == sol[k - 1]) return false;
	// No me pongo un abrigo muchos mas dias que otro
	if (marcas[i] > k / 3 + 2) return false;
	return true;
}
// d - datos entrada . probabilidad precipitacion y lluvia que aguanta cada abrigo .
// k - etapa
// sol - abrigo que me pondre cada dia.
// marcas : dias que me he puesto cada abrigo .
int abrigos(tDatos const& d, int k, std::vector <int>& sol, std::vector <int>& marcas) {
	int numSoluciones = 0; // numero de soluciones diferentes encontradas
	for (int i = 0; i < d.tiposAbrigos.size(); ++i) {
		sol[k] = i;
		// marcar
		++marcas[i];
		if (es_valida(k, i, d, sol, marcas)) { // es valida
			if (k == d.probPrecipitacion.size() - 1) { // es solucion
				if (sol[0] != sol[k]) { // El primer abrigo no coincide con el ultimo
					++numSoluciones;
					// Para escribir las soluciones cuando se pidan
					// for ( int x : sol) std :: cout << x << ’ ’;
					// std :: cout << ’\n ’;
				}
			}
			else {
				numSoluciones += abrigos(d, k + 1, sol, marcas);
			}
		}
		// desmarcar
		
			--marcas[i];
	}
	return numSoluciones;
}
// Resuelve un caso de prueba , leyendo de la entrada la
// configuracion , y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numDias, numAbrigos;
	std::cin >> numDias;
	if (numDias == 0) return false;
	std::cin >> numAbrigos;
	// leer probabilidad de precipitacion
	tDatos d;
	d.probPrecipitacion.resize(numDias);
	for (int& i : d.probPrecipitacion) std::cin >> i;
	// leer caracteristicas de los abrigos
	d.tiposAbrigos.resize(numAbrigos);
	for (int& i : d.tiposAbrigos) std::cin >> i;
	// Declaracion de tipos para llamar a la funcion
	int k = 0;
	std::vector <int > sol(numDias);
	std::vector <int > marcas(numAbrigos);
	int numSoluciones = abrigos(d, k, sol, marcas);
	// Escribir resultado
	if (numSoluciones == 0) std::cout << "Lo puedes comprar \n";
	else std::cout << numSoluciones << "\n";
	return true;
}
int main() {
# ifndef DOMJUDGE
	std::ifstream in("Texto.txt ");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std :: cin to casos . txt
# endif
	while (resuelveCaso()) {} // Resolvemos todos los casos
# ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system(" PAUSE ");
# endif
	return 0;
}
