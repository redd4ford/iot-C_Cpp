//створити конструктор по замовчуванню і конструктор, що ініціалізує
//реалізувати деструктор
//реалізувати методи доступу до даних (наприклад для поля name – getName())

#include "helicopter.h"
#include <cstdlib>
#include <utility>

helicopter::helicopter()	//конструктор за замовчуванням
{
	createdIn = rand() % 39 + 1980;
	name = "STAR # " + std::to_string(rand() % 18 + 1);
	color = "black";
	maxPassengers = 5;
	maxSpeed = 150;
	carryingCapacity = 10;
	presenceOfCrane = false;
}

helicopter::helicopter(int _year, std::string _name, std::string _color, int _pass, int _speed, int _cap, bool _crane)	//конструктор, який ініціалізує
{
	createdIn = _year;
	name = std::move(_name);
	color = std::move(_color);
	maxPassengers = _pass;
	maxSpeed = _speed;
	carryingCapacity = _cap;
	presenceOfCrane = _crane;
}


helicopter::~helicopter()	//деструктор
= default;

int helicopter::getYearOfCreation()
{
	return createdIn;
}

std::string helicopter::getName()
{
	return name;
}


std::string helicopter::getColor()
{
	return color;
}

int helicopter::getPassengers()
{
	return maxPassengers;
}

int helicopter::getSpeed()
{
	return maxSpeed;
}

int helicopter::getCapacity()
{
	return carryingCapacity;
}

std::string helicopter::getCrane()
{
	std::string answer;

	if (presenceOfCrane == true)
		answer = "yes";
	else
		answer = "no";

	return answer;
}