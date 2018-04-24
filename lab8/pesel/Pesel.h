//
// Created by walapiot on 24.04.18.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <stdexcept>
#include <string>

using std::string;

namespace academia {

    class Pesel{
    public:
        Pesel (string new_pesel);

    private:
        string pesel;
    };


    class InvalidPeselLength : public std::invalid_argument{
    public:
        InvalidPeselLength(const string &__arg);
    };


    class InvalidPeselCharacter : public std::invalid_argument{
    public:
        InvalidPeselCharacter(const string &__arg);

    };


    class InvalidPeselChecksum : public std::invalid_argument{

    public:
        InvalidPeselChecksum(const string &__arg);

    };


    class AcademiaDataValidationError{
    public:
        AcademiaDataValidationError();

    };
}
#endif //JIMP_EXERCISES_PESEL_H
