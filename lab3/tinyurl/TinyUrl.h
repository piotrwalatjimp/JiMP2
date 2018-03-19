//
// Created by Piotrek on 19.03.2018.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H

#include <iostream>
#include <memory>
#include <array>
#include <utility>

struct TinyUrlCodec{
    std::array<char,6> array = {'0', '0','0', '0','0','0'};
    std::array<std::string,2> tinyAndLong;
};

std::unique_ptr<TinyUrlCodec> Init();
void NextHash(std::array<char, 6> *state);
std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);
std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);

#endif //JIMP_EXERCISES_TINYURL_H