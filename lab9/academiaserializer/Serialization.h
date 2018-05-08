//
// Created by walapiot on 08.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#endif //JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <memory>
#include <iostream>
#include <vector>

using std::vector;
using std::string;
using namespace std;

namespace academia {


    class Serializable;

    class Serializer {
    public:

        Serializer(ostream *out);

        void IntegerField(const std::string &field_name, int value) {}

        void DoubleField(const std::string &field_name, double value) {}

        void StringField(const std::string &field_name, const std::string &value) {}

        void BooleanField(const std::string &field_name, bool value) {}

        void SerializableField(const std::string &field_name, const academia::Serializable &value) {}

        void ArrayField(const std::string &field_name,
                        const vector <reference_wrapper<const academia::Serializable>> &value) {}

        void Header(const std::string &object_name) {}

        void Footer(const std::string &object_name) {}
    };

    class Serializable{
    public:
        void Serialize(Serializer *s);
    };

    class Room : public Serializable {
    public:
        enum class Type{
            COMPUTER_LAB,
        };
    private:
        int no_;
        string name_;
        Type type_;



    };

}