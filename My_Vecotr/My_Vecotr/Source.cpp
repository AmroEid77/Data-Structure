#include <iostream>
#include"My-Vector.h"
using namespace std;



int main()
{
	MyVector <double> v1(2);
	v1.add(5);
	v1.add(7);
	cout << v1;
	v1.add(9);
	cout << v1;
	MyVector<double> v2(3);
	v2.add(0);
	v2.add(0);
	v2.add(0);
	cout << v1 * v2;
	

}