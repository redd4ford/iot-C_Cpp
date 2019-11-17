#include "ElectronicDevices.h"
#include <utility>
#include <iostream>


ElectronicDevices::ElectronicDevices(std::string name, double price, std::string prod, std::string color, double weigth,
	double height, double length, int power, int powcon)
{
	setName(name);
	setPrice(price);
	setProducer(prod);
	setColor(color);
	setSize(weigth, height, length);
	setPower(power);
	setPowerConsumption(powcon);
}
ElectronicDevices::~ElectronicDevices()
= default;

void ElectronicDevices::setName(std::string n)
{
	name = std::move(n);
}

void ElectronicDevices::setColor(std::string c)
{
	color = std::move(c);
}

void ElectronicDevices::setSize(double w, double h, double l)
{
	size = std::to_string(w) + " x " + std::to_string(h) + " x " + std::to_string(h);
}

void ElectronicDevices::setPower(int p)
{
	power = p;
}

void ElectronicDevices::setPowerConsumption(int pc)
{
	powerConsumption = pc;
}

void ElectronicDevices::setPrice(double pric)
{
	price = pric;
}

void ElectronicDevices::setProducer(std::string prod)
{
	producer = std::move(prod);
}

std::string ElectronicDevices::getName()
{
	return name;
}

std::string ElectronicDevices::getColor()
{
	return color;
}

std::string ElectronicDevices::getSize()
{
	return size;
}

int ElectronicDevices::getPower()
{
	return power;
}

int ElectronicDevices::getPowerConsumption()
{
	return powerConsumption;
}

double ElectronicDevices::getPrice()
{
	return price;
}

std::string ElectronicDevices::getProducer()
{
	return producer;
}



Analog::Analog(std::string name, double price, std::string prod, std::string color, double weigth, double height, double length,
	int power, int powcon, bool sound, int dcv, int acv) : ElectronicDevices(name, price, prod, color, weigth, height, length, power, powcon)
{
	setSound(sound);
	setVoltage(dcv, acv);
}


Analog::~Analog()
= default;

void Analog::getInformation()
{
	std::cout << "DEVICE CLASS                   | ELECTRONIC DEVICES => ANALOG" << std::endl;
	std::cout << "DEVICE NAME                    | " << getName() << std::endl;
	std::cout << "DEVICE PRICE                   | " << getPrice() << std::endl;
	std::cout << "DEVICE PRODUCER                | " << getProducer() << std::endl;
	std::cout << "DEVICE COLOR                   | " << getColor() << std::endl;
	std::cout << "DEVICE SIZE                    | " << getSize() << std::endl;
	std::cout << "DEVICE POWER                   | " << getPower() << std::endl;
	std::cout << "DEVICE POWER CONSUMPTION       | " << getPowerConsumption() << std::endl;
	std::cout << "CAN THIS DEVICE MAKE SOUNDS?   | " << getSound() << std::endl;
	std::cout << "VOLTAGE                        | " << getVoltage() << std::endl;
}


void Analog::setSound(bool s)
{
	hasSound = s;
}

void Analog::setVoltage(int dcv, int acv)
{
	DCvoltage = dcv;
	ACvoltage = acv;
}

bool Analog::getSound()
{
	return hasSound;
}

std::string Analog::getVoltage()
{
	std::string voltage = "DCvoltage = " + std::to_string(DCvoltage) + "; ACvoltage = " + std::to_string(ACvoltage);
	return voltage;
}



OperationalAmplifier::OperationalAmplifier(std::string name, double price, std::string prod, std::string color, double weigth, double height, double length,
	int power, int powcon, bool sound, int dcv, int acv, int channel, int lowt, int uppt) : Analog(name, price, prod, color, weigth, height, length, power, powcon, sound, dcv, acv)
{
	setNumberOfChannels(channel);
	setTemperatureRange(lowt, uppt);
}


OperationalAmplifier::~OperationalAmplifier()
= default;


