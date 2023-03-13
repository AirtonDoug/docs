#include <iostream>
#include "Vector.h"
using namespace std;

void print(const Vector& list) {
	for(int i = 0; i < list.size(); i++) 
		cout << list.at(i) << " ";
		cout << "\ncap = " << list.capacity() << endl;
		cout << "size = " << list.size() << endl;
	cout << endl;
}

int main() {
	Vector list1, list2;
	print(list1);
	print(list2);
	for(int i = 0; i < 150; ++i) {
		list1.push_back(i);
		list2.push_back(i * 2);
	}
	print(list1);
	print(list2);
	
}