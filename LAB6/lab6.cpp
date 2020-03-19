#include "Ellipse.h"

int main()
{
	Ellipse el1, el2;
	double numberToMultiplyBy;
	double circleRadius;

	std::cout << "Enter the values for the first ellipse: " << std::endl;
	std::cin >> el1;
	std::cout << "Enter the values for the second ellipse: " << std::endl;
	std::cin >> el2;
	system("cls");
	std::cout << "Your first ellipse: " << std::endl << el1;
	std::cout << std::endl << "Area === " << el1.getArea() << " | Perimeter === " << el1.getPerimeter() << std::endl << std::endl;
	std::cout << "Your second ellipse: " << std::endl << el2;
	std::cout << std::endl << "Area === " << el2.getArea() << " | Perimeter === " << el2.getPerimeter() << std::endl << std::endl << "==============" << std::endl << std::endl;

	std::cout << "Let's compare them!" << std::endl;
	std::cout << "Is the area of the first ellipse greater than the area of the second?";
	if (el1 > el2) { std::cout << " Yes."; }
	else { std::cout << " No."; }
	std::cout << std::endl << "Is the area of the first ellipse smaller than the area of the second?";
	if (el1 < el2) { std::cout << " Yes."; }
	else { std::cout << " No."; }

	std::cout << std::endl << std::endl << "Now let's create third ellipse that will be a circle. Enter its radius: ";
	std::cin >> circleRadius;
	
	Ellipse el3(circleRadius);
	
	std::cout << std::endl << "So we have: " << std::endl << el3;
	std::cout << std::endl << "Let's multiply the semimajor and semiminor axes by some number. Enter it: ";
	std::cin >> numberToMultiplyBy;
	el3 *= numberToMultiplyBy;
	std::cout << std::endl << "Your circle now looks like: " << std::endl << el3 << std::endl;
	std::cout << std::endl << "Area === " << el3.getArea() << " | Perimeter === " << el3.getPerimeter() << std::endl << std::endl << "==============" << std::endl << std::endl;
	
	system("pause");
	return 0;
	
}