void OperationalAmplifier::getInformation()
{
	std::cout << "DEVICE CLASS                   | ELECTRONIC DEVICES => ANALOG => OPERATIONAL AMPLIFIER" << std::endl;
	std::cout << "DEVICE NAME                    | " << getName() << std::endl;
	std::cout << "DEVICE PRICE                   | " << getPrice() << std::endl;
	std::cout << "DEVICE PRODUCER                | " << getProducer() << std::endl;
	std::cout << "DEVICE COLOR                   | " << getColor() << std::endl;
	std::cout << "DEVICE SIZE                    | " << getSize() << std::endl;
	std::cout << "DEVICE POWER                   | " << getPower() << std::endl;
	std::cout << "DEVICE POWER CONSUMPTION       | " << getPowerConsumption() << std::endl;
	std::cout << "CAN THIS DEVICE MAKE SOUNDS?   | " << getSound() << std::endl;
	std::cout << "VOLTAGE                        | " << getVoltage() << std::endl;
	std::cout << "NUMBER OF CHANNELS             | " << getNumberOfChannels() << std::endl;
	std::cout << "TEMPEREATURE RANGE             | " << getTemperatureRange() << std::endl;
}



void OperationalAmplifier::setNumberOfChannels(int n)
{
	numberOfChannels = n;
}

void OperationalAmplifier::setTemperatureRange(int low, int upp)
{
	if (low > upp)
	{
		int temp = upp;
		upp = low;
		low = temp;
	}
	temperatureRange = std::to_string(low) + " ... " + std::to_string(upp);
}

int OperationalAmplifier::getNumberOfChannels()
{
	return numberOfChannels;
}

std::string OperationalAmplifier::getTemperatureRange()
{
	return temperatureRange;
}



Digital::Digital(std::string name, double price, std::string prod, std::string color, double weigth, double height, double length,
	int power, int powcon, bool display, int lowt, int uppt) : ElectronicDevices(name, price, prod, color, weigth, height, length, power, powcon)
{
	setDisplay(display);
	setTemperatureRange(lowt, uppt);
}


Digital::~Digital()
= default;


void Digital::getInformation()
{
	std::cout << "DEVICE CLASS                   | ELECTRONIC DEVICES => DIGITAL" << std::endl;
	std::cout << "DEVICE NAME                    | " << getName() << std::endl;
	std::cout << "DEVICE PRICE                   | " << getPrice() << std::endl;
	std::cout << "DEVICE PRODUCER                | " << getProducer() << std::endl;
	std::cout << "DEVICE COLOR                   | " << getColor() << std::endl;
	std::cout << "DEVICE SIZE                    | " << getSize() << std::endl;
	std::cout << "DEVICE POWER                   | " << getPower() << std::endl;
	std::cout << "DEVICE POWER CONSUMPTION       | " << getPowerConsumption() << std::endl;
	std::cout << "DOES THIS DEVICE HAVE DISPLAY? | " << getDisplay() << std::endl;
	std::cout << "TEMPERATURE RANGE              | " << getTemperatureRange() << std::endl;
}


void Digital::setDisplay(bool d)
{
	hasDisplay = d;
}

void Digital::setTemperatureRange(int low, int upp)
{
	if (low > upp)
	{
		int temp = upp;
		upp = low;
		low = temp;
	}
	temperatureRange = std::to_string(low) + " ... " + std::to_string(upp);
}

int Digital::getDisplay()
{
	return hasDisplay;
}

std::string Digital::getTemperatureRange()
{
	return temperatureRange;
}



BinaryDecimalDecoder::BinaryDecimalDecoder(std::string name, double price, std::string prod, std::string color, double weigth, double height, double length, 
	int power, int powcon, int inv, int ouv, int inc, int ouc, int pdt, int lowt, int uppt) : Digital (name, price, prod, color, weigth, height, length, power, powcon, hasDisplay, lowt, uppt)
{
	setVoltage(inv, ouv);
	setCurrent(inc, ouc);
	setPropagationDelayTime(pdt);
}


BinaryDecimalDecoder::~BinaryDecimalDecoder()
= default;



void BinaryDecimalDecoder::getInformation()
{
	std::cout << "DEVICE CLASS                   | ELECTRONIC DEVICES => DIGITAL => BINARY DECIMAL DECODER" << std::endl;
	std::cout << "DEVICE NAME                    | " << getName() << std::endl;
	std::cout << "DEVICE PRICE                   | " << getPrice() << std::endl;
	std::cout << "DEVICE PRODUCER                | " << getProducer() << std::endl;
	std::cout << "DEVICE COLOR                   | " << getColor() << std::endl;
	std::cout << "DEVICE SIZE                    | " << getSize() << std::endl;
	std::cout << "DEVICE POWER                   | " << getPower() << std::endl;
	std::cout << "DEVICE POWER CONSUMPTION       | " << getPowerConsumption() << std::endl;
	std::cout << "DOES THIS DEVICE HAVE DISPLAY? | " << getDisplay() << std::endl;
	std::cout << "TEMPERATURE RANGE              | " << getTemperatureRange() << std::endl;
	std::cout << "VOLTAGE                        | " << getVoltage() << std::endl;
	std::cout << "CURRENT                        | " << getCurrent() << std::endl;
	std::cout << "PROPAGATION DELAY TIME         | " << getPropagationDelaytime() << std::endl;
}


