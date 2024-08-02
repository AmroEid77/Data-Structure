#pragma once
#include"iostream"
#include"Martyr.h"
#include"DoublyCircularLinkedList.h"
#include"fstream";
using namespace std;

template<typename T>

class MyVector
{
private:
    T* a;
    int capacity;//max size
    int n;//actual size
    void resize();

public:
    MyVector(int cap = 5);
    /*MyVector<T>(int one,int two,int three) {

        capacity = 5;
        a = new T[5];
        n = 3;

            a[0] = one;
            a[1] = two;
            a[2] = three;

    }*/


    MyVector(const MyVector<T>& obj);


    MyVector<T>& operator= (const MyVector<T>& obj);
    bool operator==(const MyVector<T>& obj)const;
    MyVector<T> operator+(MyVector<T>& obj);
    MyVector<T> operator-(MyVector<T>& obj);
    void operator+=(const MyVector<T>& obj);
    void operator-=(MyVector<T>& obj);
    T operator*(const MyVector<T>& obj);
    T operator/(const MyVector<T>& obj);
    bool operator!=(const MyVector<T>& obj)const;
    void add(const T& x);
    T operator[](int index);
    T get(int index);
    /*T* get(int index) {
        if (index >= 0 && index < n)
            return &a[index];
        return NULL;

    }*/ // another solution for get
    T at(int index);
    inline void removeAll();
    inline void clear();
    bool remove(int index);
    bool erase(int index);
    void reserve(int Nsize);
    int find(T value);
    void set(int index, T value);
    bool empty() const;
    int size() const;
    T front();
    void pop_Front();
    T back();
    void pop_Back();
    void push_back(T value);
    int findMartyrByName(const string& name);
    void deleteMartyr(const string& martyrName);
    void updateMartyr(const T & martyr, const string& oldName);
    template<typename T>
    friend istream& operator>>(istream& in, MyVector<T>& obj);
    template<typename T>
    friend ostream& operator<<(ostream& out, const MyVector<T>& obj);

    void saveInVector(ofstream& newFile);
    

    ~MyVector();
};
//v1.operator(v2) it's same v1 + v2
/////////////////////////////////////////////////////////////////////////////////////

template<typename T>
void MyVector<T>::resize() {

    {
        T* temp = new T[capacity * 2];
        for (int i = 0; i < n; i++)
        {
            temp[i] = a[i];
        }
        delete[] a;
        a = temp;
        capacity *= 2;


        /*
        this->capacity*=2;
        T *b=new T[capacity];
        for(int i=0;i<this->n;i++){
        b[i]=this->a[i];
        }
        delete [] this->a;
        this->a=b;
        b=NULL;
        */
    }
}


template<typename T>
MyVector<T>::MyVector(int cap)
{
    capacity = cap;
    a = new T[capacity];
    n = 0;
}

template<typename T>
MyVector<T>::MyVector(const MyVector<T>& obj)
{
    capacity = obj.capacity;
    a = new T[capacity];
    n = obj.n;
    for (int i = 0; i < n; i++) {
        this->a[i] = obj.a[i];
    }
}

template<typename T>
MyVector<T>& MyVector<T>::operator= (const MyVector<T>& obj)
{
    if (this != &obj) {
        if (a != NULL) delete[] a;
        a = new T[obj.capacity];
        n = obj.n;
        capacity = obj.capacity;
        for (int i = 0; i < n; i++) {
            this->a[i] = obj.a[i];
        }
    }
    return *this;
}

template<typename T>
bool MyVector<T>::operator==(const MyVector<T>& obj) const
{
    if (n > obj.n || n < obj.n)
        return false;
    int i;
    for (i = 0; i < n && (fabs(a[i] - obj.a[i]) <= 0.000001); i++);
    if (i >= n)
        return true;
    return false;
}

