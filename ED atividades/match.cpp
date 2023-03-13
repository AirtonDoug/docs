#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
using namespace std;


 /*vector<string> ler_vec(int n){
    vector<string> vec;
    string str{};
    char after{};
    cin >> noskipws;
    int i=0;
    while(i<n){
	    getline(cin,str);
	    vec.push_back(str);
        cin.ignore(numeric_limits<streamsize>:: max(), '\n');
	    cin >> after;
	    if(after == '\n' || cin.eof())
		    break;
        i++;    
}
return vec;    

}

 */

    vector <int> matchingStrings(vector <string> search , vector <string> consult){
        vector <int> aux;
        for(int i=0; i < (int)search.size();i++){
            aux.push_back(0);
        }
        for(int i = 0;i<(int)search.size();i++){
            for(int j=0;j<(int)consult.size();j++){
                if(search[i]==consult[j])
                aux[i]++;
            }
        } 
        return aux; 
    }




int main(){
    vector <string> consult;
    vector <string> busca;
    vector <int> result;
    int n1,n2;
    string line;
    string word;

    cin >> n1;
    cin.ignore(numeric_limits<streamsize>:: max(), '\n');
    getline(cin, line);

    stringstream ss{line};
    for(int i=0;i<n1;i++){
        ss >> word;
        consult.push_back(word);
    }
    line.clear();

    cin >> n2;
    cin.ignore(numeric_limits<streamsize>:: max(), '\n');
    getline(cin, line);

    stringstream ss1{line};
    for(int i=0;i<n2;i++){
        ss1 >> word;
        busca.push_back(word);
    }

     result = matchingStrings(busca, consult);
    
    for(int i = 0; i < (int)result.size();i++){
       cout << result[i];
       if(i < (int)result.size()-1)
        cout << " ";
    }

    cout << endl;
    
       
    

}