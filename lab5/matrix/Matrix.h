//
// Created by walapiot on 27.03.18.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <complex>
#include <vector>

using namespace std;

namespace algebra {
    class Matrix {
        complex<double> ** macierz;
        int n;
        int m;

    public:
        Matrix(int, int);
        Matrix();
        Matrix(std::string);
        Matrix(std::initializer_list<std::vector<std::complex<double>>> matrix_list);
        Matrix(Matrix &matrix);
        ~Matrix();
        pair<size_t, size_t> Size();
        Matrix Add(Matrix matrix);
        Matrix Sub(Matrix matrix);
        Matrix Mul(Matrix matrix);
//        Matrix Mul(complex<double> number);
        Matrix Pow(int number);
        int getWidth();
        int getHeight();
        complex<double> ** getMatrix();
        std::string Print();
    };
}

#endif //JIMP_EXERCISES_MATRIX_H

