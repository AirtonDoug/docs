#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cmath>
class Point{
private:
    double x{0.0};
    double y{0.0};
public:
    //Construtor com dois argumentos
    Point(double x, double y){
        this->x = x;
        this->y = y;
        std::cout << "construtor com dois argumentos foi invocado" << std::endl;
    } 
    //Construtor padrão
    Point(){
        std::cout << "construtor padrão foi invocado" << std::endl;
    }
    //Construtor de cópia
    Point(const Point& point){
        this->x = point.x;
        this->y = point.y;
    } 
    void print(){
        std::cout << "(" << x << "," << y << ")" << std::endl;
    }
    //Destrutor
    ~Point(){
        std::cout<< "(" << x << "," << y << ") foi liberado" << std::endl;

    }
    //getters: retornam o valor da coordenada x e y
   double getY();
        
   
   double getX();
       
   
    //setters: mudam os valors das coordenadas

    void setX(double x);
    
    void setY(double y);
    
    //retorna distancia entre dois pontos
    double distancia(const Point& p);
        
    
};

#endif