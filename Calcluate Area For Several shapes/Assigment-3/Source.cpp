#include"iostream"
#include"Shape.h"
#include"Rectangle.h"
#include"Triangle.h"
#include"Circle.h"
using namespace std;

//non-member function
double getShapeArea(const Shape* shape) {
	return shape->getArea();
}

int main() {
    
    Circle circle(1, 2, 2);
    Rectangle rectangle1(1, 2, 4, 3);
    Rectangle rectangle2(1, 2, 2, 3);
    Triangle triangle(1, 2, 3, 3);

    circle.getCoordinates();
    cout << "Area: " << circle.getArea() << endl<<endl;

    rectangle1.getCoordinates();
    cout << "Area: " << rectangle1.getArea() << endl<<endl;

    triangle.getCoordinates();
    cout << "Area: " << triangle.getArea() <<endl<<endl;

    
    double sumArea =rectangle1+rectangle2;
    cout << "Sum of Rectangle1 and Rectangle2 areas: " << sumArea << endl<<endl;

    // Using the non-member function
    cout << "Area of Triangle: " << getShapeArea(&triangle) << endl<<endl;

    
}
