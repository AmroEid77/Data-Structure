#pragma once
#include "iostream"
#include"Seat.h"

using namespace std;




class Flight {

private:
	Seat** seat;
	



public:

	
	Flight() {
		int firstS = 11;
		seat = new Seat * [9];

		for (int i = 0; i < 9; i++) {
			if (i < 3) {
				seat[i] = new Seat[2]{ firstS,firstS + 1 };
				
				firstS += 10;
			}
			else {
				seat[i] = new Seat[4]{ firstS ,firstS +1,firstS +2,firstS +3};
				
				firstS += 10;

			}
		}
	}

	bool isValid(int SN) {


		int arr[30] = { 11,12,21,22,31,32,41,42,43,44,51,52,53,54,61,62,63,64,71,72,73,74,81,82,83,84,91,92,93,94 };


		for (int i = 0; i < 30; i++) {
			if (arr[i] == SN)
				return true;
		}


		return false;

	}



	void Reserved() {
		int NS;//number Seat
		
		cout << "Please enter a valid seat" << endl;
		cin >> NS;
		while (!(isValid(NS))) {
			cout << "You have already entered a not valid number so re-enter again" << endl;
			cin >> NS;

		}
		for (int i = 0; i < 9; i++) {
			if (i < 3) {
				for (int j = 0; j < 2; j++) {
					if (seat[i][j].GetseatN() == NS) {
						if (seat[i][j].GetReserved()==false) {
							seat[i][j].SetReserved(true);
							cout << "it's reserved for you good :) " << endl << endl;
							return;
						}

						else {
							Reserved();
							return;

						}
						
					}
				}// loop j brace
				
			}
			else {
				for (int j = 0; j < 4; j++) {
					if (seat[i][j].GetseatN() == NS){
						if (seat[i][j].GetReserved() == false) {
							seat[i][j].SetReserved(true);
							cout << "it's reserved for you good :) " << endl << endl;
							return;
						}

						else {
							Reserved();
							return;

						}
						

					}
				}// loop j brace

			}
		}


	}
	void DeleteReservedSeat() {
		int NS;//number Seat
		int flag = 0;
		cout << "Please enter a valid seat" << endl;
		cin >> NS;
		while (!(isValid(NS))) {
			cout << "You have already entered a not valid number so re-enter again" << endl;
			cin >> NS;

		}
		for (int i = 0; i < 9; i++) {
			if (i < 3) {
				for (int j = 0; j < 2; j++) {
					if (seat[i][j].GetseatN() == NS) {
						if (seat[i][j].GetReserved() == true) {

							seat[i][j].SetReserved(false);
							cout << "it's  not reserved  :) " << endl << endl;
							return;
						}

						else {
							DeleteReservedSeat();
							return;

						}
						
					}
				}// loop j brace

			}
			else {
				for (int j = 0; j < 4; j++) {
					if (seat[i][j].GetseatN() == NS) {
						if (seat[i][j].GetReserved() == true) {

							seat[i][j].SetReserved(false);
							cout << "it's  not reserved  :) " << endl << endl;
							return;
						}

						else {
							DeleteReservedSeat();
							return; 
						}
						

					}
				}// loop j brace

			}
		}

	}
	void DeleteAllReservedSeat() {
		for (int i = 0; i < 9; i++) {
			if (i < 3) {
				for (int j = 0; j < 2; j++) {
					seat[i][j].SetReserved(false);
				}
			}
			else {
				for (int j = 0; j < 4; j++) {
					seat[i][j].SetReserved(false);
				}

			}
		}
		cout << "It's Done :)" << endl;

	}
	int PrintFlightMap() {
		int counter = 0;
		for (int i = 0; i < 9; i++) {
			if (i < 3) {
				for (int j = 0; j < 2; j++) {
					if (seat[i][j].GetReserved() == true) {
						counter++;
					}
					seat[i][j].printInfo();
				}
			}
			else {
				for (int j = 0; j < 4; j++) {
					if (seat[i][j].GetReserved() == true) {
						counter++;
					}
					seat[i][j].printInfo();
				}

			}
		}
		return counter;

	}
	~Flight() {
		for (int i = 0; i < 9; i++) {
			
			delete[] seat[i];
			
			
		}
		delete[] seat;



	}
	


};


