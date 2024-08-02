#pragma once
#include<string>
using namespace std;
class Bucket
{
private:
	string elem;
	int status;
	friend  class  Hash;
public:
	Bucket() {
		status = 0;
	}
};

class  Hash {
	Bucket* hash;
	int capacity;
	int  h(const string& s);
public:
	//ADT
	Hash(int cap=11);// hash size is prime
	~Hash() { if (hash)  delete[] hash;   hash = NULL;  }
	bool  insert(const string & s);
	int  find(const string & s);
	bool  remove(const string& s);
	
};
// Hashing function : hash code(maping any data type to int) + compression function ( Division Method)
int  Hash::h(const string& s) {
	int  sum = s[0] + s[1];//220
	return  sum % capacity;// % used only in integers [0-capacity-1]
}

Hash::Hash(int cap ) {
	capacity = cap;
	hash = new Bucket[capacity];
}

bool  Hash::insert(const string& s) {
	int  b = h(s);
	if (hash[b].status == 0)
	{
		hash[b].elem = s;
		hash[b].status = 1;
			return true;
	}
    for(int  i = (b+1)%capacity ; i!= b ; i = (i+1) % capacity)
		if (hash[i].status == 0)
		{
			hash[i].elem = s;
			hash[i].status = 1;
			return true;
		  }
	return false;
}
int    Hash::find(const string& s)
{
	int  b = h(s);
	if (hash[b].status == 1 && hash[b].elem == s)
		return b;
	for (int i = (b + 1) % capacity; i != b; i = (i + 1) % capacity)
		if (hash[i].status == 1 && hash[i].elem == s)
		{
			return i;
		}
	return -1;
}
bool    Hash::remove(const string& s)
{
	int  loc = find(s);
	if (loc == -1)  return false;

	hash[loc].status = 0;

}







