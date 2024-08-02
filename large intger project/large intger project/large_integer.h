#pragma once
#include"iostream"
using namespace std;

class LargeInteger {

private:
	short int* number;
	int length;
	int maxSize;
	void resize();

public:
	LargeInteger(int maxSize);
	LargeInteger(const LargeInteger& L);
	bool setNumber(string str);
	void read(istream& in);
	void write(ostream& out);
	LargeInteger operator+(const LargeInteger& L);
	LargeInteger operator-(const LargeInteger& L);
	LargeInteger operator*(const LargeInteger& L);
	const LargeInteger& operator=(const LargeInteger& L);
	bool operator==(const LargeInteger& L)const;
	bool operator<(const LargeInteger& L)const;
	bool operator>(const LargeInteger& L)const;
	

	~LargeInteger();
};

void LargeInteger:: resize() {
	maxSize =length*2;
	short int* a = new short int[maxSize] {0};
	for (int i = length,j=0; i < maxSize; i++,j++) {
		a[i] = number[j];
	}
	delete[] number;
	number = a;
	a = NULL;
}

LargeInteger::LargeInteger(int Size = 10) {
	this->maxSize = Size;
	length = 0;
	number = new short int[this->maxSize] {0};
}


LargeInteger::LargeInteger(const LargeInteger& L) {
	maxSize = L.maxSize;
	number = new short int[maxSize] {0};
	length = L.length;

	for (int i = maxSize-1; i>=maxSize-length; i--) {
		number[i] = L.number[i];
	}


}


bool LargeInteger::setNumber(string str) {

	length = str.length();
	for (int i = 0; i < length; i++) {
		if (int(str[i]) > 58 || int(str[i]) < 48)
			return false;
	}
	if (length >= maxSize) {
		resize();
	}
	

	for (int i = maxSize-1, j = length; j!=0; i--, j--) {
		number[i] = str[j-1] - 48;
	}

	/*for (int i = 0; i < maxSize; i++) {
		cout << number[i] << " ";
	}*/
	return true;
	
}

void LargeInteger::read(istream& in) {
	string temp;
	cout << "Enter a vaild number with out letter"<<endl;
	in >> temp;
	cout << endl ;
	if (setNumber(temp)) {
		cout << "Successful Input :)" << endl<<endl;
	}
	else {
		cout << "Failed Input" << endl;
		
	}
}

void LargeInteger::write(ostream& out) {
	int index;
	for (index = 0; number[index] == 0; index++);
	if (index == maxSize) {
		cout << 0;
		return;
	}
	for (int i = index, counter = 0; i < maxSize; i++) {
		counter++;
		out << number[i];
		if (counter == 3&&i+1!=maxSize) {
			
			cout << ",";
			counter = 0;
		}

	}
}

LargeInteger LargeInteger:: operator+(const LargeInteger& L) {
	int max= (maxSize >= L.maxSize)?maxSize:L.maxSize;
	

	LargeInteger temp(max+1);
	
		
	temp = L;
		

		for (int i = temp.maxSize - 1, j = maxSize - 1; j >= maxSize-length; i--, j--) {
			temp.number[i] += number[j];
			if (temp.number[i] >= 10) {
				int mod = temp.number[i] % 10;
				temp.number[i - 1] += temp.number[i] / 10;
				temp.number[i] = mod;
			}

		} // for loop

		int i;
		for ( i = 0;  temp.number[i]==0; i++);
		temp.length = temp.maxSize-i;
		return temp;

}

