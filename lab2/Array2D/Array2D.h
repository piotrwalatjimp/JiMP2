//
// Created by walapiot on 06.03.18.
//

#ifndef JIMP_EXERCISES_ARRAY2D_H
#define JIMP_EXERCISES_ARRAY2D_H
#include <iostream>
using namespace std;

int FillArray2D(int rows, int cols, int *const *array);
void DeleteArray2D(int **array, int n_rows, int n_columns);
int ** NewArray2D (int rows, int cols);


#endif //JIMP_EXERCISES_ARRAY2D_H
