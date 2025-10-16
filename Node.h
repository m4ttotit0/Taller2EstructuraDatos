#pragma once

class Node {
public:
  int valor;
  int posX;
  int posY;

  Node* nextRow;
  Node* nextCol;

  Node(int val, int x, int y);
  ~Node();
};

