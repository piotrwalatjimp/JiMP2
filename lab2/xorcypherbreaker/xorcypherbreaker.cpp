//
// Created by Piotrek on 12.03.2018.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include "xorcypherbreaker.h"

std::string
XorCypherBreaker(const std::vector<char> &cryptogram, int key_length, const std::vector<std::string> &dictionary) {

    std::string key = "";

    for (int i = 0; i < key_length; ++i) {
        key += "a";
    }

    int max_matches = 0;
    std::string best_key;
    std::string decrypted;



    while (generateNextKey(key)[0] <= 'z')
    {
        key = generateNextKey(key);

        decrypted = XorCypher(cryptogram, key_length, key);

        int matches = 0;


        auto start = 0U;
        auto end = decrypted.find(' ');
        while (end != std::string::npos)
        {
            std::string token = decrypted.substr(start, end - start);
            start = end + 1;
            end = decrypted.find(' ', start);

            if (find(dictionary.begin(),dictionary.end(),token) != dictionary.end()) {
                matches++;
            }


        }

        if(matches > max_matches)
        {
            max_matches = matches;
            best_key = key;
        }


    }



    return best_key;
}

std::string XorCypher(const std::vector<char> &message, int key_length, std::string key) {

    std::string cryptogram;
    int i = 0;
    for( auto c : message)
    {
        char character = c ^ key[i];
        cryptogram += character;
        i = (i+1) % key_length;
    }


    return cryptogram;

}

std::string generateNextKey(std::string previous_key) {

    std::string key = previous_key;
    key[key.length() - 1] = char( int(key[key.length() - 1]) + 1 );

    for (int i = (previous_key.length() - 1); i >= 0; --i) {

        if ((int(key[i]) > 'z') && i != 0)
        {
            key[i-1] = char( int(key[i-1])+1 );
            key[i] = char( (int(key[i]) - 'a') % 26 + 'a' );

        }
    }



    return key;
}
