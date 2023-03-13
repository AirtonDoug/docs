#include <iostream>
#include <string>

using namespace std;
/*void splitstr(string str, string deli = " ")
{
    int start = 0;
    int end = str.find(deli);
    while (end != -1) {
        tempstr = str.substr(start, end - start);
        start = end + deli.size();
        end = str.find(deli, start);
    }
    cout << str.substr(start, end - start);
}*/

int main(){
    string str;
    string tempstr;
    string aux[10];
    bool ordenado;
    int j=0;
    getline(cin,str);

    str+=" ";
    for(int i=0;i<(int)str.length();i++){
        if(str[i]!=' '){
            tempstr+=str[i];
        }else if(str[i]==' ' || str[i] == '\0'){
            aux[j]=tempstr;
            j++;
            tempstr.clear();
        }

    }
    
    for(int i =0;i<j-1;i++){
    if(aux[i]<= aux[i+1])
        ordenado = true;
    else{
        ordenado = false;
        break;
    }    
    }


    if(ordenado == true)
        cout << "sim" << endl;
    else
        cout << "nao" << endl;
}