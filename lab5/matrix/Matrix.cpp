//
// Created by walapiot on 27.03.18.
//

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

//Matrix::Matrix(std::string){
//
//}
//
//Matrix::Matrix(Matrix &matrix){
//
//}
//
//Matrix::~Matrix(){
//
//}
//void Matrix::print(Matrix ){
//    for (){
//
//    }
//}
//add(Matrix &matrix) {
//
//}
//
//sub(Matrix &matrix) {
//
//}


Matrix::Matrix(Matrix &matrix) {
    n = matrix.n;
    m = matrix.m;
    macierz = new complex<double>*[n];
    for (int i = 0; i < n; i++){
        macierz[i] = new complex<double>[m];
        for (int x = 0; x < m; x++) {
            macierz[i][x] = matrix.macierz[i][x];
        }
    }
}

Matrix::Matrix() {
    //
}

Matrix::~Matrix() {
    for (int i = 0; i < n; i++) {
        delete [] macierz[i];
    }
    delete [] macierz;
}

Matrix::Matrix(std::string matlabowy) {
    int n = 1, m = 1;
    string::size_type size_w;
    string wartosc = "", wartosc_r = "", wartosc_i = "";
    double wartosc_double, wartosc_r_double, wartosc_i_double;

    for (string::iterator it = matlabowy.begin(); it != matlabowy.end(); it++) {
        if (*it == 32) {
            m++;
        }
        if (*it == 59) {
            n++;
        }
    }

    m = m / n;
    this->n = n;
    this->m = m;

    macierz = new complex<double>*[n];

    for (int i = 0; i < n; ++i) {
        macierz[i] = new complex<double>[m];
    }

    int i = 0, j = 0;

    for (string::iterator it = matlabowy.begin(); it != matlabowy.end(); it++) {
        if ((*it <= 57 && *it >= 48) ||  *it == 105 || *it == 46) {
            wartosc += *it;
        } else if (*it == ' ' || *it == ']') {
            if (wartosc.find("i") != string::npos) {
                wartosc_r = wartosc.substr(0, wartosc.find("i"));
                wartosc_i = wartosc.substr(wartosc.find("i") + 1, wartosc.length() - wartosc.find("i"));

                wartosc_r_double = stod(wartosc_r, &size_w);
                wartosc_i_double = stod(wartosc_i, &size_w);

                macierz[i][j] = complex<double>(wartosc_r_double, wartosc_i_double);

                j++;
                wartosc = "";
                wartosc_r = "";
                wartosc_i = "";
            } else {
                wartosc_double = stod(wartosc, &size_w);
                macierz[i][j] = complex<double>(wartosc_double);

                j++;
                wartosc = "";
            }
        } else if (*it == 59) {
            if (wartosc.find("i") != string::npos) {
                wartosc_r = wartosc.substr(0, wartosc.find("i"));
                wartosc_i = wartosc.substr(wartosc.find("i") + 1, wartosc.length() - wartosc.find("i"));

                wartosc_r_double = stod(wartosc_r, &size_w);
                wartosc_i_double = stod(wartosc_i, &size_w);

                macierz[i][j] = complex<double>(wartosc_r_double, wartosc_i_double);

                i++;
                j = 0;
                wartosc = "";
                wartosc_r = "";
                wartosc_i = "";
            } else {
                wartosc_double = stod(wartosc, &size_w);
                macierz[i][j] = complex<double>(wartosc_double);

                i++;
                j = 0;
                wartosc = "";
            }
            *it++;
        }
    }
}

