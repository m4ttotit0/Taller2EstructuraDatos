#include "SparseMatrix.h"
#include <iostream>

using namespace std;

SparseMatrix::SparseMatrix() : rowHeads(nullptr), colHeads(nullptr), maxRow(0), maxCol(0), count(0) {}

SparseMatrix::~SparseMatrix() {
    NodeHead* currentRowHead = rowHeads;
    while (currentRowHead != nullptr) {
        Node* current = currentRowHead->first;
        while (current != nullptr) {
            Node* next = current->nextRow;
            delete current;
            count--;
            current = next;
        }
        currentRowHead = currentRowHead->next;
    }

    NodeHead* currentHead = rowHeads;
    while (currentHead != nullptr) {
        NodeHead* nextHead = currentHead->next;
        delete currentHead;
        currentHead = nextHead;
    }

    currentHead = colHeads;
    while (currentHead != nullptr) {
        NodeHead* nextHead = currentHead->next;
        delete currentHead;
        currentHead = nextHead;
    }
}

NodeHead* SparseMatrix::findOrCreateHead(NodeHead*& headList, int index, int& maxDim) {
    NodeHead* current = headList;
    NodeHead* prev = nullptr;

    while (current != nullptr && current->index < index) {
        prev = current;
        current = current->next;
    }

    if (current != nullptr && current->index == index) {
        return current;
    }

    NodeHead* newHead = new NodeHead(index);
    if (prev == nullptr) {
        newHead->next = headList;
        headList = newHead;
    } else {
        newHead->next = current;
        prev->next = newHead;
    }

    if (index > maxDim) {
        maxDim = index;
    }

    return newHead;
}

NodeHead* SparseMatrix::findHead(NodeHead* headList, int index) {
    NodeHead* current = headList;
    while (current != nullptr && current->index < index) {
        current = current->next;
    }
    if (current != nullptr && current->index == index) {
        return current;
    }
    return nullptr;
}

void SparseMatrix::add(int value, int xPos, int yPos)
{
    if (value == 0) {
        remove(xPos, yPos);
        return;
    }

    NodeHead* rowH = findOrCreateHead(rowHeads, xPos, maxRow);
    NodeHead* colH = findOrCreateHead(colHeads, yPos, maxCol);
    
    Node* currentR = rowH->first;
    Node* prevR = nullptr;

    Node* currentC = colH->first;
    Node* prevC = nullptr;

    while (currentR != nullptr && currentR->yPos < yPos) {
        prevR = currentR;
        currentR = currentR->nextRow;
    }

    if (currentR != nullptr && currentR->yPos == yPos) {
        currentR->value = value;
        return;
    }

    Node *newNode = new Node(value, xPos, yPos);
    count++;

    if (prevR == nullptr) {
        newNode->nextRow = rowH->first;
        rowH->first = newNode;
    } else {
        newNode->nextRow = prevR->nextRow;
        prevR->nextRow = newNode;
    }
    
    while (currentC != nullptr && currentC->xPos < xPos) {
        prevC = currentC;
        currentC = currentC->nextCol;
    }
    
    if (prevC == nullptr) {
        newNode->nextCol = colH->first;
        colH->first = newNode;
    } else {
        newNode->nextCol = prevC->nextCol;
        prevC->nextCol = newNode;
    }
}

int SparseMatrix::get(int xPos, int yPos)
{
    NodeHead* rowH = findHead(rowHeads, xPos);
    if (rowH == nullptr) return 0; 


    Node *current = rowH->first;
    while (current != nullptr)
    {
        if (current->yPos == yPos)
            return current->value;

        if (current->yPos > yPos) 
            break; 
        current = current->nextRow;
    }
    return 0;
}


void SparseMatrix::remove(int xPos, int yPos)
{

    NodeHead* rowH = findHead(rowHeads, xPos);
    NodeHead* colH = findHead(colHeads, yPos);

    if (rowH == nullptr || colH == nullptr) return; 
    
    Node *currentR = rowH->first;
    Node *prevR = nullptr;
    while (currentR != nullptr && currentR->yPos < yPos) {
        prevR = currentR;
        currentR = currentR->nextRow;
    }
    
    if (currentR == nullptr || currentR->yPos != yPos) 
        return; 

    Node *currentC = colH->first;
    Node *prevC = nullptr;
    while (currentC != nullptr && currentC->xPos < xPos) {
        prevC = currentC;
        currentC = currentC->nextCol;
    }
    
    if (currentC == nullptr || currentC->xPos != xPos)
        return;

    if (prevR == nullptr) {
        rowH->first = currentR->nextRow;
    } else {
        prevR->nextRow = currentR->nextRow;
    }

    if (prevC == nullptr) {
        colH->first = currentC->nextCol;
    } else {
        prevC->nextCol = currentC->nextCol;
    }

    delete currentR;
    count--;

}

void SparseMatrix::printStoredValues() {
    NodeHead *currentRowHead = rowHeads;
    
    while (currentRowHead != nullptr)
    {
        Node *current = currentRowHead->first;
        while (current != nullptr)
        {
            cout << "(" << current->xPos << ", " << current->yPos << ") --> "
                 << current->value << endl;
            current = current->nextRow;
        }
        currentRowHead = currentRowHead->next;
    }
}


double SparseMatrix::density() {
    int totalCells = (maxRow + 1) * (maxCol + 1);
    if (totalCells == 0)
        return 0.0;
    return ((double)count * 100.0) / totalCells;
}


SparseMatrix* SparseMatrix::multiply(SparseMatrix* second) {
    if (maxCol != second->getRowCount()) {
        return nullptr;
    }

    SparseMatrix* result = new SparseMatrix();

    NodeHead* rowA = rowHeads;
    while (rowA != nullptr) {
        int i = rowA->index;

        NodeHead* colB = second->colHeads;
        while (colB != nullptr) {
            int j = colB->index;
            
            int sum = 0;
            
            Node* currentA = rowA->first;
            Node* currentB = colB->first;
             
            while (currentA != nullptr && currentB != nullptr) {
                
                int kA = currentA->yPos;
                int kB = currentB->xPos;

                if (kA == kB) {
                    sum += currentA->value * currentB->value;
                    currentA = currentA->nextRow;
                    currentB = currentB->nextCol;
                } else if (kA < kB) {
                    currentA = currentA->nextRow;
                } else { 
                    currentB = currentB->nextCol;
                }
            }
            
            if (sum != 0) {
                result->add(sum, i, j);
            }
            
            colB = colB->next;
        }
        rowA = rowA->next;
    }

    return result;
}
