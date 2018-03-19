//
// Created by Piotrek on 19.03.2018.
//

#include "CCounter.h"


namespace ccounter
{
    std::unique_ptr<Counter> Init(){
        return std::make_unique<Counter>();
    }

    void Inc(std::string key, std::unique_ptr<Counter> *counter) {
        auto it = counter->get()->values.find(key);
        if(it != counter->get()->values.end())
            (*it).second++;
        else
            counter->get()->values.insert(std::make_pair(key,1));
    }

    int Counts(const std::unique_ptr<Counter> &counter, std::string key) {
        auto it = counter->values.find(key);
        if(it == counter->values.end())
            return 0;
        else return (*it).second;
    }

    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter) {
        auto it = counter->get()->values.find(key);
        if( it != counter->get()->values.end())
            (*it).second = value;

    }
}