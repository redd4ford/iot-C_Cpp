//здійснити ініціалізацію 3 об’єктів заданого класу
//реалізувати виведення значень всіх полів (приватних, захищених та публічних) за допомогою cout в стандартний вивід.

#include <iostream>
#include "helicopter.h"

int main()
{
	helicopter hel_a(1990, "ARROW #6", "blue", 7, 210, 50, true);
	helicopter hel_b(1996, "LUMBERJACK", "black", 4, 180, 80, true);
	helicopter hel_c(2006, "BLITZKRIEG Z-01", "green", 12, 320, 20, false);
		
	std::cout << hel_a.getYearOfCreation() << " // " << hel_a.getName() << std::endl;
	std::cout << "color === " << hel_a.getColor() << std::endl;
	std::cout << "max passengers === " << hel_a.getPassengers() << std::endl;
	std::cout << "max speed (kmph) === " << hel_a.getSpeed() << std::endl;
	std::cout << "carrying capacity (tons) === " << hel_a.getCapacity() << std::endl;
	std::cout << "presence of a crane == " << hel_a.getCrane() << std::endl << std::endl;

	std::cout << hel_b.getYearOfCreation() << " // " << hel_b.getName() << std::endl;
	std::cout << "color === " << hel_b.getColor() << std::endl;
	std::cout << "max passengers === " << hel_b.getPassengers() << std::endl;
	std::cout << "max speed (kmph) === " << hel_b.getSpeed() << std::endl;
	std::cout << "carrying capacity (tons) === " << hel_b.getCapacity() << std::endl;
	std::cout << "presence of a crane == " << hel_b.getCrane() << std::endl << std::endl;

	std::cout << hel_c.getYearOfCreation() << " // " << hel_c.getName() << std::endl;
	std::cout << "color === " << hel_c.getColor() << std::endl;
	std::cout << "max passengers === " << hel_c.getPassengers() << std::endl;
	std::cout << "max speed (kmph) === " << hel_c.getSpeed() << std::endl;
	std::cout << "carrying capacity (tons) === " << hel_c.getCapacity() << std::endl;
	std::cout << "presence of a crane == " << hel_c.getCrane() << std::endl << std::endl;
	
	system("pause");
	return 0;
}