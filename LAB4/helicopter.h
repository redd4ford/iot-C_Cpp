//представляє сутності з таблиці, які є private
//додати 2 public (string + int), 2 protected
//ініціалізація методів доступу до private + protected
//конструктор по замовчуванню + ініціалізатор

#pragma once
#include <string>

class helicopter
{
public:
	helicopter(); //конструктор за замовчуванням
	helicopter(int _year, std::string _name, std::string _color, int _pass, int _speed, int _cap, bool _crane); //конструктор ініціалізації
	~helicopter(); //деструктор


	int getYearOfCreation();
	std::string getName();
	std::string getColor();
	int getSpeed();
	int getPassengers();
	int getCapacity();
	std::string getCrane();

	int createdIn;  //рік, коли був сконструйований
	std::string color; //колір

private:

	std::string name; //назва вертоліту
	int maxPassengers; //кількість пасажирів
	int maxSpeed; //швидкість
		
protected:

	int carryingCapacity; //вантажопідйомність
	bool presenceOfCrane; //чи є вантажопідйомний кран

};