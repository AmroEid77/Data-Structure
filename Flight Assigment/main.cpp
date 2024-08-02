#include "iostream"
#include"Flight.h"

using namespace std;


int main() {
	Flight plane;
	int input;
	do{
		cout << "1. Reserve a newly empty seat." << endl;
		cout << "2. Delete a reserved seat." << endl;
		cout << "3. Delete all reserved seats." << endl;
		cout << "4. Print out flight seats map." << endl;
		cout << "5. Quit." << endl;
		cout << "Select 1 Option from 1-5 " << endl;
		cin >> input;
		switch (input)
		{
		case 1:plane.Reserved(); break;
		case 2:plane.DeleteReservedSeat(); break;
		case 3:plane.DeleteAllReservedSeat(); break;
		case 4:plane.PrintFlightMap(); break;
		case 5:return 0; break;

		default:cout << "you enter wrong number please re enter" << endl;
			break;
		}
	
	
	
	} while (input != 5);

	
}