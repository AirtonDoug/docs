#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    float A, B, C;
    float delta;
    cin >> A >> B >> C;

    delta = (B*B) - (4 * A * C);

    if(delta > 0){
        cout << "duas raizes" << endl;
        float x1,x2;
        x1= ((-B) + sqrt(delta))/(2*A);
        x2= ((-B) - sqrt(delta))/(2*A);

        cout << x1 << endl;
        cout << x2 << endl;

    }else if(delta == 0){
        cout << "uma raiz" << endl;
        float x;
        x = (-B) / (2*A);
        cout << fixed << setprecision(2) << x << endl;
    }else{
        cout << "sem raizes" << endl;

        cout << "nao ha raiz real" << endl;
    }





}