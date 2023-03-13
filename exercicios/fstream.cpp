
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main () {
    ifstream arquivo;
    string linha;
    //string str;
    int numl,numc;
    double v;
    stringstream ss;
    arquivo.open("Teste1.txt");
    if(arquivo.is_open()){
        getline(arquivo,linha);
        ss << linha;
        ss >> numl >> numc;
         cout << numl << " " << numc << endl;
        while(getline(arquivo,linha)){
            ss << linha;
            ss >> numl >> numc;
            ss >> v;
             cout << numl << " " << numc << " " << v << endl;
        }
    }


}