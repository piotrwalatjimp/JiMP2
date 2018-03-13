//
// Created by Piotrek on 12.03.2018.
//

#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H

#include <string>
#include <vector>

std::string XorCypherBreaker(const std::vector<char> &cryptogram, int key_length, const std::vector<std::string> &dictionary);
std::string XorCypher(const std::vector<char> &cryptogram, int key_length, std::string key);
std::string generateNextKey(std::string previous_key);


#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
