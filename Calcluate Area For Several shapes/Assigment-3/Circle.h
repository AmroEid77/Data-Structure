#include"iostream";
using namespace std;
#define bie 3.14
class Circle :public Shape {
private:
	double radius;
public:
	Circle(double x,double y,double r ):Shape(x, y,"Circle"), radius(r) {}

	double getArea() const {
		return pow(radius,2)*bie;
	}
	double operator+(const Circle& cir) {
		return getArea() + cir.getArea();
	}

};