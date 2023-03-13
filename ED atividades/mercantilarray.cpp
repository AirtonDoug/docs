#include <iostream>
#include <limits>
using namespace std;

int main(){
    int n;
    float produtos[50];
    float chute1[50];
    char chute2[50];
    int acerto1 = 0;
    int acerto2 = 0;
    cin >> n;

    cin.ignore(numeric_limits<streamsize>:: max(), '\n');//ignora um numero especifico do buffer
    for(int i=0;i<n;i++)
        cin >> produtos[i];
    for(int i=0;i<n;i++)
        cin >> chute1[i];
    for(int i=0;i<n;i++)
        cin >> chute2[i];
    
        
    for(int i = 0;i<n;i++){
        if(chute2[i]=='m'){
            if(chute1[i] <= produtos[i])
                acerto1++;
            else
                acerto2++;    
        }else if(chute2[i]=='M'){
            if(chute1[i]>= produtos[i])
                acerto1++;
            else
                acerto2++;    
        }

    }
    if(acerto1>acerto2)
        cout << "primeiro" << endl;
    if(acerto1<acerto2)
        cout << "segundo" << endl;
    if(acerto1==acerto2)
        cout << "empate" << endl;    


}