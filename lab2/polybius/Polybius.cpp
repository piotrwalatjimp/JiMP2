//
// Created by Piotrek on 12.03.2018.
//

#include "Polybius.h"

std::string PolybiusDecrypt(std::string message){

    std::string answer = "";

    std::string polybiusSquare[5][5];
    int ascii = 0;
    for(int i = 0; i<5; i++) {
        for (int j = 0; j < 5; ++j) {
            if (ascii == 9)
                ascii++;
            polybiusSquare[i][j] = 'a' + ascii;
            ascii++;
        }
    }


    for (int k = 0; k < message.length(); k+=2) {

        int i = message[k] - '1';
        int j = message[k+1] - '1';


        answer += (polybiusSquare[i][j]);

    }

    return answer;
}

std::string PolybiusCrypt(std::string message) {

    std::string answer = "";

    for (auto x : message)
    {
        x = static_cast<char>(tolower(x));

        if (int(x) != 32)
        {
            int c = int(x);
            if (c >= 'J')
            {
                c--;
            }

            c -= 'A';
            c++;
            answer += std::to_string(int( (c-1)/5 +1));
            answer += std::to_string(int(c-1)%5 + 1);

        }


    }

    return answer;
}