void BinaryDecimalDecoder::setVoltage(int inv, int ouv)
{
	inputVoltage = inv;
	outputVoltage = ouv;
}

void BinaryDecimalDecoder::setCurrent(int inc, int ouc)
{
	inputCurrent = inc;
	outputCurent = ouc;
}

void BinaryDecimalDecoder::setPropagationDelayTime(int pdt)
{
	propagationDelayTimeInMS = pdt;
}

std::string BinaryDecimalDecoder::getVoltage()
{
	std::string voltage = "Input Voltage = " + std::to_string(inputVoltage) + "; Output Voltage = " + std::to_string(outputVoltage);
	return voltage;
}

std::string BinaryDecimalDecoder::getCurrent()
{
	std::string current = "Input Current = " + std::to_string(inputCurrent) + "; Output Current = " + std::to_string(outputCurent);
	return current;
}

int BinaryDecimalDecoder::getPropagationDelaytime()
{
	return propagationDelayTimeInMS;
}



BinaryAdder::BinaryAdder(std::string name, double price, std::string prod, std::string color, double weigth, double height, double length,
	int power, int powcon, int loadcap, int pulsdur, int lowt, int uppt) : Digital (name, price, prod, color, weigth, height, length, power, powcon, hasDisplay, lowt, uppt)
{
	setLoadCapacity(loadcap);
	setInputPulseDuration(pulsdur);

}

BinaryAdder::~BinaryAdder()
= default;


void BinaryAdder::getInformation()
{
	std::cout << "DEVICE CLASS                   | ELECTRONIC DEVICES => DIGITAL => BINARY ADDER" << std::endl;
	std::cout << "DEVICE NAME                    | " << getName() << std::endl;
	std::cout << "DEVICE PRICE                   | " << getPrice() << std::endl;
	std::cout << "DEVICE PRODUCER                | " << getProducer() << std::endl;
	std::cout << "DEVICE COLOR                   | " << getColor() << std::endl;
	std::cout << "DEVICE SIZE                    | " << getSize() << std::endl;
	std::cout << "DEVICE POWER                   | " << getPower() << std::endl;
	std::cout << "DEVICE POWER CONSUMPTION       | " << getPowerConsumption() << std::endl;
	std::cout << "DOES THIS DEVICE HAVE DISPLAY? | " << getDisplay() << std::endl;
	std::cout << "TEMPERATURE RANGE              | " << getTemperatureRange() << std::endl;
	std::cout << "LOAD CAPACITY                  | " << getLoadCapacity() << std::endl;
	std::cout << "INPUT PULSE DURATION           | " << getInputPulseDuration() << std::endl;
}



void BinaryAdder::setLoadCapacity(int loadcap)
{
	loadCapacityInPicofarade = loadcap;
}

void BinaryAdder::setInputPulseDuration(int pulsdur)
{
	inputPulseDuration = pulsdur;
}

int BinaryAdder::getLoadCapacity()
{
	return loadCapacityInPicofarade;
}

int BinaryAdder::getInputPulseDuration()
{
	return inputPulseDuration;
}



Impulse::Impulse(std::string name, double price, std::string prod, std::string color, double weigth, double height, double length,
	int power, int powcon, int lim, int low, int upp) : ElectronicDevices(name, price, prod, color, weigth, height, length, power, powcon)
{
	setCurrentLimit(lim);
	setRange(low, upp);
}


Impulse::~Impulse()
= default;



