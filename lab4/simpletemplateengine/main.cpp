//
// Created by Piotrek on 25.03.2018.
//

#include "SimpleTemplateEngine.h"
#include <iostream>
#include <string>
#include <unordered_map>
using namespace nets;
using namespace std;

int main(){
    View view = View::View("Test {{test}} {{injected}}");
    cout<<view.GetText()<<endl;
    cout<<view.Render({{"test", "{{injected}}"}, {"injected", "{{test}}"}});
}