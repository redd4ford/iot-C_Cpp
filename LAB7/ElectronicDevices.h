#pragma once
#include <string>

class ElectronicDevices
{
public:
	ElectronicDevices(std::string name, double price, std::string prod, std::string color, double weigth, double height, double length, int power, int powcon);
	virtual ~ElectronicDevices();

	virtual void getInformation() = 0;
	
protected:

	virtual std::string getName();
	virtual std::string getColor();
	virtual std::string getSize();
	virtual int getPower();
	virtual int getPowerConsumption();
	virtual double getPrice();
	virtual std::string getProducer();

	virtual void setName(std::string n);
	virtual void setColor(std::string c);
	virtual void setSize(double w, double h, double l);
	virtual void setPower(int p);
	virtual void setPowerConsumption(int pc);
	virtual void setPrice(double pric);
	virtual void setProducer(std::string prod);
	
	std::string name;
	std::string color;
	std::string size = "";
	int power;
	int powerConsumption;
	double price;
	std::string producer;
};

class Analog : protected ElectronicDevices
{
public:
	Analog(std::string name, double price, std::string prod, std::string color, double weigth, double height, double length, int power, int powcon, bool sound, int dcv, int acv);
	~Analog();

	void getInformation() override;

protected:
	bool getSound();
	std::string getVoltage();
	void setSound(bool s);
	void setVoltage(int dcv, int acv);

	bool hasSound;
	int DCvoltage;
	int ACvoltage;
};

class OperationalAmplifier : protected Analog
{
public:
	OperationalAmplifier(std::string name, double price, std::string prod, std::string color, double weigth, double height, double length, int power, int powcon, bool sound, int dcv, int acv, int channel, int lowt, int uppt);
	OperationalAmplifier();
	~OperationalAmplifier();

	void getInformation() override;
	
private:
	int getNumberOfChannels();
	std::string getTemperatureRange();
	void setNumberOfChannels(int n);
	void setTemperatureRange(int low, int upp);

	int numberOfChannels;
	std::string temperatureRange;
};

class Digital : protected ElectronicDevices
{
public:
	Digital(std::string name, double price, std::string prod, std::string color, double weigth, double height, double length, int power, int powcon, bool display, int lowt, int uppt);
	~Digital();

	void getInformation() override;
	
protected:
	int getDisplay();
	std::string getTemperatureRange();
	virtual void setDisplay(bool d);
	void setTemperatureRange(int low, int upp);

	bool hasDisplay = false;
	std::string temperatureRange;
};

class BinaryDecimalDecoder : protected Digital
{
public:
	BinaryDecimalDecoder(std::string name, double price, std::string prod, std::string color, double weigth, double height, double length, int power, int powcon, int inv, int ouv, int inc, int ouc, int pdt, int lowt, int uppt);
	BinaryDecimalDecoder();
	~BinaryDecimalDecoder();

	void getInformation() override;
	
private:
	std::string getVoltage();
	std::string getCurrent();
	int getPropagationDelaytime();

	void setDisplay(bool d) override
	{
		hasDisplay = false;
	}
	void setVoltage(int inv, int ouv);
	void setCurrent(int inc, int ouc);
	void setPropagationDelayTime(int pdt);

	
	int inputVoltage;
	int outputVoltage;
	int inputCurrent;
	int outputCurent;
	int propagationDelayTimeInMS;
};

class BinaryAdder : protected Digital
{
public:
	BinaryAdder(std::string name, double price, std::string prod, std::string color, double weigth, double height, double length, int power, int powcon, int loadcap, int pulsdur, int lowt, int uppt);
	~BinaryAdder();

	void getInformation() override;

private:

	int getLoadCapacity();
	int getInputPulseDuration();
	void setDisplay(bool d) override
	{
		hasDisplay = false;
	}
	void setLoadCapacity(int loadcap);
	void setInputPulseDuration(int pulsdur);
	
	int loadCapacityInPicofarade;
	int inputPulseDuration;
};

class Impulse : protected ElectronicDevices
{
public:
	Impulse(std::string name, double price, std::string prod, std::string color, double weigth, double height, double length, int power, int powcon, int lim, int low, int upp);
	~Impulse();

	void getInformation() override;
		
protected:
	int getCurrentLimit();
	std::string getRange();
	void setCurrentLimit(int lim);
	void setRange(int low, int upp);

	int currentLimitInAmpere;
	std::string rangeGHz;
};

class CurrentGenerator : protected Impulse
{
public:
	CurrentGenerator(std::string name, double price, std::string prod, std::string color, double weigth, double height, double length, int power, int powcon, int lim, int low, int upp, int numofph);
	~CurrentGenerator();

	void getInformation() override;
	
private:
	int getNumberOfPhases();
	void setNumberOfPhases(int numofph);
	int numberOfPhases;
};

class VoltageGenerator : protected Impulse
{
public:
	VoltageGenerator(std::string name, double price, std::string prod, std::string color, double weigth, double height, double length, int power, int powcon, int lim, int low, int upp, int inv, int ouv);
	~VoltageGenerator();

	void getInformation() override;

private:
	std::string getVoltage();
	void setVoltage(int inv, int ouv);
	
	int inputVoltage;
	int outputVoltage;
};