#pragma once
#include"iostream"
#include"DoublyCircularLinkedList.h"
#include"Martyr.h"
#include"SinglyList.h"
using namespace std;

//Note * last input first output (LIFO)
template<typename T>
class MyStack {
private:
	SingleList<T> *container;
	int n;


public:
	MyStack() {
		container = new SingleList<T>;
		n = 0;
	}
	MyStack(const MyStack <T>& obj)
	{
		container = new SingleList<T>;
		container = obj.container;
		n = obj.n;
	}
	T top() {
		return container->getBack();
	}
	void pop() {
		if (empty()) {
			return;
		}
		container->removeBack();
		n--;
	}
	void push(const  T & x) {
		container->addBack(x);
		n++;
	}

	int size()const {
		return n;
	}
	bool empty() {
		return n == 0;
	}
	~MyStack() {
		delete container;
	}
};