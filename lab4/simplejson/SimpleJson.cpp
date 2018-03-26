//
// Created by Piotrek on 24.03.2018.
//

#include "SimpleJson.h"


using nets::JsonValue;
using std::to_string;
using ::std::literals::operator""s;

JsonValue::~JsonValue(){
    m_json.clear();
}

JsonValue::JsonValue(map<string, JsonValue> _value) {
    m_json = _value;
}

JsonValue::JsonValue(int _value) {
    i_json = _value;
}

JsonValue::JsonValue(double _value) {
    d_json = _value;
}

JsonValue::JsonValue(bool _value) {
    b_json = _value;
}

JsonValue::JsonValue(string _value) {
    string cos = _value;
    for (int k=0;k < cos.length();k++){
        if (cos[k]=='\"' || cos[k]=='\\'){
            cos.insert(k, 1,'\\');
            k++;
        }
    }
    s_json=cos;
}

JsonValue::JsonValue(vector<JsonValue> _value) {
    v_json = _value;
}

optional<JsonValue> JsonValue::ValueByName(const string &name) const {
    for (auto &n : this->m_json) {
        if (n.first==name){
            return n.second;
        }
    }
}

string JsonValue::ToString() const {
    if (s_json) {
        string cos = *s_json;
        return cos ;
    }
    else if (d_json) {
        string data_json =  std::to_string(*d_json);
        for(int j=0;j<data_json.length();j++) {
            bool slice = true;
            for (int k = data_json.length() - 1; k >= j; k -= 1) {
                if (data_json[k] != '0') { slice = false; }
            }
            if (slice) {
                data_json = data_json.substr(0, j);
                break;
            }
        }
        return data_json;
    }
    else if (i_json) {
        return std::to_string(*i_json);
    }
    else if (b_json) {
        if (*b_json == false){
            return "false";
        }
        else if (*b_json == true){
            return "true";
        }
    }
    else if (v_json) {
        string data_json = "[";
        for (auto &n : *v_json) {
            data_json = data_json+", "+n.ToString();
        }
        data_json += "]";
        data_json = data_json.substr(2);
        data_json[0]='[';
        return data_json;
    }
    else if (&m_json != nullptr) {
        string data_json = "{";
        for (auto &n : this -> m_json) {
            string cos = n.first;
            for (int i=0;i<cos.length();i++){
                if (cos[i]=='\"' || cos[i]=='\\'){
                    cos.insert(i, 1,'\\');
                    i++;
                }
            }
            data_json = data_json + "\""+ cos +"\": "+n.second.ToString()+", ";
        }
        data_json[data_json.size()-2]='}';
        data_json.pop_back();
        return data_json;
    }
}