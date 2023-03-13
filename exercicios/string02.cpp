#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;

    cin.ignore(numeric_limits<streamsize>:: max(), '\n');
    for(int teste=1; teste<=n; teste++){
        string line;
        getline(cin, line);

        for(int i=1;i<(int)line.size();i++){
            if(line[i-1]!= ' ' && islower(line[i-1])){
                line[i] = toupper(line[i]);
            }else if(line[i-1] != ' '&& isupper(line[i-1])){
                line[i] = tolower(line[i]);
            }
            else if(line[i-1]==' '){
                if(islower(line[i-2])){
                    line[i] = toupper(line[i]);
                }else{
                    line[i] = tolower(line[i]);
                }
            }
            
        }
        cout << line << endl;

    }

}