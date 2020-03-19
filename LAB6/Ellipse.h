#pragma once
#include <iostream>

class Ellipse
{
public:
	Ellipse();
	Ellipse(double semimajorAxis, double semiminorAxis);
	Ellipse(double radius);
	~Ellipse();

	double getArea();
	double getPerimeter();

	friend std::ostream& operator<< (std::ostream &out, const Ellipse &ellipse);
	friend std::istream& operator>> (std::istream &in, Ellipse &ellipse);
	friend bool operator== (Ellipse &ellipse1, Ellipse &ellipse2);
	friend bool operator> (Ellipse &ellipse1, Ellipse &ellipse2);
	friend bool operator< (Ellipse &ellipse1, Ellipse &ellipse2);
	friend void operator*= (Ellipse &ellipse, double someNumber);
	
private:
	double semimajorAxis;
	double semiminorAxis;
	double area;
	double perimeter;
};