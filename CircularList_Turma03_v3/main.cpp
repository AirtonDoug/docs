#include <iostream>
#include "CircularList.h"
using namespace std;

void print(const CircularList& lst) {
    for(int i = 0; i < lst.size(); ++i)
        cout << lst[i] << " ";
    cout << endl;
}

int main() {
    CircularList lst;

    for(int i = 1; i <= 9; ++i) 
        lst.insert(lst.size(), i); // insere no final da lista

    print(lst);

    lst.remove(1);

    print(lst);
    
}