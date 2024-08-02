#include"iostream";
using namespace std;


class Shape {
protected:
	double x;
	double y;
	string name;
public:
	Shape(double x,double y,string Name):x(x),y(y),name(Name){}

	virtual void getCoordinates()const {
		cout << name << endl;
		cout << "Center Coordinates : (" << x << ", " << y << ")" << endl;
	}
	virtual double getArea()const = 0;


};