#include"iostream";
using namespace std;


class Rectangle :public Shape {
private:
	double length;
	double width;
public:
	Rectangle(double x,double y,double L , double W ) :Shape(x,y,"Rectangle"), length(L), width(W) {}
	double getArea()const {
		return length * width;
	}
	double operator+(const Rectangle& rec) {
		return getArea() + rec.getArea();
	}
};