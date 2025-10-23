#pragma once
#include "Node.h"

struct NodeHead {
    int index;
    Node* first;
    NodeHead* next;
    
    NodeHead(int idx) : index(idx), first(nullptr), next(nullptr) {}
};

class SparseMatrix {
private:
    NodeHead* rowHeads;
    NodeHead* colHeads;
    int maxRow;
    int maxCol;
    int count;
    NodeHead* findOrCreateHead(NodeHead*& headList, int index, int& maxDim);
    NodeHead* findHead(NodeHead* headList, int index);
    
public:
    SparseMatrix();
    void add(int value, int xPos, int yPos);
    int get(int xPos, int yPos);
    void remove(int xPos, int yPos);
    void printStoredValues();
    int density();  
    SparseMatrix* multiply(SparseMatrix* second);

    int getElement(int xPos, int yPos);
    int getRowCount() const { return maxRow; }
    int getColCount() const { return maxCol; }

    ~SparseMatrix();
};
