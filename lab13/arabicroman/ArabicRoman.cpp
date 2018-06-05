//
// Created by walapiot on 05.06.18.
//
#include <string>
#include <map>
#include "ArabicRoman.h"

using namespace std;

string ArabicToRoman(int n){
    string result;
    map<char, int> roman;
    roman['I']=1;
    roman['V']=5;
    roman['X']=10;
    roman['L']=50;
    roman['C']=100;
    roman['D']=500;
    roman['M']=1000;

    if(n<=0)
        throw runtime_error("error");
    if(n>3999)
        throw runtime_error("error2");
    else
    {

    }


}