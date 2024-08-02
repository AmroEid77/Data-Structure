#pragma once
#include"iostream"
using namespace std;
template<typename T>
class SNode {
private:
	T data;
	SNode <T>* ptrNext;
	template<typename T>
	friend class SingleList;
};
template<typename T>
class SingleList {
private:
	SNode<T>* head;
	int n;// actual size
public:

	SingleList() {
		head = NULL;
		n = 0;
	}

	SingleList(const SingleList<T>& obj) {
		SNode<T>* p = obj.head;
		while (p) {
			addBack(p->data);
			p = p->ptrNext;
		}
	}
	bool empty()const {
		return head == NULL;
	}
	void addFront(const T& item) {
		SNode <T>* p = new SNode<T>;
		p->data = item;
		p->ptrNext = NULL;
		if (empty()) {
			head = p;
			n++;
			return;
		}
		p->ptrNext = head;
		head = p;
		n++;

	}
	void removeFront() {
		if (empty()) {
			return;
		}
		SNode <T>* p = head;
		head = head->ptrNext;
		p->ptrNext = NULL;
		delete p;
		n--;

	}
	void addBack(const T& item) {
		SNode <T>* p = new SNode<T>;
		p->data = item;
		p->ptrNext = NULL;
		SNode <T>* movePtr = head;
		if (empty()) {
			addFront(item);
			return;
		}
		while (movePtr && movePtr->ptrNext) {
			movePtr = movePtr->ptrNext;
		}
		movePtr->ptrNext = p;
		n++;
	}
	void removeBack() {
		SNode <T>* p = head;
		if (empty()) {
			return;
		}
		if (n == 1) {
			removeFront();
			return;
		}
		while (p && p->ptrNext->ptrNext) {
			p = p->ptrNext;
		}
		delete p->ptrNext;
		p->ptrNext = NULL;
		n--;
	}

	void addAfter(const SNode <T>* ptr, const T& item) {
		SNode <T>* p = new SNode<T>;
		p->data = item;
		p->ptrNext = NULL;

		p->ptrNext = ptr->ptrNext;
		ptr->ptrNext = p;
		n++;
	}
	SNode<T>* find(const T& item) {
		SNode<T>* p = head;
		while (p && p->data != item) {
			p = p->ptrNext;
		}
		return p;
	}
	void removeAll() {
		while (!empty()) {

			removeFront();
		}
		head = NULL;
		n = 0;
	}
	void displaySList() {
		SNode <T>* ptr = head;
		while (ptr) {
			cout << ptr->data << " ";
			ptr = ptr->ptrNext;
		}
		cout << endl << n;
	}
	T getBack()const {
		SNode <T>* ptr = head;
		while (ptr && ptr->ptrNext) {
			ptr = ptr->ptrNext;
		}
		return ptr->data;
	}
	~SingleList() {
		while (!empty()) {

			removeFront();
		}
		head = NULL;
		n = 0;

	}
};