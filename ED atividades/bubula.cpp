#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isvowel(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
        return true;
    }else{
        return false;
    }
}

void print_Silaba(string s){
    int i=0;
    while(i<(int)s.size()){
        if((int)s.size() > 3){
        if(isvowel(s[i]) == false && isvowel(s[i+1]) == true && i==0 && isvowel(s[i+2]) == false){
            cout << s[i] << s[i+1]
                 << s[i] << s[i+1]
                 << s[i] << s[i+1];
                 i=i+2;
        }else if(isvowel (s[i]) == true && isvowel(s[i+1])== false && i==0){
            cout << s[i]
                 << s[i]
                 << s[i];
                 i++;
        }else if((i==0 && isvowel(s[i]) == false && isvowel(s[i+1]) == true && isvowel(s[i+2]) == true && s[i+3]!=' ')  || (i==0 && isvowel(s[i]) == false && isvowel(s[i+1]) == false && isvowel(s[i+2]) == true && isvowel(s[i+3]) == false)){
             cout << s[i] << s[i+1] << s[i+2]
                 << s[i] << s[i+1]  << s[i+2]
                 << s[i] << s[i+1]  << s[i+2];
            i=i+3;
        }
    }
        cout << s[i];
        i++;
    }


}

int main (){
    string str;
    string tempstr;
    string aux[200];
    int j =0;

    getline(cin,str);

    str+=" ";




for(int i=0;i<(int)str.size();i++){
            if(i<(int)str.size()-1)
            tempstr+=str[i];
         if(str[i]==' '){
            aux[j]=tempstr;
            j++;
            tempstr.clear();
        }
    }


for(int i=0;i<j;i++){
        print_Silaba(aux[i]);
    }


   


}