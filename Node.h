#pragma once

class Node {
public:
  int value;
  int xPos;
  int yPos;

  Node* nextRow;
  Node* nextCol;

  Node(int val, int x, int y);
  ~Node();
};

