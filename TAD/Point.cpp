#include "Point.h"
#include <iostream>

 double Point::distancia(const Point& p){
        double dx = (p.x - this->x) * (p.x - this->x);
        double dy = (p.y - this->y) * (p.y - this->y);
        return sqrt(dx+dy);
    }
    void Point::setX(double x){
        this->x = x;
    }
    void Point::setY(double y){
        this->y = y;
    }

     double Point::getY(){
        return y;
   }
   double Point::getX(){
        return x;
   }