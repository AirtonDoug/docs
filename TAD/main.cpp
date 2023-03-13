#include <iostream>
#include "Point.h"
using namespace std;

int main(){
    Point p1;
    Point p2{ 6,7 };
    Point p3{ 9999, 3333};
    Point *ptr = new Point(9,9);

    p1.setX(2.0);
    p1.setY(3.0);
    p1.print();
    p2.print();
    p3.print();
    ptr->print();
    cout << p1.distancia(p2) << endl;
    cout << p1.distancia(p2) << endl;
    delete ptr;
    
}