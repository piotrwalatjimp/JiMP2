//
// Created by walapiot on 06.03.18.
//
#include "Array2D.h"

int **NewArray2D(int rows, int cols)
{

    int ** array = new int*[rows];
    for(int j=0; j< cols; j++)
        array[j] = new int[cols];
}
int **Array2D(int rows, int cols)
{

    int integer = 1;
    int ** array = NewArray2D(rows,cols);

    for(int i=0; i<rows; i++){
        for(int j=0;j<cols;j++){
            array[i][j]= integer;
            integer+=1;
        }
    }
    return array;
}

void DeleteArray2D(int **array, int n_rows, int n_columns);