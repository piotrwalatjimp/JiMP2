//
// Created by Piotrek on 19.03.2018.
//

#include "TinyUrl.h"

std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {

    NextHash(&(codec->get()->array));
    std::string tinyUrl = "";
    for(int i = 0; i < 6; i++)
        tinyUrl += codec->get()->array[i];
    codec->get()->tinyAndLong[0] = tinyUrl;
    codec->get()->tinyAndLong[1] = url;

    return tinyUrl;
}

std::unique_ptr<TinyUrlCodec> Init() {
    std::unique_ptr<TinyUrlCodec> ptr = std::make_unique<TinyUrlCodec>();
    return ptr;
}

void NextHash(std::array<char, 6> *state) {
    int elementAdress = 5;
    int type;
    bool toChange = true;
    while(toChange) {
        type = (int)(*state)[elementAdress];
        if (type == 57) {
            (*state)[elementAdress] = 'a';
            toChange = false;
        } else if(type == 90) {
            (*state)[elementAdress] = 'A';
            toChange = false;
        } else if(type == 122) {
            (*state)[elementAdress] = '0';
            elementAdress--;
        } else {
            type++;
            (*state)[elementAdress] = (char)type;
            toChange = false;
        }
    }

}

std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {

    if(hash == codec->tinyAndLong[0])
        return codec->tinyAndLong[1];
    else return "Not found";
}