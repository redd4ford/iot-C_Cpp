#include "Ellipse.h"

Ellipse::Ellipse() { }

Ellipse::Ellipse(double enteredSemimajorAxis, double enteredSemiminorAxis)
{
	semimajorAxis = enteredSemimajorAxis;
	semiminorAxis = enteredSemiminorAxis;
}

Ellipse::Ellipse(double radius) { semimajorAxis = radius; semiminorAxis = radius; }

Ellipse::~Ellipse() = default;

double Ellipse::getArea() { return area = 3.14159265358979323846 * semimajorAxis*semiminorAxis; }

double Ellipse::getPerimeter() { return perimeter = 4 * ((3.14159265358979323846*semimajorAxis*semiminorAxis + pow(semimajorAxis - semiminorAxis, 2)) / (semimajorAxis + semiminorAxis)); }

std::ostream& operator<< (std::ostream &out, const Ellipse &ellipse)
{
	out << "semimajor axis === " << ellipse.semimajorAxis << " | semiminor axis === " << ellipse.semiminorAxis;
	return out;
}	

std::istream& operator>> (std::istream &in, Ellipse &ellipse)
{
	std::cout << "Enter semimajor axis: ";
	in >> ellipse.semimajorAxis;
	std::cout << "Enter semiminor axis: ";
	in >> ellipse.semiminorAxis;
	return in;
}

bool operator==(Ellipse & ellipse1, Ellipse & ellipse2)
{
	if (ellipse1.semimajorAxis == ellipse2.semimajorAxis && ellipse1.semiminorAxis == ellipse2.semiminorAxis) {
		return true;
	}
	else {
		return false;
	}
}

bool operator> (Ellipse &ellipse1, Ellipse &ellipse2)
{
	if (ellipse1.area > ellipse2.area) {
		return true;
}
	else {
		return false;
}
}

bool operator< (Ellipse &ellipse1, Ellipse &ellipse2)
{
	if (ellipse1.area < ellipse2.area) {
		return true;
	}
	else {
		return false;
	}
}

void operator*= (Ellipse &enteredEllipse, double numberToMultiplyBy)
{
	enteredEllipse.semimajorAxis *= numberToMultiplyBy;
	enteredEllipse.semiminorAxis *= numberToMultiplyBy;
}