void Impulse::getInformation()
{
	std::cout << "DEVICE CLASS                   | ELECTRONIC DEVICES => IMPULSE" << std::endl;
	std::cout << "DEVICE NAME                    | " << getName() << std::endl;
	std::cout << "DEVICE PRICE                   | " << getPrice() << std::endl;
	std::cout << "DEVICE PRODUCER                | " << getProducer() << std::endl;
	std::cout << "DEVICE COLOR                   | " << getColor() << std::endl;
	std::cout << "DEVICE SIZE                    | " << getSize() << std::endl;
	std::cout << "DEVICE POWER                   | " << getPower() << std::endl;
	std::cout << "DEVICE POWER CONSUMPTION       | " << getPowerConsumption() << std::endl;
	std::cout << "CURRENT LIMIT                  | " << getCurrentLimit() << std::endl;
	std::cout << "RANGE                          | " << getRange() << std::endl;
}



void Impulse::setCurrentLimit(int lim)
{
	currentLimitInAmpere = lim;
}

void Impulse::setRange(int low, int upp)
{
	if (low > upp)
	{
		int temp = upp;
		upp = low;
		low = temp;
	}
	rangeGHz = std::to_string(low) + " ... " + std::to_string(upp);
}

int Impulse::getCurrentLimit()
{
	return currentLimitInAmpere;
}

std::string Impulse::getRange()
{
	return rangeGHz;
}



CurrentGenerator::CurrentGenerator(std::string name, double price, std::string prod, std::string color, double weigth, double height, double length,
	int power, int powcon, int lim, int low, int upp, int numofph) : Impulse(name, price, prod, color, weigth, height, length, power, powcon, lim, low, upp)
{
	setNumberOfPhases(numofph);
}


CurrentGenerator::~CurrentGenerator()
= default;



void CurrentGenerator::getInformation()
{
	std::cout << "DEVICE CLASS                   | ELECTRONIC DEVICES => IMPULSE => CURRENT GENERATOR" << std::endl;
	std::cout << "DEVICE NAME                    | " << getName() << std::endl;
	std::cout << "DEVICE PRICE                   | " << getPrice() << std::endl;
	std::cout << "DEVICE PRODUCER                | " << getProducer() << std::endl;
	std::cout << "DEVICE COLOR                   | " << getColor() << std::endl;
	std::cout << "DEVICE SIZE                    | " << getSize() << std::endl;
	std::cout << "DEVICE POWER                   | " << getPower() << std::endl;
	std::cout << "DEVICE POWER CONSUMPTION       | " << getPowerConsumption() << std::endl;
	std::cout << "CURRENT LIMIT                  | " << getCurrentLimit() << std::endl;
	std::cout << "RANGE                          | " << getRange() << std::endl;
	std::cout << "NUMBER OF PHASES               | " << getNumberOfPhases() << std::endl;
}


void CurrentGenerator::setNumberOfPhases(int numofph)
{
	numberOfPhases = numofph;
}

int CurrentGenerator::getNumberOfPhases()
{
	return numberOfPhases;
}



VoltageGenerator::VoltageGenerator(std::string name, double price, std::string prod, std::string color, double weigth, double height, double length,
	int power, int powcon, int lim, int low, int upp, int inv, int ouv) : Impulse(name, price, prod, color, weigth, height, length, power, powcon, lim, low, upp)
{
	setVoltage(inv, ouv);
}


VoltageGenerator::~VoltageGenerator()
= default;



void VoltageGenerator::getInformation()
{
	std::cout << "DEVICE CLASS                   | ELECTRONIC DEVICES => IMPULSE => VOLTAGE GENERATOR" << std::endl;
	std::cout << "DEVICE NAME                    | " << getName() << std::endl;
	std::cout << "DEVICE PRICE                   | " << getPrice() << std::endl;
	std::cout << "DEVICE PRODUCER                | " << getProducer() << std::endl;
	std::cout << "DEVICE COLOR                   | " << getColor() << std::endl;
	std::cout << "DEVICE SIZE                    | " << getSize() << std::endl;
	std::cout << "DEVICE POWER                   | " << getPower() << std::endl;
	std::cout << "DEVICE POWER CONSUMPTION       | " << getPowerConsumption() << std::endl;
	std::cout << "CURRENT LIMIT                  | " << getCurrentLimit() << std::endl;
	std::cout << "RANGE                          | " << getRange() << std::endl;
	std::cout << "VOLTAGE                        | " << getVoltage() << std::endl;
}



void VoltageGenerator::setVoltage(int inv, int ouv)
{
	inputVoltage = inv;
	outputVoltage = ouv;
}


std::string VoltageGenerator::getVoltage()
{
	std::string voltage = "Input Voltage = " + std::to_string(inputVoltage) + "; Output Voltage = " + std::to_string(outputVoltage);
	return voltage;
}

