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
        Matrix(Matrix &matrix);
        ~Matrix();
        void print(const Matrix);
        void add(const Matrix &other);
        void sub(const Matrix &other);
        void mul(const Matrix &other);
        void div(const Matrix &other);
        void pow(const Matrix &other);
    };
}

#endif //JIMP_EXERCISES_MATRIX_H

