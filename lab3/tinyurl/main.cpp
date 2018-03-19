//
// Created by Piotrek on 19.03.2018.
//

#include "TinyUrl.h"
int main() {

    std::array<char,6> *ptr = new std::array<char,6> ({'0', '0','0', '0','0','0'});
    NextHash(ptr);

    for (int i = 0; i < ptr->size(); ++i) {
        std::cout<<(*ptr)[i];
    }

    std::cout<<std::endl;

    std::string firstUrl = "www.abcd.com/bardzodobrylink";
    std::unique_ptr<TinyUrlCodec> ptr2 = Init();
    std::string tinyUrl = Encode(firstUrl, &ptr2);
    std::cout<<tinyUrl<<std::endl;
    std::string longUrl = Decode(ptr2,tinyUrl);
    std::cout<<longUrl<<std::endl;
    std::string secondUrl = "https://www.facebook.pl/123123";
    tinyUrl = Encode(secondUrl, &ptr2);
    std::cout<<tinyUrl<<std::endl;
    longUrl = Decode(ptr2, tinyUrl);
    std::cout<<longUrl<<std::endl;

    return 0;
}