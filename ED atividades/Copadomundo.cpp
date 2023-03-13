#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <stdexcept>
using namespace std;


int main(){
    queue <char> times;
    queue <char> aux;
    int gol1,gol2;
    for(int i = 'A'; i <= 'P'; i++){
        times.push(i);
    }

    while(!times.empty()){  
            string resultado;
            getline(cin,resultado);
            stringstream ss{resultado};
            ss >> gol1 >> gol2;
            if(gol1 > gol2){
                aux.push(times.front());
                times.pop();
                times.pop();
            }
            else{
                times.pop();
                aux.push(times.front());
                times.pop();
            }
        
    }

    while(!aux.empty()){
            string resultado;
            getline(cin,resultado);
            stringstream ss{resultado};
            ss >> gol1 >> gol2;
            if(gol1 > gol2){
                times.push(aux.front());
                aux.pop();
                aux.pop();
            }
            else{
                aux.pop();
                times.push(aux.front());
                aux.pop();
            }
    }

    while(!times.empty()){  
            string resultado;
            getline(cin,resultado);
            stringstream ss{resultado};
            ss >> gol1 >> gol2;
            if(gol1 > gol2){
                aux.push(times.front());
                times.pop();
                times.pop();
            }
            else{
                times.pop();
                aux.push(times.front());
                times.pop();
            }
        
    }
     while(!aux.empty()){
            string resultado;
            getline(cin,resultado);
            stringstream ss{resultado};
            ss >> gol1 >> gol2;
            if(gol1 > gol2){
                times.push(aux.front());
                aux.pop();
                aux.pop();
            }
            else{
                aux.pop();
                times.push(aux.front());
                aux.pop();
            }
    }
    cout << times.front() << endl;
    times.pop();

}