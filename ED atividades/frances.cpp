#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main(){
    string texto;
    string texto2;
    string texto3;
    int tam;

    getline(cin,texto);
    tam=texto.size();

    for(int i=0; i < tam ;i++ ){
        if(texto[i]=='a' || texto[i]=='e' ||texto[i]=='i' || texto[i] =='o' || texto[i] == 'u'){
            if(texto[i+1] == ' ' && texto[i+2] == texto[i]){
                int igual = i+3;
                while(texto[i]==texto[igual]||texto[igual] ==' '){
                    igual++;
                }
             texto2=texto.substr(0,i+1);
             texto3=texto.substr(igual,tam);
             texto=texto2+texto3;
            }
        }
            
    }

    cout << texto << endl;      

    
    







    //string texto2{texto, 8};
    
    //string texto3{texto,0,6};
     

    //cout << texto3<< endl;





}