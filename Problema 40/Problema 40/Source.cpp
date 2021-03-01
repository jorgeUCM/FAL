#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int resolver(std::vector <int> const& v, int ini, int fin, int num) {

	if (ini == fin) {
		if (v[ini] == num)
			return 1;
		else {
			return 0;
		}
	}
	else {
		int medio = (ini + fin) / 2;

		if (v[medio] == num) {
			return 1;
		}
		else {
			if (v[medio] > v[ini]) { //Parte izquierda ordenada
				if (v[medio] > num && v[ini] <= num) {//El numero esta en la parte izquierda
					return resolver(v, ini, medio, num);
				}
				else {//El numero esta en la parte derecha
					return resolver(v, medio + 1, fin, num);
				}
			}
			else {//parte derecha ordenada
				if (v[medio] < num && v[fin] >= num) {//El numero esta en la parte derecha
					return resolver(v, medio + 1, fin, num);
				}
				else {//El numero esta en la parte izquierda
					return resolver(v, ini, medio, num);
				}
			}
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam, num;
	std::cin >> tam >> num;
	if (tam == -1)
		return false;

	std::vector <int> v(tam);
	for (int i = 0; i < tam; i++) {
		std::cin >> v[i];
	}
	if (tam == 0) { // caso base de vector vacío
	std::cout << "NO" << "\n";
	}
	else {
		int sol = resolver(v, 0, tam - 1, num);
		if (sol == 1)
			std::cout << "SI" << "\n";
		else
			std::cout << "NO" << "\n";
	}
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