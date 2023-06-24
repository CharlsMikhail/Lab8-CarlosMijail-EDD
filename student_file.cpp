//Estudiante: Carlos Mijail Mamani Anccasi
#include <iostream>
#include <vector>

using namespace std;

vector<int> Torneo(vector<int> habilidades, int N, int K) {
  int ganadorActual = 0;
  int numGanados = 0;
  int juegoActual = 1;
  vector<int> mesa(habilidades.begin(), habilidades.begin() + 2);
  habilidades.erase(habilidades.begin(), habilidades.begin() + 2);
  while (juegoActual <= K) {
    if (mesa[0] > mesa[1]) { // Corregido: El jugador con mayor habilidad gana
      ganadorActual = 0;
      numGanados++;
    } else {
      ganadorActual = 1;
      numGanados = 0;
    }

    if (numGanados == N) {
      habilidades.push_back(habilidades[ganadorActual]);
      habilidades.erase(habilidades.begin() + ganadorActual);
      numGanados = 0;
    }

    if (habilidades.size() < 2) {
      habilidades.push_back(habilidades[0]);
      habilidades.erase(habilidades.begin());
    }

    juegoActual++;
  }

  if (numGanados >= K) {
    habilidades.push_back(habilidades[ganadorActual]);
    habilidades.erase(habilidades.begin() + ganadorActual);
  }

  vector<int> resultado;
  resultado.push_back(habilidades[1 - ganadorActual]);
  resultado.push_back(habilidades[ganadorActual]);
  return resultado;
}

int main() {

	// Ejemplo
	vector<int> habilidades4 = {30, 12};
	int N4 = 34;
	int K4 = 80;
	vector<int> resultado4 = Torneo(habilidades4, N4, K4);
	cout << "{";
	for (int i = 0; i < resultado4.size(); i++) {
		cout << resultado4[i];
		if (i < resultado4.size() - 1)
			cout << ", ";
	}
	cout << "}" << endl;

	return 0;
}