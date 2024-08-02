#pragma once
#include<iostream>
using namespace std;

template <typename T>
class TNode {
	T data;
	TNode<T>* left, *right, *parent;

	template <typename T> friend class BST;
};
template <typename T>
class BST {
	TNode<T>* root;
	int n;

public:
	BST():root(NULL),n(0) {}

	bool  empty()const { return root == NULL;  }
	
	int  size()const { return n;  }
	
	bool  isLeaf(TNode<T>* p)const { if (!p) return false;  else return p->left == p->right;  }
	
	bool  hasUniChild(TNode<T>* p)const { if (!p) return NULL; else return (p->left && !p->right) || (!p->left && p->right);  }
	
	bool isRoot(TNode<T>* p) const { if (!p) return NULL; else  return p->parent == NULL; }

	TNode<T>* getParent(TNode<T>* p) const { if (isRoot(p) || !p) return NULL;  else  return p->parent; }

	T getSibling(TNode<T>* p)const { 
		if (isRoot(p) || !p ) exit(1);   
		  else   
			return (p->parent->left == p)? p->parent->right->data : p->parent->left->data;
	}
	T getSibling(const T & key)const {
		TNode<T>* p = find(key);
		return getSibling(p);
	}
	~BST() {  removeAll(root); 	root = NULL; } 

    void   removeAll(TNode<T>* p) {
		 if (!p) return;
		 removeAll(p->left);
		 removeAll(p->right);
		 delete p;
	}

   TNode<T>* createNode(const T& key) {
	   TNode<T>* p = new TNode<T>;
	   p->data = key;
	   p->left = NULL;
	   p->right = NULL;
	   p->parent = NULL;
	   return p;
   }

   void   insert(const T& key)
   {
	   TNode<T>* N = createNode(key);
	   if (empty()) {
		   root = N;  n++;  return;
	   }
	   TNode<T>* prev = root;
	   TNode<T>* cur = root;
	   while (cur) {
		   prev = cur;
		   if (key > cur->data)
			   cur = cur->right;
		   else
			   cur = cur->left;
	   }//while

	   if (prev && key > prev->data) prev->right = N;
	   else  prev->left = N;

	   N->parent = prev;
	   n++;
   }

   TNode<T>* find(const T& key)const {
	   TNode<T>* cur = root;
	   while (cur && cur->data != key) {
		    if (key > cur->data)
			   cur = cur->right;
		   else
			   cur = cur->left;
	   }//while
	   return cur;
  }


   void   printLNR(TNode<T>* p) {
	   if (!p) return;
	   printLNR(p->left);
	   cout << p->data << "\t";
	   printLNR(p->right);
  }

   void  printAsc() {
	   printLNR(root);
 }

  void   printRNL(TNode<T>* p) {
	   if (!p) return;
	   printRNL(p->right);
	   cout << p->data << "\t";
	   printRNL(p->left);
   }
   void  printDesc() {
	   printRNL(root);
   }

   bool   remove(const T& key) {
	   
	   TNode<T>* p = find(key);
	   
	   if (!p) return false;

	   //case1: If the removed node is a leaf node
	   if (isLeaf(p)) {
		   if (p->parent->left == p) p->parent->left = NULL; else p->parent->right = NULL;
		   p->parent = NULL;
		   n--;
		   delete p;
		   return true;
	   }
	   //case 2: If the removed node has a uni-child
	   if (hasUniChild(p))
	   {
		   TNode<T>* above = p->parent;
		   if (p == above->left)
			   if (p->left) {
				   above->left = p->left;
				   p->left->parent = above;
			   }
			   else {
				   above->left = p->right;
				   p->right->parent = above;
			   }
		   else if(p == above->right)
			   if (p->left) {
				   above->right = p->left;
				   p->left->parent = above;
			   }
			   else {
				   above->right = p->right;
				   p->right->parent = above;
			   }

		   n--;
		   delete p;
		   return true;
	   }
	   // case 3: If the removed node has two children
	   else {
		   TNode<T>* succ = getSuccessor(p);
		   if (succ) {
			   p->data = succ->data;
			   // 2 cases : 1) if succ is a leaf 
			   if (isLeaf(succ)) {
				   if (succ->parent->left == succ) succ->parent->left = NULL; else succ->parent->right = NULL;
				   succ->parent = NULL;
				   n--;
				   delete succ;
				   return true;
			   }
			   // 2) succ has right unichild
			   else {

				   TNode<T>* above = succ->parent;
				   if (succ == above->left)
					{
						   above->left = succ->right;
						   succ->right->parent = above;
					   }
				   else if (succ == above->right)
				   {
						   above->right = succ->right;
						   succ->right->parent = above;
					   }

				   n--;
				   delete succ;
				   return true;
			   }
		   }
	   }
	   return false;
 }
   TNode<T>* getSuccessor(TNode<T>* p) const {
	   if (!p || empty() ) return NULL;
	   if (!p->right) return NULL;
	   TNode<T>* s = p->right;
	   while (s && s->left)  s = s->left;
	   return s;
 }
};