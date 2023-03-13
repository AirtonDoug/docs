#include <iostream>
#include <string>
#include <cctype>
#include <limits>
using namespace std;

int main (){
    string str;
    string tempstr;
    string aux[100];
    char op;
    int j =0;

    getline(cin,str);
    str+=" ";
    cin >> op;
    int MAX=str.size();

    for(int i=0;i<MAX;i++){
        if(str[i]!=' '){
            tempstr+=str[i];
        }else if(str[i]==' '){
            aux[j]=tempstr;
            j++;
            tempstr.clear();
        }
    }
    

    for(int i=0;i < j;i++){
            int max = aux[i].size();
        for(int k=0; k < max ;k++){
            
            switch(op){
                case 'M':
                    aux[i][k] = toupper(aux[i][k]);
                    break;
                case 'm':
                    aux[i][k] = tolower(aux[i][k]);
                    break;
                case 'i':
                    if(isupper(aux[i][k])>0)
                        aux[i][k] = tolower(aux[i][k]);
                    else if(islower(aux[i][k])>0)
                       aux[i][k] = toupper(aux[i][k]);  
                                break;
                 case 'p':
                    if((k==0 && k < max-1)){
                        if(islower(aux[i][0])>0)
                       aux[i][0] = toupper(aux[i][0]); 
                    
                    }else if(max == 1)
                        aux[i][0] = tolower(aux[i][0]);
                                break;                                  
            }
        
        }
      
    }
    for(int i = 0;i < j;i++){
       cout << aux[i];
       if(i<j-1)
       cout << " ";
    }
}