#pragma once

#include<iostream>

using namespace std;

/*template<typename T>
void print(const T* a, int N) { // or const T a it's better cuz when I call string or somthing like that I should put & obj in print func in main

	for (int i = 0; i < N; i++) {
		cout << a[i];
	}
}

int main() {
	const char* st = "Hello";
	//use the above genric function to print st
	print(st, strlen(st));
	const string s = "Hello me";
	print(&s, s.length());


}
*/

template <typename T, typename M>

/*template <typename T , typename M>*/
class Complex {

private:

	T img;
	M real;
public:
	Complex(T x, M y);

	void setImg(T x) {
		img = x;
	}
	void setReal(M y) {
		real = y;
	}
	T getImg()const {
		return img;
	}
	M getReal()const {
		return real;
	}

	Complex<T, M> operator+(const Complex<T, M>& obj);// if I want to call data type I should  do this Complex<T, M> for every var
	
	
	 template <typename T, typename M>// I should add this before o i stream idk why but this is your compiler
	 friend ostream& operator<<(ostream& out, const Complex<T, M>& obj);
};

template <typename T, typename M>
Complex<T, M> Complex<T, M>:: operator+(const Complex<T, M>& obj) {
	Complex<T, M>  res;
	res.img = img + obj.img;
	res.real = real + obj.real;
	return res;


}


template <typename T, typename M>
ostream& operator<<(ostream& out, const Complex<T, M>& obj) {// I put Complex<T, M>:: for member function and ostream is not member fun I must not put friend cuz it's for class only
	out << obj.img << "i+" << obj.real;
	return out;
}
template <typename T, typename M>
Complex<T, M>::Complex(T x, M y) {
	img = x;
	real = y;
}
















