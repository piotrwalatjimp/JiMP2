//
// Created by walapiot on 06.03.18.
//
#include "Array2D.h"


int ** NewArray(int rows, int cols) {

    if (rows <= 0 || cols <= 0)
        return nullptr;

    int ** array = new int*[rows];
    for(int j = 0; j < rows; j++)
        array[j] = new int[cols];

    return array;
}

int ** Array2D(int rows, int cols) {

    int integer = 1;
    int ** array = NewArray(rows, cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            array[i][j] = integer;
            integer ++;
        }
    }

    return array;
}

//int ** NewArray2D(int rows, int cols) {
//
//    if (rows <= 0 || cols <= 0)
//        return nullptr;
//
//    int ** array = new int*[rows];
//    for(int j = 0; j < rows; j++)
//        array[j] = new int[cols];
//
//    return array;
//}

void DeleteArray2D(int **array, int rows, int cols) {
    for (int i = 0; i < rows ; i++) {
        delete array[i];
    }
    delete array;
}

//void ArrayFilling2D(int k_rows, int k_cols, int **to_fill) {
//    int number = 1;
//
//    for (int i = 0; i < k_rows; ++i) {
//
//        for (int j = 0; j < k_cols; ++j) {
//
//            to_fill[i][j] = number;
//            number++;
//
//        }
//
//    }
//
//}