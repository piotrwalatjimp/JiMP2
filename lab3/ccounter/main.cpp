//
// Created by Piotrek on 19.03.2018.
//

#include "CCounter.h"



int main()
{
    std::unique_ptr<ccounter::Counter> c = ccounter::Init();
    ccounter::Inc("v", &c);
}