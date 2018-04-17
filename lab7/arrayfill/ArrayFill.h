//
// Created by walapiot on 17.04.18.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H
#include <vector>;
namespace arrays {

    class Base{
    public:
        virtual int get_value(size index) const;
    };

    class UniformFill:public Base {
    public:
        int get_value(size index) const;
    private:
        int default_value = 0;

    };

    class IncrementalFill:public Base{
    public:
        int get_value(size index) const;
    private:
        int step=1;
        int start_value=1;
    };

    class SquaredFill: public Base{
    public:
        int get_value(size index) const;
    private:
        int a=2;
        int b=1;
    };
}
#endif //JIMP_EXERCISES_ARRAYFILL_H
