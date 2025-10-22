#include <iostream>
#include <ctime>
#include "SparseMatrix.h"
using namespace std;

int main() {
  SparseMatrix funciones; //Creo la variable referente a la clase SparseMatrix.cpp (I hope so)
  
  int menu=0;
  while (menu != 9)
    {
        cout << "========================\n";
        cout << "1.- Añadir nuevo nodo\n";
        cout << "2.- Obtener un valor\n";
        cout << "3.- Eliminar un nodo\n";
        cout << "4.- Imprimir valores\n";
        cout << "5.- Calcular la densidad\n";
        cout << "6.- Multiplicar la matriz\n";
        cout << "9.- Salir\n";
        cout << "========================\n";
        cout << "Ingrese una opción: ";
        cin >> menu;

        switch (menu)
        {
        case 1: //agregar
          {
            int valor = 0;
            int posx = 0;
            int posy = 0;
            cout<< "\nIngrese un valor: ";
            cin >> valor;
            cout<< "\nIngrese la posición x: ";
            cin >> posx;
            cout<< "\nIngrese la posición y: ";
            cin >> posy;
          
            std::clock_t inicio = std::clock();
          
            funciones.add(valor, posx, posy);
          
            std::clock_t fin = std::clock();
            double tiempoTranscurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
            std::cout << "Tiempo de CPU consumido: " << tiempoTranscurrido << " segundos" << std::endl;
          }
            break;
        case 2: //obtener
            int posx = 0;
            int posy = 0;
            cout<< "\nIngrese la posición x: ";
            cin >> posx;
            cout<< "\nIngrese la posición y:  ";
            cin >> posy;
          
            std::clock_t inicio = std::clock();
          
            funciones.get(posx, posy);
          
            std::clock_t fin = std::clock();
            double tiempoTranscurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
            std::cout << "Tiempo de CPU consumido: " << tiempoTranscurrido << " segundos" << std::endl;
            break;
        case 3: //Eliminar
            int posx = 0;
            int posy = 0;
            cout<< "\nIngrese la posición x: ";
            cin >> posx;
            cout<< "\nIngrese la posición y:  ";
            cin >> posy;
          
            std::clock_t inicio = std::clock();
          
            funciones.remove(posx, posy);
          
            std::clock_t fin = std::clock();
            double tiempoTranscurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
            std::cout << "Tiempo de CPU consumido: " << tiempoTranscurrido << " segundos" << std::endl;
            break;
          
        case 4: //Imprimir
            std::clock_t inicio = std::clock();
          
            funciones.printStoredValues();
          
            std::clock_t fin = std::clock();
            double tiempoTranscurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
            std::cout << "Tiempo de CPU consumido: " << tiempoTranscurrido << " segundos" << std::endl;
          
            break;
        case 5: //densidad
            std::clock_t inicio = std::clock();
          
            funciones.density();
          
            std::clock_t fin = std::clock();
            double tiempoTranscurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
            std::cout << "Tiempo de CPU consumido: " << tiempoTranscurrido << " segundos" << std::endl;
          
            break;
        case 6: //multiplicación
            break;
        case 9:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Ingrese una opcion valida\n";
            break;
        }
    }
  
  return 0;
}
