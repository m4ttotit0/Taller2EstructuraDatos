#include <iostream>
#include <ctime>
#include "SparseMatrix.h"
using namespace std;


int main() {
  SparseMatrix funciones;
 
  int menu=0;
 
  //Variables de tiempo
  std::clock_t inicio;
  std::clock_t fin;
  double tiempoTranscurrido;

 
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
       
       
        if (!(cin >> menu)) {
            cout << "Entrada inválida. Saliendo...\n";
            break;
        }

        switch (menu)
        {
        case 1: //agregar
          {
            int valor = 0;
            int posx = 0;
            int posy = 0;
           
            cout<< "\nIngrese un valor: ";
            if (!(cin >> valor)) break;
           
            // Validación
            cout<< "\nIngrese la posición x (fila): ";
            if (!(cin >> posx)) break;
            cout<< "\nIngrese la posición y (columna): ";
            if (!(cin >> posy)) break;
         
           
            inicio = std::clock();
         
            funciones.add(valor, posx, posy);
         
       
            fin = std::clock();
            tiempoTranscurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
            std::cout << "Tiempo de CPU consumido: " << tiempoTranscurrido << " segundos" << std::endl;
            break;}
        case 2: //obtener
          {
            int posx = 0;
            int posy = 0;
           
            // Revisar que sean datos válidos
            cout<< "\nIngrese la posición x (fila): ";
            if (!(cin >> posx)) break;
            cout<< "\nIngrese la posición y (columna): ";
            if (!(cin >> posy)) break;
         
            inicio = std::clock();
         
            int resultado = funciones.get(posx, posy);
            cout << "Valor en (" << posx << ", " << posy << "): " << resultado << endl;
         
            fin = std::clock();
            tiempoTranscurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
            std::cout << "Tiempo de CPU consumido: " << tiempoTranscurrido << " segundos" << std::endl;
            break;}
         
        case 3: //Eliminar
          {
            int posx = 0;
            int posy = 0;
           
           
            cout<< "\nIngrese la posición x (fila): ";
            if (!(cin >> posx)) break;
            cout<< "\nIngrese la posición y (columna): ";
            if (!(cin >> posy)) break;
         
            inicio = std::clock();
         
            funciones.remove(posx, posy);
         
            fin = std::clock();
            tiempoTranscurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
            std::cout << "Tiempo de CPU consumido: " << tiempoTranscurrido << " segundos" << std::endl;
            break;}
         
        case 4: //Imprimir
            {
            inicio = std::clock();
         
            funciones.printStoredValues();
         
            fin = std::clock();
            tiempoTranscurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
         
            std::cout << "Tiempo de CPU consumido: " << tiempoTranscurrido << " segundos" << std::endl;
            break;}
        case 5: //densidad
           {
            inicio = std::clock();
         
            double dens = funciones.density();
            cout << "La densidad de la matriz es: " << dens << "%" << endl;
         
            fin = std::clock();
            tiempoTranscurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
            std::cout << "Tiempo de CPU consumido: " << tiempoTranscurrido << " segundos" << std::endl;
              break;}
           
        case 6:{
                cout << "\n--- MULTIPLICACIÓN DE MATRICES ---\n";

                SparseMatrix B;
                B.add(2, 0, 0); // Datos de ejemplo para la Matriz B
                B.add(3, 1, 1);
                B.add(1, 0, 2);

                inicio = std::clock();

                SparseMatrix* C = funciones.multiply(&B);

                fin = std::clock();
                tiempoTranscurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;

                if (C != nullptr) {
                    cout << "\nResultado de la Matriz C = A * B:" << endl;
                    C->printStoredValues();
                    delete C;
                }
                std::cout << "Tiempo de CPU consumido: " << tiempoTranscurrido << " segundos" << std::endl;
                break;}
           
        case 9:
        {
          cout << "Saliendo...\n";
            break;}
        default:
        {
            cout << "Ingrese una opcion valida\n";
            break;}
        }
    }
 
  return 0;
}
