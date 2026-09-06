#include <stdio.h>

#define MAX_TERMS 100

typedef struct {
    int row;
    int col;
    int value;
} Element;

typedef struct {
    Element data[MAX_TERMS];
    int rows;
    int cols;
    int terms;
} SparseMatrix;