template<typename T>
MyVector<T> MyVector<T>::operator+(MyVector<T>& obj)
{
    //should &obj// I can see obj private cuz it's have same data type for the class if not else you cant see the private
// if i do MyVector<T>& pass with refernce you will got trash value when the destructer is called cuz in v=v1+v2
//v1+v2 it will save in result and when i have & and the destructer is called i delete address of result and delete everyting in side the dynamic a inside it and the a in v point to trash
    if (this->n < obj.n) {

        MyVector<T> result(obj.n);
        for (int i = 0; i < n; i++) {
            result.add(a[i] + obj.a[i]);
            //result.a[i]=a[i]+obj.a[i];result.n++;

        }
        for (int j = n; j < obj.n; j++) {
            result.add(obj.a[j]);
            //result.a[j]=obj.a[j];n++;
        }
        return result;

    }// n<obj.n brace

    if (this->n > obj.n) {

        MyVector<T> result(n);
        for (int i = 0; i < obj.n; i++) {
            result.add(a[i] + obj.a[i]);
            //result.a[i]=a[i]+obj.a[i];result.n++;

        }
        for (int j = obj.n; j < n; j++) {
            result.add(a[j]);
            //result.a[j]=obj.a[j];n++;
        }
        return result;

    }

    MyVector<T> result(n);
    for (int i = 0; i < obj.n; i++) {
        result.add(a[i] + obj.a[i]);
        //result.a[i]=a[i]+obj.a[i];result.n++;

    }

    return result;

}

template<typename T>
MyVector<T> MyVector<T>::operator-(MyVector<T>& obj)
{//should &obj// I can see obj private cuz it's have same data type for the class if not else you cant see the private
// if i do MyVector<T>& pass with refernce you will got trash value when the destructer is called cuz in v=v1+v2
//v1+v2 it will save in result and when i have & and the destructer is called i delete address of result and delete everyting in side the dynamic a inside it and the a in v point to trash
    if (this->n < obj.n) {

        MyVector<T> result(obj.n);
        for (int i = 0; i < n; i++) {
            result.add(a[i] - obj.a[i]);
            //result.a[i]=a[i]-obj.a[i];result.n++;

        }
        for (int j = n; j < obj.n; j++) {
            result.add(obj.a[j]);
            //result.a[j]=obj.a[j];n++;
        }
        return result;

    }// n<obj.n brace

    if (this->n > obj.n) {

        MyVector<T> result(n);
        for (int i = 0; i < obj.n; i++) {
            result.add(a[i] - obj.a[i]);
            //result.a[i]=a[i]-obj.a[i];result.n++;

        }
        for (int j = obj.n; j < n; j++) {
            result.add(a[j]);
            //result.a[j]=obj.a[j];n++;
        }
        return result;

    }

    MyVector<T> result(n);
    for (int i = 0; i < obj.n; i++) {
        result.add(a[i] - obj.a[i]);
        //result.a[i]=a[i]-obj.a[i];result.n++;

    }

    return result;


}

template<typename T>
void MyVector<T>::operator+=(const MyVector<T>& obj)
{

    if (size() != obj.size())
        return;
    for (int i = 0; i < size(); i++) {
        a[i] += obj.a[i];
    }
}

template<typename T>
void MyVector<T>::operator-=(MyVector<T>& obj)
{
    if (size() != obj.size())
        return;
    for (int i = 0; i < size(); i++) {
        a[i] -= obj.a[i];
    }


}

template<typename T>
T MyVector<T>::operator*(const MyVector<T>& obj)
{
    if (size() != obj.size() || empty() || obj.empty())
        exit(1);

    T sum = 0;
    for (int i = 0; i < size(); i++) {
        sum += a[i] * obj.a[i];
    }
    return sum;

}

template<typename T>
T MyVector<T>::operator/(const MyVector<T>& obj)
{
    if (size() != obj.size() || empty() || obj.empty())
        exit(1);

    T sum = 0;
    for (int i = 0; i < size(); i++) {
        sum += a[i] / obj.a[i];
    }
    return sum;

}

template<typename T>
bool MyVector<T>::operator!=(const MyVector<T>& obj) const
{
    if (size() != obj.size()) return true;
    int i = 0;
    for (; i < size(); i++) {
        if (!(fabs(a[i] - obj.a[i]) <= 0.0000001))
            return true;
    }
    return false;
}

