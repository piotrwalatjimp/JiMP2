//
// Created by walapiot on 06.03.18.
//
#include "Array2D.h"


int ** NewArray2D(int rows, int cols) {

    if (rows <= 0 || cols <= 0)
        return nullptr;

    int ** array = new int*[rows];
    for(int j = 0; j < rows; j++)
        array[j] = new int[cols];
    FillArray2D(rows, cols, array);
    return array;
}

int FillArray2D(int rows, int cols, int *const *array) {

    int integer = 1;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            array[i][j] = integer;
            integer ++;
        }
    }
}


void DeleteArray2D(int **array, int rows, int cols) {
    for (int i = 0; i < rows ; i++) {
        delete array[i];
    }
    delete array;
}
