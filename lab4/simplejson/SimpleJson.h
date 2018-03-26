//
// Created by Piotrek on 24.03.2018.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <vector>
#include <map>
#include <iostream>

using std::string;
using std::map;
using std::vector;
using std::experimental::optional;
//using ::std::literals::operator""s;

namespace nets {
    class JsonValue {
    protected:
        map<string, JsonValue> m_json;
        optional<int> i_json;
        optional<double> d_json;
        optional<bool> b_json;
        optional<string> s_json;
        optional<vector<JsonValue>> v_json;

    public:
        JsonValue(map<string, JsonValue> _value);
        JsonValue(int _value);
        JsonValue(double _value);
        JsonValue(bool _value);
        JsonValue(string _value);
        JsonValue(vector<JsonValue> _value);
        ~JsonValue();

        optional<JsonValue> ValueByName(const string &name) const;
        string ToString() const;
    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
