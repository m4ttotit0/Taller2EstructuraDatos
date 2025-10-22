#include <iostream>
#include <ctime>
using namespace std;

int main() {
  SparseMatrix funciones; //Creo la variable referente a la clase SparseMatrix.cpp (I hope so)
  
  int menu=0;
  while (menu != 9)
    {
        cout << "========================\n";
        cout << "1.- Gestión de alumnos\n";
        cout << "2.- Gestión de cursos\n";
        cout << "3.- Inscripción de cursos\n";
        cout << "4.- Gestión de notas\n";
        cout << "5.- Reportes\n";
        cout << "9.- Salir\n";
        cout << "========================\n";
        cout << "Ingrese una opción: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            Caso1();
            break;
        case 2:
            Caso2();
            break;
        case 3:
  
  /*std::clock_t inicio = std::clock();
  //llamar las disntintas funciones e ir agregando los datos
  funciones.add(50, 0, 0);
  
  std::clock_t fin = std::clock();
  double tiempoTranscurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
  std::cout << "Tiempo de CPU consumido: " << tiempoTranscurrido << " segundos" << std::endl;
    */
  
  return 0;
}
