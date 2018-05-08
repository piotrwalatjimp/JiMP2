//
// Created by Piotrek on 12.03.2018.
//


#include "Polybius.h"
using namespace std;
int main()
{
    string word, code;
    cin>>word;
    code=PolybiusCrypt(word);
    cout<<code<<endl;
    word=PolybiusDecrypt(code);
    cout<<word
    return 0;
}