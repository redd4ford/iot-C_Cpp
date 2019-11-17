#include "ElectronicDevices.h"
#include <iostream>

int main()
{
	Analog Multimeter("Dial multimeter 8801", 230.75, "Ukraine", "orange", 2.0, 9.15, 6.0, 500, 2, true, 5, 3);
	OperationalAmplifier Amplifier("Operational Amplifier LM224N", 6.50, "Ukraine", "black", 0.35, 0.55, 0.9, 360, 1, false, 2, 2, 4, -40, 125);
	Digital Thermometer("Digital Thermometer", 166.52, "USA", "white", 2.0, 17.0, 4.9, 100, 17, true, -30, +45);
	BinaryDecimalDecoder Decoder("Binary Decimal Decoder K561ID1", 8.08, "USSR", "black", 0.6, 0.8, 0.21, 200, 1, 200, 1, 0.4, 0.45, 290, -45, +25);
	BinaryAdder Adder("Binary Adder K155IM2 DIP14", 6.25, "USSR", "black", 0.55, 0.91, 0.3, 200, 1, 15, 150, -45, +25);
	Impulse CounterStopper("Pulse Buck Converter DC-DC", 250.00, "UKC", "yellow", 0.12, 0.11, 0.042, 360, 12, 30, 20, 40);
	CurrentGenerator PetrolGenerator("Daewoo GDA 3500", 8000.00, "Korea", "red", 10, 3, 7, 3200, 0, 400, 60, 230, 1);
	VoltageGenerator GasGenerator("GREENPOWER CC3000 LPG/NG-B", 8400.00, "China", "green", 0.7, 0.57, 0.535, 2600, 1, 220, 50, 220, 5, 200);
	
	Multimeter.getInformation();
	std::cout << std::endl << "==================================================================" << std::endl << std::endl;
	Amplifier.getInformation();
	std::cout << std::endl << "==================================================================" << std::endl << std::endl;
	Thermometer.getInformation();
	std::cout << std::endl << "==================================================================" << std::endl << std::endl;
	Decoder.getInformation();
	std::cout << std::endl << "==================================================================" << std::endl << std::endl;
	Adder.getInformation();
	std::cout << std::endl << "==================================================================" << std::endl << std::endl;
	CounterStopper.getInformation();
	std::cout << std::endl << "==================================================================" << std::endl << std::endl;
	PetrolGenerator.getInformation();
	std::cout << std::endl << "==================================================================" << std::endl << std::endl;
	GasGenerator.getInformation();
	std::cout << std::endl << std::endl;

	system("pause");
	return 0;
}