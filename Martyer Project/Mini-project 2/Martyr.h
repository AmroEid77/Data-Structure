#pragma once
#include"iostream"
#include"MyVector.h"
#include"fstream";
using namespace std;


class Martyr {
private:
    string name, age, eventLocationDistrict, dateOfDeath, gender;
public:

    void setName(const string& newName) {
        name = newName;
    }

    void setAge(const string& newAge) {
        age = newAge;
    }

    void setEventLocationDistrict(const string& newLocation) {
        eventLocationDistrict = newLocation;
    }

    void setDateOfDeath(const string& newDate) {
        dateOfDeath = newDate;
    }

    void setGender(const string& newGender) {
        gender = newGender;
    }

    string getName() const {
        return name;
    }

    string getAge() const {
        return age;
    }

    string getEventLocationDistrict() const {
        return eventLocationDistrict;
    }

    string getDateOfDeath() const {
        return dateOfDeath;
    }

    string getGender() const {
        return gender;
    }

    friend ostream& operator<<(ostream& out, const Martyr& martyr) {
    out << "Name: " << martyr.getName() << ", Age: " << martyr.getAge() << ", Event Location District: " << martyr.getEventLocationDistrict() << ", Date of Death: " << martyr.getDateOfDeath() << ", Gender: " << martyr.getGender()<<endl;
    return out;
}


};