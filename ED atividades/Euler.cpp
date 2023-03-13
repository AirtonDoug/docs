#include <iostream>
#include <iomanip>
using namespace std;

double fatorial(double n){

    if(n==0 || n==1)
        return 1;

    
    else{
        for(double i=(n-1);i > 0;i--)
            
            n=n*i;       
    
    return n;
}
}

void euler(double n){
    double E=1;
    

    for(double i=1;i<=n;i++){
        E+=(1/fatorial(i));
    }
    cout << fixed << setprecision(6) <<  E << endl;


}


int main(){
    double n;

    cin >> n;

    euler(n);

    




}