string Matrix::Print() {
    string liczba;
    liczba += "[";

    for (int o = 0; o < n; o++) {
        for (int p = 0; p < m; p++) {
            string data = to_string(macierz[o][p].real());

            for (int j = 0; j < data.length(); j++){
                bool slice = true;
                for (int k = data.length() - 1; k >= j; k -= 1){
                    if (data[k] != '0'){
                        slice = false;
                    }
                }
                if (slice){
                    data = data.substr(0, j);
                    break;
                }
            }

            if (data[data.length() - 1] == '.'){
                data = data.substr(0, data.length() - 1);
            }

            liczba += data;

            if (macierz[o][p].imag() != 0) {
                string data2 = to_string(macierz[o][p].imag());
                for (int j = 0; j < data2.length(); j++){
                    bool slice = true;
                    for (int k = data2.length() - 1; k >= j; k -= 1){
                        if (data2[k] != '0'){
                            slice = false;
                        }
                    }
                    if (slice) {
                        data2 = data2.substr(0, j);
                        break;
                    }
                }

                if (data2[data2.length() - 1] == '.') {
                    data2 = data2.substr(0, data2.length() - 1);
                }

                liczba += "i" + data2;
            } else {
                liczba += "i0";
            }
            liczba += ", ";
        }
        liczba = liczba.substr(0, liczba.length() - 2);
        liczba += "; ";
    }

    liczba = liczba.substr(0, liczba.length() - 2);
    liczba += "]";

    return liczba;
}

Matrix Matrix::Add(Matrix matrix) {
    if (m != matrix.getWidth() || n != matrix.getHeight()) {
        throw "Cannot add matrices of different sizes!";
    }

    Matrix result(matrix.getHeight(), matrix.getWidth());

    for (int o = 0; o < n; o++) {
        for (int p = 0; p < m; p++) {
            result.getMatrix()[o][p] = macierz[o][p] + matrix.getMatrix()[o][p];
        }
    }

    return result;
}

Matrix Matrix::Mul(Matrix matrix) {
    if (n != matrix.getWidth()) {
        throw "Cannot multiply matrices when the first matrix has different height than second has width!";
    }

    Matrix result(n, matrix.getWidth());

    for (int o = 0; o < n; o++) {
        for (int p = 0; p < matrix.getWidth(); p++) {
            result.getMatrix()[o][p] = 0;
            for (int k = 0; k < matrix.getHeight(); k++) {
                result.getMatrix()[o][p] += macierz[o][k] * matrix.getMatrix()[k][p];
            }
        }
    }

    return result;
}

Matrix Matrix::Mul(complex<double> number) {
    Matrix result(n, m);

    for (int o = 0; o < n; o++) {
        for (int p = 0; p < m; p++) {
            result.getMatrix()[o][p] = macierz[o][p] * number;
        }
    }

    return result;
}

complex<double> ** Matrix::getMatrix() {
    return macierz;
}

int Matrix::getHeight() {
    return n;
}

int Matrix::getWidth() {
    return m;
}

pair<size_t, size_t> Matrix::Size() {
    return pair<size_t, size_t>(n, m);
}

Matrix::Matrix(std::initializer_list<std::vector<std::complex<double>>> matrix_list) {
    int num_row = int(matrix_list.size());

    unsigned long num_col =0;

    for (auto row : matrix_list) {
        num_col = row.size();
        break;
    }

    n = int(num_col);
    m = num_row;

    std::complex<double> ** tablica = new std::complex<double>*[m];
    for (int i=0; i< m; i++) {
        tablica[i] = new std::complex<double>[n];
    }

    macierz = tablica;
    macierz[0][0] = 1.0 + 1.0i;

    int i = 0;
    int j = 0;

    for (std::vector<std::complex<double>> row : matrix_list) {
        j = 0;
        for (std::complex<double> element : row) {
            macierz[i][j] = element;
            j++;
        }
        i++;
    }
}

Matrix Matrix::Pow(int number) {
    Matrix result = *this;

    for (int i = 1; i < number; i++) {
        result = result.Mul(*this);
    }

    return result;
}

Matrix Matrix::Sub(Matrix matrix) {
    if (m != matrix.getWidth() || n != matrix.getHeight()) {
        throw "Cannot add matrices of different sizes!";
    }

    Matrix result(matrix.getHeight(), matrix.getWidth());

    for (int o = 0; o < n; o++) {
        for (int p = 0; p < m; p++) {
            result.getMatrix()[o][p] = macierz[o][p] - matrix.getMatrix()[o][p];
        }
    }

    return result;
}