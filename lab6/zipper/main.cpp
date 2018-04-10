//
// Created by walapiot on 10.04.18.
//

#include "Zipper.h"


int foo(const vector<string> &v1, const vector<int> &v2) {
    for (const pair<string,int> &p : Zipper::zip(v1,v2)) {
        if (p.first == "elo") {
            return p.second+4;
        }
    }
    return 0;
}