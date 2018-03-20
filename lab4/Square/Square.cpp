//
// Created by walapiot on 20.03.18.
//

#include "Square.h"

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;


double Point::Distance(const Point &other) const{
    return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
}

void Point::ToString(ostream *out) const{
    (*out) << "(" << GetX() << ";" << GetY() << ")";
}

void Point::SetX(double x){
    x_=x;
}
void Point::SetY(double y){
    y_=y;
}

double Point::GetX() const{
    return x_;

}
double Point::GetY() const{
    return y_;

}

double Square::Circumference();
double Square::Area();

