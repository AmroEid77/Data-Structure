#pragma once
#include"iostream"
using namespace std;



class Seat {
private:
	int Seatnumber;
	bool reserved;



public:
	Seat(int x=0) {
		Seatnumber = x;
		

		reserved = false;
	}
	int GetseatN() {
		return Seatnumber;
	}
	void setSeatN(int x) {
		Seatnumber = x;
	}
	bool GetReserved() {
		return reserved;
	}
	void  SetReserved(bool x) {
		 reserved= x;
	}

	void printInfo() {
		if (reserved) {
			cout << "the seat " << Seatnumber << " is  reserved" << endl;
		}
		else {
			cout << "the seat " << Seatnumber << " isn't reserved" << endl;
		}
	}

	~Seat(){}

};