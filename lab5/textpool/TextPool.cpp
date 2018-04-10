//
// Created by Piotrek on 09.04.2018.
//

#include "TextPool.h"
#include <iostream>
#include <set>
using pool::TextPool;


//Rule of Five (z usuniętą możliwością kopiowania)


TextPool::TextPool(TextPool &&cos){
    swap(tekst,cos.tekst);

}

TextPool & TextPool::operator=(TextPool &&cos){
    if (this == &cos) {
        return cos;
    }
    tekst.clear();
    swap(tekst,cos.tekst);
    return *this;

}

TextPool::~TextPool(){
    tekst.clear();
}

TextPool::TextPool(){}

TextPool::TextPool(const std::initializer_list<const std::string> &elements){

    for (auto i=elements.begin(); i!=elements.end(); i++) {
        tekst.emplace(*i);
    }
}

std::experimental::string_view TextPool::Intern(const std::string &str){
    bool flag = true;
    for (auto &n : this->tekst) {
        if (n == str){
            flag = false;
            return n;
        }
    }
    if (flag){
        tekst.emplace(str);
        return Intern(str);
    }
}

size_t TextPool::StoredStringCount() const{
    size_t size = 0;
    for (auto &n : this->tekst) {
        size+=1;
    }
    return size;
}