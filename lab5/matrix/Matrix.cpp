//
// Created by walapiot on 27.03.18.
//
#include <string>
#include <complex>
#include "Matrix.h"

using algebra::Matrix;

Matrix::Matrix(int n, int m) {
    this->n = n;
    this->m = m;
    macierz = new complex<double>*[n];
    for (int i = 0; i < n; i++) {
        macierz[i] = new complex<double>[m];
    }
}
Matrix::Matrix() {

}

Matrix::Matrix(std::string){

}

Matrix::Matrix(Matrix &matrix){

}

Matrix::~Matrix(){

}
void Matrix::print(Matrix ){
    for (){

    }
}
add(Matrix &matrix) {

}

sub(Matrix &matrix) {

}