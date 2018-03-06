//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"


bool OutOfRange(int value);

int Zmiana(int value) {
//  if (value<0){
//    return 0;
//  }
//  else
  if (OutOfRange(value))
  {
    return 0;
  }
  else if (value==0) {
    return 1;
  }
  else if (value>0){
    return value * Zmiana(value - 1);
  }
  else if (value<0){
    return value * Zmiana(value + 1);
  }
}

bool OutOfRange(int value) { return value > 12 || value < -12; }

