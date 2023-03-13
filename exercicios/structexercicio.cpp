#include <iostream>
#include <cmath>
using namespace std;

struct Ponto{
    double x{0.0};
    double y{0.0};
};

double distance(Ponto P, Ponto Q){
    double dx = pow((P.x - Q.x),2);
    double dy = pow((P.y - Q.y),2);
    double resultado = sqrt(dx + dy);
    return resultado;
}


int main(){
    Ponto p,origem;

    cout << "Forneca as coordenadas do ponto p: ";
    cin >> p.x >> p.y;

    cout<< "Distancia do ponto p para a origem: "
        << distance(p,origem) << endl;

}