LargeInteger LargeInteger:: operator-(const LargeInteger& L) {
	int max = (maxSize >= L.maxSize) ? maxSize : L.maxSize;


	LargeInteger temp(max + 1);
	if (*this > L ) {
		temp = *this;
		

		for (int i = temp.maxSize - 1, j = L.maxSize - 1; j >= 0; i--, j--) {
			if(temp.number[i] >= L.number[j])
			temp.number[i] -= L.number[j];
			else if (temp.number[i] < L.number[j]) {
				for (int c = i - 1; true; c--) {
					if (temp.number[c] != 0) {
						temp.number[i] += 10;
						temp.number[c] -= 1;
						break;
					}
					else {
						temp.number[c] = 9;
					}
				}
				temp.number[i] -= L.number[j];
			}
			

		} // for loop

		int i;
		for (i = 0; temp.number[i] == 0; i++);
		temp.length = temp.maxSize - i;
		/*i++;
		for(;i<=maxSize;i++)
			temp.number[i] = abs(temp.number[i]);*/

		return temp;

	}


	else if(*this < L) {
		temp = L;
		


		for (int i = temp.maxSize - 1, j = maxSize - 1; j >= maxSize-length; i--, j--) {
			if (temp.number[i] >= number[j])
				temp.number[i] -= number[j];
			else if (temp.number[i] < number[j]) {
				for (int c = i - 1; true; c--) {
					if (temp.number[c] != 0) {
						temp.number[i] += 10;
						temp.number[c] -= 1;
						break;
					}
					else {
						temp.number[c] = 9;
					}
				}
				temp.number[i] -= number[j];
			}


		} // for loop

		int i;
		for (i = 0; temp.number[i] == 0; i++);
		temp.length = temp.maxSize - i;
		temp.number[temp.maxSize - temp.length] *= -1;
		

		return temp;
	}

	temp.number[temp.maxSize - 1] = 0;
	
		return temp;
	
	

	

}

LargeInteger LargeInteger:: operator*(const LargeInteger& L) {

	int tempSize = length + L.length;
	LargeInteger temp(tempSize + 1);

	for (int i = L.maxSize - 1, k = 0; i >= L.maxSize - L.length; i--, k++) {
		int carry = 0;
		int tempBack = tempSize - k;

		for (int j = maxSize - 1; j >= maxSize - length; j--) {
			int product = (number[j] * L.number[i]) + carry;
			carry = product / 10;
			temp.number[tempBack] += product % 10;

			if (temp.number[tempBack] >= 10) {
				carry += temp.number[tempBack] / 10;
				temp.number[tempBack] %= 10;
			}

			tempBack--;
		}

		
		while (carry > 0) {
			temp.number[tempBack] += carry;
			if (temp.number[tempBack] >= 10) {
				carry = temp.number[tempBack] / 10;
				temp.number[tempBack] %= 10;
			}
			else {
				carry = 0;
			}
			tempBack--;
		}
	}


	int i;
	for (i = 0; temp.number[i] == 0; i++);
	temp.length = tempSize - i;

	return temp;
}

const LargeInteger& LargeInteger:: operator=(const LargeInteger& L) {
	if (this != &L) {
		maxSize = L.maxSize;
		length = L.length;
		if (number != NULL)
			delete[] number;
		number = new short int[maxSize] {0};
		for (int i = maxSize - 1; 0 <= i; i--) {
			number[i] = L.number[i];
		}
}

	return *this;
}

bool LargeInteger:: operator==(const LargeInteger& L)const {
	if (length != L.length)
		return false;

	for (int i = maxSize - length, j = L.maxSize - L.length; i<maxSize; i++, j++) {
		if (number[i] != L.number[j])
			return false;
	}
	return true;
	
}

bool LargeInteger:: operator<(const LargeInteger& L)const {
	if (length < L.length)
		return true;
	else if (length > L.length)
		return false;
	else {
		for (int i = maxSize - length, j = L.maxSize - L.length; i < maxSize; i++, j++) {
			if (number[i] < L.number[j])
				return true;
			else if (number[i] > L.number[j]) {
				return false;
			}
		}
	}
	return false;
}

bool LargeInteger:: operator>(const LargeInteger& L)const {
	if (length > L.length)
		return true;
	else if (length < L.length)
		return false;
	else {
		for (int i = maxSize - length, j = L.maxSize - L.length; i < maxSize; i++, j++) {
			if (number[i] > L.number[j])
				return true;
			else if (number[i] < L.number[j]) {
				return false;
			}
		}
	}
	return false;
}


LargeInteger::~LargeInteger() {
	if (number != NULL)
		delete[]number;
	number = NULL;
}