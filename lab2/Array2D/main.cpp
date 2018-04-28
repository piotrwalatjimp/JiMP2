//
// Created by walapiot on 06.03.18.
//
#include <iostream>
#include "Array2D.h"

//int a=5;
//int b=7;
int main() {
    cin>>a>>b;
    int ** tab;
    FillArray2D(a,b);

    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            std::cout<<tab[i][j]<<std::endl;

        }
    }

    DeleteArray2D(tab, a, b);

    return 0;
}