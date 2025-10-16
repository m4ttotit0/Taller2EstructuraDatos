#include "SparseMatrix.h"
#include <iostream>
using namespace std;

SparseMatrix::SparseMatrix() : start(nullptr), maxRow(0), maxCol(0), count(0) {}

SparseMatrix::~SparseMatrix() {}
