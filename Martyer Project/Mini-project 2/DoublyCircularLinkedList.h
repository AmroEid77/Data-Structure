    #pragma once
    #include"iostream"
    #include"Martyr.h"
    #include"MyVector.h"
    #include"MyStack.h"
    #include"string"
    #include <cctype>
    #include"fstream";
    
    
    using namespace std;



    class CNode {
    private:
	    string cityName;
	    MyVector<Martyr> martyrVector;
	    MyStack<Martyr> martyrStack;
	    CNode* next;
	    CNode* prev;
	    friend class DoublyCircularLinkedList;

    };

    class DoublyCircularLinkedList {
    private:
	    CNode* head;
	    int n;
    public:
	    DoublyCircularLinkedList():head(NULL),n(0) {}
	    ~DoublyCircularLinkedList() { while (!empty())remove(); head = NULL; }
	    bool empty()const { return head == NULL; }
	    void addInOrderd(const Martyr &martyr);
	    bool insertNewLocation(string location);
        bool updateLocation(const string& oldLocation, const string& newLocation);
        bool isfoundCityName(const string& cityName) const;
        CNode* isfoundCityName2Edition(const string& cityName) const;
        int numberOfMartyrsInLocation(const string& location);
        bool isfoundMartyrName(const string& name, const string& location,int x)const;
        void deleteLocation(const string& location);
	    bool remove();
        int lowestNumberOfMyatyrInLocation(string &lowest);
	    string front() const { return head->cityName; }
	    string back() const { return head->prev->cityName; }
	    int size() const{ return n;}
	    void printAll();
        void printStack(const string& location)const;
        void printMartyrInLocation(const string& location)const;
	    void sortByCityName();
        void save(ofstream& newFile);
    };



    //find it by search
    string toLower(const string& str) {
        string result;
        for (char c : str) {
            result += tolower(c);
        }
        return result;
    }

    void DoublyCircularLinkedList::addInOrderd(const Martyr& martyr) {
        string newLocation = toLower(martyr.getEventLocationDistrict());
        CNode* newNode = new CNode;
        newNode->cityName = newLocation;

        if (empty()) {
            head = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
            newNode->martyrVector.add(martyr);
            newNode->martyrStack.push(martyr);
            n++;
            return;
        }

        // Check if the eventLocationDistrict already exists
        CNode* temp = head;
        bool locationExists = false;
        do {
            if (temp->cityName == newLocation) {
                locationExists = true;
                break;
            }
            temp = temp->next;
        } while (temp != head);

        if (!locationExists) {
        
            temp = head;
            while (temp->next != head && newLocation > temp->next->cityName) {
                temp = temp->next;
            }

            if (newLocation <= head->cityName) {
                newNode->next = head;
                newNode->prev = head->prev;
                head->prev->next = newNode;
                head->prev = newNode;
                head = newNode;
            }
            else {
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next->prev = newNode;
                temp->next = newNode;
            }

        
            temp = head;
            while (temp->cityName != newLocation) {
                temp = temp->next;
            }

        
        }
        temp->martyrVector.add(martyr);
        temp->martyrStack.push(martyr);
        n++;
    }


    bool DoublyCircularLinkedList::remove() {
	    if (empty())return false;
	    CNode* p=head->next;
	    if (p == head) { head = NULL; }
	    else {
		    head->next = head->next->next;
		    head->next->prev = head;
		    p->next = NULL;
		    delete p;
		    n--;
	    }
	
    }
    void DoublyCircularLinkedList::printAll() {
	    if (empty()) {
		    cout << "The list is empty." << endl;
		    return;
	    }
	    sortByCityName();

	    CNode* temp = head;
	    cout << "cityName in the list:" << endl;
	    do {
		    cout << temp->cityName << endl;
		    temp = temp->next;
	    } while (temp != head);
    }

    void DoublyCircularLinkedList::sortByCityName() {
        if (empty() || head->next == head) {
            return;
        }

        bool sorted = false;
        do {
            sorted = true;
            CNode* current = head;
            do {
                if (current->next != head && current->cityName > current->next->cityName) {
                    // Swap the nodes (locations)
                    CNode* tempNext = current->next;
                    CNode* tempPrev = current->prev;
                    CNode* tempNextNext = tempNext->next;

                    tempNext->next = current;
                    tempNext->prev = tempPrev;
                    current->next = tempNextNext;
                    current->prev = tempNext;

                    tempPrev->next = tempNext;
                    tempNextNext->prev = current;

                    if (head == current) {
                        head = tempNext;
                    }

                    sorted = false;
                }
                current = current->next;
            } while (current != head);
        } while (!sorted);

    }






    bool DoublyCircularLinkedList::insertNewLocation(string location) {
        if (empty()) {
            // DCLL is empty
            CNode* newNode = new CNode;
            newNode->cityName = location;
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
            return true;
        }

        // Check if the location already exists
        CNode* checker = head;
        while (checker->cityName != location &&checker->next != head ) {
            checker = checker->next;
        }

        if (checker->cityName == location) {
            // Location already exists
            return false;
        }

        // Find the correct position to insert in order of cityName
        CNode* temp = head;
        while (temp->next != head && location > temp->next->cityName) {
            temp = temp->next;
        }

        CNode* newNode = new CNode;
        newNode->cityName = location;
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;

        if (location < head->cityName) {
            head = newNode;
        }
        n++;

        return true;
    }
    bool DoublyCircularLinkedList::updateLocation(const string& oldLocation, const string& newLocation) {
        if (empty()) {
            cout << "The list is empty." << endl;
            return false;
        }

        CNode* temp = head;
        do {
            if (temp->cityName == oldLocation) {
                temp->cityName = newLocation;
                return true;
            }
            temp = temp->next;

        } while (temp != head);

        return false;
    }


    bool DoublyCircularLinkedList::isfoundCityName(const string& cityName) const {
        if (empty()) {
            cout << "The list is empty." << endl;
            return false;
        }

        CNode* temp = head;
        do {
            if (temp->cityName == cityName) {
                return true;
            }
            temp = temp->next;
        } while (temp != head);

        return false;
    }
    void DoublyCircularLinkedList::deleteLocation(const string& location) {
        if (empty()) {
            cout << "The list is empty." << endl;
            return;
        }

        CNode* temp = head;
        do {
            if (temp->cityName == location) {
                if (temp->next == temp) {
                    // Only one node in the list
                    delete temp;
                    head = NULL;
                    return;
                }
                else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    if (temp == head) {
                        head = temp->next;
                    }
                    delete temp;
                    return;
                }
            }
            temp = temp->next;
        } while (temp != head);

    
    }
    CNode* DoublyCircularLinkedList::isfoundCityName2Edition(const string& cityName) const {
        if (empty()) {
            cout << "The list is empty." << endl;
            return NULL;
        }

        CNode* temp = head;
        do {
            if (temp->cityName == cityName) {
                return temp;
            }
            temp = temp->next;
        } while (temp != head);

        return NULL;
    }

    bool DoublyCircularLinkedList::isfoundMartyrName(const string& name, const string& location,int x)const {

        CNode* temp = isfoundCityName2Edition(location);
    
            string newName;
        
        int i = temp->martyrVector.findMartyrByName(name);
    
        if (i != -1) {
            if (x==1) {
                Martyr test;
            
                cout << "write his/her new name :";
                getline(cin, newName);
                test.setName(newName);
            
            
                cout << "write his/her age :";
                cin >> newName;
                test.setAge(newName);
                cout << "write his/her Gender :";
                cin >> newName;
                test.setGender(newName);

                temp->martyrVector.updateMartyr(test, name);

                return true;
            }
            else if(x==0) {
                temp->martyrVector.deleteMartyr(name);
            
                return true;
            }
            else {
           
                cout << temp->martyrVector[i];
                
                return true;
            }
        }
        return false;
    }


    int DoublyCircularLinkedList::numberOfMartyrsInLocation(const string& location) {
    
        CNode* temp = isfoundCityName2Edition(location);
        return temp->martyrVector.size();
    

    }

    void DoublyCircularLinkedList::printMartyrInLocation(const string& location)const {
        CNode* temp = isfoundCityName2Edition(location);
        cout << temp->martyrVector;

    }
    void DoublyCircularLinkedList::printStack(const string& location)const {

        CNode* temp = isfoundCityName2Edition(location);
        MyStack<Martyr> tempStack = temp->martyrStack;
        while (!tempStack.empty())
        {
            cout << tempStack.top();
            tempStack.pop();

        }

    }
    int DoublyCircularLinkedList::lowestNumberOfMyatyrInLocation(string& lowest) {
        CNode* temp = head;
        int lowestNumber = numberOfMartyrsInLocation(temp->cityName);
        do {
            if (lowestNumber > numberOfMartyrsInLocation(temp->cityName)) {
                lowestNumber = numberOfMartyrsInLocation(temp->cityName);
                lowest = temp->cityName;
            }
            temp = temp->next;
        } while (temp != head);

        return lowestNumber;
    }
    void DoublyCircularLinkedList::save(ofstream& newFile) {
        CNode* temp = head;
        newFile << "Name" << " , " << "Age" << " , " << " Event location - District" << " , " << "Date of death" << " , " << "Gender";
        do {
            temp->martyrVector.saveInVector(newFile);
            temp = temp->next;

        } while (temp != head);
    }