template<typename T>
void MyVector<T>::add(const T &x) {
    if (n >= capacity)
        resize();

    int i = n - 1;
    while (i >= 0 && x.getName() < a[i].getName()) {
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = x;
    n++;
}



template<typename T>
T MyVector<T>::operator[](int index)
{
    if (index >= 0 && index < n)
        return a[index];
    exit(1);
}


template<typename T>
T MyVector<T>::get(int index)
{

    if (index >= 0 && index < n)
        return a[index];
    exit(1);


}

template<typename T>
T MyVector<T>::at(int index) {
    return get(index);
}

template<typename T>
inline void MyVector<T>::removeAll()
{
    n = 0;
}

template<typename T>
inline void MyVector<T>::clear()
{
    removeAll();
}

template<typename T>
bool MyVector<T>::remove(int index)
{
    if (index < 0 || index >= n)
        return false;
    for (int i = index; i < n - 1; i++)
        a[i] = a[i + 1];
    n--;
    return true;

}
template<typename T>
bool MyVector<T>::erase(int index) {
    return remove(index);
}

template<typename T>
void MyVector<T>::reserve(int Nsize)
{
    capacity = Nsize;
    n = 0;
    if (a != NULL) {
        delete[] a;
    }
    a = new T[capacity];
}

template<typename T>
int MyVector<T>::find(T value)
{
    int i;
    for (i = 0; i < n && !(fabs(a[i] - value) <= 0.0000001); i++);
    if (i >= n)
        return -1;
    return i;

}

template<typename T>
void MyVector<T>::set(int index, T value)
{
    if (index > size() || index < 0)
        return;
    a[index] = value;
}

template<typename T>
bool MyVector<T>::empty() const
{
    return n <= 0;
}

template<typename T>
int MyVector<T>::size() const
{
    return n;
}

template<typename T>
T MyVector<T>::front()
{
    if (empty())
        exit(1);
    return a[0];
}

template<typename T>
void MyVector<T>::pop_Front()
{
    if (empty())
        return;
    remove(0);
}

template<typename T>
T MyVector<T>::back()
{
    if (empty())
        exit(1);
    return a[n - 1];
}

template<typename T>
void MyVector<T>::pop_Back()
{
    if (empty())
        return;
    remove(size() - 1);//n-1 or n--
}

template<typename T>
void MyVector<T>::push_back(T value)
{
    add(value);
}

template<typename T>
istream& operator>>(istream& in, MyVector<T>& obj)
{
    obj.n = 0;
    for (int i = 0; i < obj.capacity; i++) {
        in >> obj.a[i];
        obj.n++;
    }
    return in;
}


template<typename T>
ostream& operator<<(ostream& out, const MyVector<T>& obj) {
    
    for (int i = 0; i < obj.n; i++) {
        out << obj.a[i];
        
    }
    
    return out;
}


template<typename T>
MyVector<T>::~MyVector()
{
    if (a != NULL)
        delete[] a;
    a = NULL;
}
template<typename T>
int MyVector<T>::findMartyrByName(const string& name) {
    for (int i = 0; i < n; i++) {
        if (a[i].getName() == name) {
            return i; // return the index if found
        }
    }
    return -1; // return -1 if not found
}
template<typename T>
void MyVector<T>:: deleteMartyr(const string& martyrName) {
    for (int i = 0; i < n; i++) {
        if (a[i].getName() == martyrName) {
            remove(i);
            return; 
        }
    }
    cout << "Martyr with name '" << martyrName << "' not found." << endl;
}


template<typename T>
void MyVector<T>::updateMartyr(const T& martyr, const string& oldName) {
    for (int i = 0; i < size(); ++i) {
        if (a[i].getName() == oldName) {
            a[i].setName(martyr.getName());
            a[i].setAge(martyr.getAge());
            a[i].setGender(martyr.getGender());
            
            cout << "Martyr's name updated successfully." << endl;
            return;
        }
    }
    
}
template<typename T>
void MyVector<T>::saveInVector(ofstream& newFile) {
    for (int i = 0; i < n; i++) {
        newFile << a[i];
    }

}