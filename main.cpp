#include <iostream>
#include <ctime>
using namespace std;
SparseMatrix funciones;

int main() {
  std::clock_t inicio = std::clock();
  //llamar las disntintas funciones e ir agregando los datos
  std::clock_t fin = std::clock();
  double tiempoTranscurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
  std::cout << "Tiempo de CPU consumido: " << tiempoTranscurrido << " segundos" << std::endl;
  
  return 0;
}
