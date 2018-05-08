//
// Created by Piotrek on 09.04.2018.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <vector>

using std::experimental::string_view;


namespace pool {
    class TextPool {
    protected:
        std::set<const string_view> tekst;

    public:
        //Rule of Five (bez możliwości kopiowania)
        TextPool(TextPool &&cos);
        TextPool &operator=(TextPool &&cos);
        ~TextPool();
        TextPool();
        TextPool(const std::initializer_list<const std::string> &elements);
        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;


    };
}
#endif //JIMP_EXERCISES_TEXTPOOL_H
