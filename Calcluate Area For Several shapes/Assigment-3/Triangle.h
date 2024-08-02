#include"iostream";
using namespace std;

class Triangle:public Shape {
private:
	double length;
	double height;
public:
	Triangle(double x, double y , double L, double H ) :Shape(x, y,"Triangle"), length(L), height(H) {}

	double getArea()const {
		return 0.5*length * height;
	}
	double operator+(const Triangle& tri) {
		return getArea() + tri.getArea();
	}

};