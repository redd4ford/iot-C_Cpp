//����������� ������� � �������, �� � private
//������ 2 public (string + int), 2 protected
//����������� ������ ������� �� private + protected
//����������� �� ������������ + �����������

#pragma once
#include <string>

class helicopter
{
public:
	helicopter(); //����������� �� �������������
	helicopter(int _year, std::string _name, std::string _color, int _pass, int _speed, int _cap, bool _crane); //����������� �����������
	~helicopter(); //����������


	int getYearOfCreation();
	std::string getName();
	std::string getColor();
	int getSpeed();
	int getPassengers();
	int getCapacity();
	std::string getCrane();

	int createdIn;  //��, ���� ��� ���������������
	std::string color; //����

private:

	std::string name; //����� ��������
	int maxPassengers; //������� ��������
	int maxSpeed; //��������
		
protected:

	int carryingCapacity; //����������������
	bool presenceOfCrane; //�� � ��������������� ����

};