//
// Created by walapiot on 24.04.18.
//

#include "Pesel.h"

namespace academia {
    Pesel::Pesel(string new_pesel) {
        if((int)new_pesel.size() !=11)
            throw InvalidPeselLength("Nieodpowiednia długość");

        for(auto &i : new_pesel)
            if(i <48 && i>57)
                throw InvalidPeselCharacter("Nieodpowiedni znak");

//        int suma;
//        int tab[9, 7, 5, 3, 9, 7, 5, 3, 9, 7];
//        for(int k=0; k<10; k++)
//        {
//            suma+=(new_pesel[k]-'0')*tab[k];
//
//        }
//        if(suma%10 != new_pesel[11])
//            throw InvalidPeselChecksum("Zła suma kontrolna");

        this->pesel = new_pesel;
    }

    InvalidPeselChecksum::InvalidPeselChecksum(const string &__arg) : invalid_argument(__arg) {}

    InvalidPeselCharacter::InvalidPeselCharacter(const string &__arg) : invalid_argument(__arg) {}


    AcademiaDataValidationError::AcademiaDataValidationError() {}

    InvalidPeselLength::InvalidPeselLength(const string &__arg) : invalid_argument(__arg) {}
}