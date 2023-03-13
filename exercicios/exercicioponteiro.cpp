#include <iostream>
using namespace std;

struct Ponto{
    double x;
    double y;
};


void troca(Ponto *p1, Ponto *p2){
    Ponto aux = *p1;
    *p1=*p2;
    *p2= aux;


    /*r=p1->x;
    p1->x = p2->x;
    p2->x = r;
    r=p1->y;
    p1->y = p2->y;
    p2->y = r;
    */

}


void dobraPonto(Ponto *p){
    p->x *= 2;
    p->y *= 2;
}

int main(){
    Ponto p1{5,4.3}, p2{6.6,4};
   

    troca(&p1,&p2);

    cout << "(" << p1.x << " , " << p1.y  << ")"<< endl;
    cout <<  "( " << p2.x << " , " << p2.y << ")"<< endl;
    dobraPonto(&p1);
    cout << "(" << p1.x << " , " << p1.y  << ")"<< endl;
}