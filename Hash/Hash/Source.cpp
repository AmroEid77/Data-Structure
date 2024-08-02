#include <iostream>
#include "hash.h"
using namespace std;
int main()
{
	Hash h;
	h.insert("int");
	h.insert("float");
	h.insert("double");
	cout << h.find("float");
	cout << h.find("int");
	cout << h.find("double");
	h.remove("float");
	cout << endl << h.find("float");
}