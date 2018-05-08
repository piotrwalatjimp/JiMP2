//
// Created by Piotrek on 28.04.2018.
//

#include <iostream>
#include "ArrayFill.h"
using namespace arrays;

int main(){
    std::vector<int> vs;
    IncrementalFill uniform {3, 5};
    FillArray(35, uniform, &vs);

    for(auto v : vs){
        std::cout << v << "  ";
    }

    std::vector<int> vs1;
    UniformFill uniform1 {5};
    FillArray(35, uniform1, &vs);

    for(auto v : vs){
        std::cout << v << "  ";
    }

    std::vector<int> vs2;
    SquaredFill uniform2 {5};
    FillArray(35, uniform2, &vs);

    for(auto v : vs){
        std::cout << v << "  ";
    }

}