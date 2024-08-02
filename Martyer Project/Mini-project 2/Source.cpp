#include "iostream"
#include"DoublyCircularLinkedList.h"
#include"Martyr.h"
#include"fstream"
#include "MyStack.h"
#include"string"
using namespace std;

void split(const string& text, Martyr& x) {
    int count = 0;
    string* parts = new string[5];
    string token = "";

    for (int i = 0; i < text.length(); i++) {
        while (text[i] != ',' && i < text.length()) {
            token += text[i];
            i++;
        }

        parts[count] = token;
        count++;
        token = "";

        if (count >= 5) {
            break; 
        }
    }

    x.setName(parts[0]);
    x.setAge(parts[1]);
    x.setEventLocationDistrict(parts[2]); 
    x.setDateOfDeath(parts[3]);
    x.setGender(parts[4]);

    delete[] parts; // Clean up D M
}

int main() {
	DoublyCircularLinkedList sortedDoublyCircularLinked;
	ifstream file;
	file.open("C:\\unversite files\\Secoend Year\\Data Structure\\btselem.csv");
	string x;
    Martyr martyr;
    string name;
    MyStack<Martyr> c;

	getline(file, x);

	for (int i = 0; i <300; i++) {

		getline(file, x);
        split(x, martyr);
        
		sortedDoublyCircularLinked.addInOrderd(martyr);
	}
    
    sortedDoublyCircularLinked.printAll();
    
    int locationChoice;
    string locationName="None";
    string newLocation;
    int low;
    
    do {
        cout << "Location Menu:" << endl;
        cout << "1. Insert new location record" << endl;
        cout << "2. Update an existing location" << endl;
        cout << "3. Delete an existing location" << endl;
        cout << "4. Search for a location record" << endl;
        cout << "5. Quit"<<endl;
        cout << "Enter your choice (1-5): ";
        cin >> locationChoice;

        switch (locationChoice) {
        case 1:
            sortedDoublyCircularLinked.printAll();

            cout << "What location you want to add ?  ";
            
            cin>> locationName;
            while (!(sortedDoublyCircularLinked.insertNewLocation(locationName))) {
                cout << "it's already exists ,  Enter again" << endl;
                cin >> locationName;
            }
            cout <<endl <<"it's Done";
            cout << endl << endl;
            break;
        case 2:
            cout << endl;
            sortedDoublyCircularLinked.printAll();

            cout << "Which location you want to update ??  ";
            cin.ignore();
            getline(cin, locationName);
            while (!sortedDoublyCircularLinked.isfoundCityName(locationName)) {
                cout << "The Location not found" << endl << "enter again : ";
                cin.ignore();
                getline(cin, locationName);
            }

            cout << "What is the new name ??";
            
            cin>>newLocation;
            while (sortedDoublyCircularLinked.isfoundCityName(newLocation)) {
                cout << "The Location already exists" << endl << "enter again : ";
                
                cin >> newLocation;
            }
            sortedDoublyCircularLinked.updateLocation(locationName, newLocation);
            break;
        case 3:
            sortedDoublyCircularLinked.printAll();
            cout << endl;
            cout << "enter the location" << endl;
            
            cin>>locationName;
            while (!sortedDoublyCircularLinked.isfoundCityName(locationName)) {
                cout << "Location not found enter again \n";
                
                cin>>locationName;
            }
            sortedDoublyCircularLinked.deleteLocation(locationName);
            cout<<"it's Done \n";
            break;
        case 4:
            
            char searchChoice;
            cout << "a. Martyrs' Menu" << endl;
            cout << "b. Statistics Report" << endl;
            cout << "Enter your choice (a/b): ";
            cin >> searchChoice;

            switch (searchChoice) {
            case 'a':
                cout << "Martyrs' Menu:" << endl;
                cout << "1. Insert a new martyr record" << endl;
                cout << "2. Update a martyr record" << endl;
                cout << "3. Delete a martyr record" << endl;
                cout << "4. Search for a martyr by name and display information" << endl;
                cout << "Enter your choice (1-4): " << endl;
                int choicee;
                cin >> choicee;
                switch (choicee) {
                case 1:
                    
                    cout << "which location you want to add on it ??" << endl;
                    
                    cin>>locationName;
                    while (!sortedDoublyCircularLinked.isfoundCityName(locationName)) {
                        cout << "The Location not found" << endl << "enter again : ";
                        
                        cin>>locationName;
                    }
                    cout << "write his/her name :";
                    cin>>name;
                    martyr.setName(name);

                    cout << "write his/her age :";
                    cin>>name;
                    martyr.setAge(name);
                    
                    martyr.setEventLocationDistrict(locationName);
                    cout << "write his/her Date of death :";
                    cin>>name;

                    martyr.setDateOfDeath(name);
                    cout << "write his/her Gender :";
                    cin >> name;

                    martyr.setGender(name);

                    sortedDoublyCircularLinked.addInOrderd(martyr);
                    cout << "it's Done\n";

                    break;
                case 2:
                    cout << "which location you want to update on it ??" << endl;
                    
                    cin>>locationName;
                    while (!sortedDoublyCircularLinked.isfoundCityName(locationName)) {
                        cout << "The Location not found" << endl << "enter again : ";
                        
                        cin>>locationName;
                    }
                    cout << "write his/her name to search :";
                    cin.ignore();
                    getline(cin, name);
                    if (sortedDoublyCircularLinked.isfoundMartyrName(name, locationName,1)) {

                        cout << "Done" << endl;
                        break;
                    }
                    else {
                        cout << "not found" << endl;
                        break;
                    }
                case 3:
                    cout << "which location you want to delete martyr on it ??" << endl;

                    cin >> locationName;
                    while (!sortedDoublyCircularLinked.isfoundCityName(locationName)) {
                        cout << "The Location not found" << endl << "enter again : ";

                        cin >> locationName;
                    }
                    cout << "write his/her name to search :";
                    cin.ignore();
                    getline(cin, name);
                    if (sortedDoublyCircularLinked.isfoundMartyrName(name, locationName,0)) {

                        cout << "Done" << endl;
                        break;
                    }
                    else {
                        cout << "not found" << endl;
                        
                    }
                    break;
                case 4:
                    cout << "which location you want ??" << endl;

                    cin >> locationName;
                    while (!sortedDoublyCircularLinked.isfoundCityName(locationName)) {
                        cout << "The Location not found" << endl << "enter again : ";

                        cin >> locationName;
                    }
                    cout << "write his/her name to search :";
                    cin.ignore();
                    getline(cin, name);
                    if (sortedDoublyCircularLinked.isfoundMartyrName(name, locationName, -1)) {

                        cout << "Done" << endl;
                        break;
                    }
                    else {
                        cout << "not found" << endl;
                        
                    }

                    break;
                default:
                    cout << "Wrong choice !!!!" << endl;
                    break;
                }

                break;
            case 'b':
                cout << "Statistics Report:" << endl;
                cout << "1. The numbers of martyrs in the selected location" << endl;
                cout << "2. Print the Martyrs’ full information in that location" << endl;
                cout << "3. Traverse the stack(i.e., start from the latest date back to the earliest) and print the Martyrs’ full information" << endl;
                cout << "4. Report the date that had the minimum number of martyrs" << endl;
                cout << "Enter your choice (1-4): " << endl;
                int choice;
                cin >> choice;
                switch (choice)
                {
                case 1 :
                    sortedDoublyCircularLinked.printAll();
                    cout << endl;
                    cout << "enter the location" << endl;

                    cin >> locationName;
                    while (!sortedDoublyCircularLinked.isfoundCityName(locationName)) {
                        cout << "Location not found enter again \n";

                        cin >> locationName;
                    }
                    cout<<"the number of Martyr is " << sortedDoublyCircularLinked.numberOfMartyrsInLocation(locationName)<<endl;
                    break;
                case 2 :
                    sortedDoublyCircularLinked.printAll();
                    cout << endl;
                    cout << "enter the location" << endl;

                    cin >> locationName;
                    while (!sortedDoublyCircularLinked.isfoundCityName(locationName)) {
                        cout << "Location not found enter again \n";

                        cin >> locationName;
                    }
                    sortedDoublyCircularLinked.printMartyrInLocation(locationName);
                    break;


                case 3 :
                    sortedDoublyCircularLinked.printAll();
                    cout << endl;
                    cout << "enter the location" << endl;

                    cin >> locationName;
                    while (!sortedDoublyCircularLinked.isfoundCityName(locationName)) {
                        cout << "Location not found enter again \n";

                        cin >> locationName;
                    }
                    sortedDoublyCircularLinked.printStack(locationName);
                    cout << endl;
                    break;


                case 4 :
                    
                    low = sortedDoublyCircularLinked.lowestNumberOfMyatyrInLocation(locationName);

                    cout << "The city with lowest martyrs is " << locationName << " with :" << low << " Martyr";



                    cout << endl;

                    break;
                default:
                    cout << "Wrong choice !!!!" << endl;
                    break;
                }

                
                break;
            default:
                cout << "Wrong choice !!!!" << endl;
                break;
            }
            break;

        case 5:
            break;

        default:
            cout << "Wrong choice !!!!" << endl;
            break;
        }
    } while (locationChoice != 5);
    cout << endl;

    
    cout << "Do you want to save the file" << endl;

    char saveChoice;
    do {
        cout << "a . yes" << endl;
        cout << "b . no"<<endl;
        cout << "enter your choice :"<<endl;
        cin >> saveChoice;

        
    } while (saveChoice != 'a' && saveChoice != 'b');

    if (saveChoice == 'a') {
        ofstream saveFile;
        string newFileName;
        cout << "Enter the new file name<" << endl;
        cin >> newFileName;
        saveFile.open(newFileName + ".txt");
        sortedDoublyCircularLinked.save(saveFile);
    }

    cout << endl << "Byeee my Frendooooo :)" << endl;

}