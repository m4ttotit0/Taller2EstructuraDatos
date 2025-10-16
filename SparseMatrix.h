#pragma once
#include "Node.h"
class SparseMatrix {
  private:
  Node* start;
  public:
    SparseMatrix();
    void add(int valor, int posX, int posY);
    int get(int posX, int posY);
    void remove(int posX, int posY);
    void printStoredValues();
    int density();  
    SparseMatrix* multiply(SparseMatrix* second);

    ~SparseMatrix();
};
