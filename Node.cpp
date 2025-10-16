#include <iostream>
#include "Node.h"
using namespace std;

Node::Node(int val, int x, int y) : value(val), xPos(x), yPos(y), nextRow(nullptr), nextCol(nullptr) {}

Node::~Node() {}
