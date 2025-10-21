#include "SparseMatrix.h"
#include <iostream>
using namespace std;

SparseMatrix::SparseMatrix() : start(nullptr), maxRow(0), maxCol(0), count(0) {}

SparseMatrix::~SparseMatrix() {}

void SparseMatrix::add(int value, int xPos, int yPos)
{
    if (value == 0)
        return;

    Node *newNode = new Node(value, xPos, yPos);

    // Si es que no hay nodo, sera el inicial
    if (start == nullptr)
    {
        start = newNode;
        count++;
        if (xPos > maxRow)
            maxRow = xPos;
        if (yPos > maxCol)
            maxCol = yPos;
        return;
    }

    // Se busca la posicion (x,y)
    Node *current = start;
    Node *prev = nullptr;

    while (current != nullptr &&
           (current->xPos < xPos ||
            (current->xPos == xPos && current->yPos < yPos)))
    {
        prev = current;
        current = current->nextCol; // recorremos en x
    }

    // Actualizamos el nodo si es que existe
    if (current != nullptr && current->xPos == xPos && current->yPos == yPos)
    {
        current->value = value;
        return;
    }

    // Insertamos el nuevo nodo
    if (prev == nullptr)
    {
        newNode->nextCol = start;
        start = newNode;
    }
    else
    {
        newNode->nextCol = prev->nextCol;
        prev->nextCol = newNode;
    }

    count++;
    if (xPos > maxRow)
        maxRow = xPos;
    if (yPos > maxCol)
        maxCol = yPos;
}

void SparseMatrix::remove(int xPos, int yPos)
{
    if (start == nullptr)
        return;

    Node *current = start;
    Node *prev = nullptr;

    while (current != nullptr &&
           (current->xPos != xPos || current->yPos != yPos))
    {
        prev = current;
        current = current->nextCol;
    }

    // Retorna si no encuentra resultado
    if (current == nullptr)
        return;

    // Si es el primero
    if (prev == nullptr)
    {
        start = current->nextCol;
    }
    else
    {
        prev->nextCol = current->nextCol;
    }

    delete current;
    count--;
}

int SparseMatrix::get(int xPos, int yPos)
{
    Node *current = start;
    while (current != nullptr)
    {
        if (current->xPos == xPos && current->yPos == yPos)
            return current->value;
        current = current->nextCol;
    }
    return 0; // Si no existe retornamos 0
}

void SparseMatrix::printStoredValues()
{
    Node *current = start;
    while (current != nullptr)
    {
        cout << "(" << current->xPos << ", " << current->yPos << ") --> "
             << current->value << endl;
        current = current->nextCol;
    }
}
int SparseMatrix::density()
{

    int totalCells = (maxRow + 1) * (maxCol + 1);
    if (totalCells == 0)
        return 0;
    return (count * 100) / totalCells;
    // En pocas palabras sacamos el porcentaje de numeros existentes en el total
}
