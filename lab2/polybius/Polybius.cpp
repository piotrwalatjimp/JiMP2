//
// Created by Piotrek on 12.03.2018.
//

//#include "Polybius.h"
//
//std::string PolybiusDecrypt(std::string message){
//
//    std::string answer = "";
//
//    std::string polybiusSquare[5][5];
//    int ascii = 0;
//    for(int i = 0; i<5; i++) {
//        for (int j = 0; j < 5; ++j) {
//            if (ascii == 9)
//                ascii++;
//            polybiusSquare[i][j] = 'a' + ascii;
//            ascii++;
//        }
//    }
//
//
//    for (int k = 0; k < message.length(); k+=2) {
//
//        int i = message[k] - '1';
//        int j = message[k+1] - '1';
//
//
//        answer += (polybiusSquare[i][j]);
//
//    }
//
//    return answer;
//}
//
//std::string PolybiusCrypt(std::string message) {
//
//    std::string answer = "";
//
//    for (auto x : message)
//    {
//        x = static_cast<char>(tolower(x));
//
//        if (int(x) != 32)
//        {
//            int c = int(x);
//            if (c >= 'J')
//            {
//                c--;
//            }
//
//            c -= 'A';
//            c++;
//            answer += std::to_string(int( (c-1)/5 +1));
//            answer += std::to_string(int(c-1)%5 + 1);
//
//        }
//
//
//    }
//
//    return answer;
//}
#include "Polybius.h"

const char polybius_tab[5][5] = {{'A', 'B', 'C', 'D', 'E'},
                                 {'F', 'G', 'H', 'I', 'K'},
                                 {'L', 'M', 'N', 'O', 'P'},
                                 {'Q', 'R', 'S', 'T', 'U'},
                                 {'V', 'W', 'X', 'Y', 'Z'}};
string PolybiusCrypt(string message)
{
    string encrypted;
    bool found;
    transform(message.begin(), message.end(),message.begin(), ::toupper);
    replace( message.begin(), message.end(), 'J', 'I');
    for(int i=0; i<message.length(); i++)
    {
        if(message[i] == ' ')
            continue;
        found = false;
        for(int row=0; row<5; row++)
        {
            for(int column=0; column<5; column++)
            {
                if(message[i] == polybius_tab[row][column])
                {
                    encrypted+=to_string(row+1)+to_string(column+1);
                    found = true;
                    break;
                }
            }
            if(found)
                break;
        }
    }
    return encrypted;
}

string PolybiusDecrypt(string crypted)
{
    int row, column;
    string decrypted;
    for(int i=0; i<crypted.length(); i+=2)
    {
        decrypted+=polybius_tab[(int)crypted[i]-48-1][(int)crypted[i+1]-48-1];
    }
    transform(decrypted.begin(), decrypted.end(),decrypted.begin(), ::tolower);
    return decrypted;
}