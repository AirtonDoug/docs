#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main (){
    string str;
    string tempstr;
    string aux[20];
    int j =0;

    getline(cin,str);

    str+=" ";

    for(int i=0;i<(int)str.size();i++){
        if(str[i]!=' '){
            tempstr+=str[i];
        }else if(str[i]==' '){
            aux[j]=tempstr;
            j++;
            tempstr.clear();
        }
    }

    for(int i=0;i < j;i++){
        bool punct=false;
        bool num=false;
        bool alpha=false;
        bool neg=false;
        for(int k=0; k < (int)aux[i].size();k++){
            
            if(ispunct(aux[i][k]) ){
               if(aux[i][k]=='-'){
                    neg = true;
               }else{
                punct = true;
               }
            }
               
             if(isdigit(aux[i][k]) ){
                num=true;
             }
               
            if(isalpha(aux[i][k])){
                alpha = true;
                
            }
        
        }
        if(alpha==true)
            cout << "str ";
        if((num==true && alpha == false && punct == false && neg == false) || (num==true && alpha == false && punct == false && neg == true))
            cout <<  "int ";
        if((punct == true && alpha == false && neg == false) || (punct == true && alpha == false && neg == true))
            cout << "float ";    
    }
}