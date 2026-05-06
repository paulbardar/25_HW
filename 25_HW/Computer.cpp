#include "Computer.h"

Computer::Computer()
{
    name = "Undefined";
    frequency = 0.0;
    ramSize = 0;
    hasDVD = false;
    price = 0.0;
}

Computer::Computer(string _name, double _frequency, int _ramSize, bool _hasDVD, double _price)
{
    name = _name; 
    frequency = _frequency;
    ramSize = _ramSize;
    hasDVD = _hasDVD;
    price = _price;
}

Computer::Computer(const Computer& obj)
{
    this->name = obj.name;
    this->frequency = obj.frequency;
    this->ramSize = obj.ramSize;
    this->hasDVD = obj.hasDVD;
    this->price = obj.price;
}

Computer& Computer::operator=(const Computer& obj)
{
    if (this == &obj) {
        return *this;
    }
    this->name = obj.name;
    this->frequency = obj.frequency;
    this->ramSize = obj.ramSize;
    this->hasDVD = obj.hasDVD;
    this->price = obj.price;

    return *this;
}

Computer::~Computer()
{
    //cout << "Computer '" << name << "' was deleted" << endl;
}

void Computer::setName(const string& _name)
{
    name = _name;
}

void Computer::setFrequency(double _frequency)
{
    if (_frequency > 0) {
        frequency = _frequency;
    }
    else {
        cout << "Error: setFrequency!\n";
    }
}

void Computer::setRamSize(int _ramSize)
{
    if (_ramSize > 0) {
        ramSize = _ramSize;
    }
    else {
        cout << "Error: setRamSize!\n";
    }
}

void Computer::setHasDVD(bool _dvd)
{
    hasDVD = _dvd;
}

void Computer::setPrice(double _price)
{
    if (_price > 0) {
        price = _price;
    }
    else {
        cout << "Error: setPrice!\n";
    }
}

string Computer::getName() const
{
    return name;
}

double Computer::getFrequency() const
{
    return frequency;
}

int Computer::getRamSize() const
{
    return ramSize;
}

bool Computer::getHasDVD() const
{
    return hasDVD;
}

double Computer::getPrice() const
{
    return price;
}

void Computer::showInfo() const
{
    cout << "[Computer: " << name << " | " << frequency << "GHz | RAM: "
        << ramSize << "GB | DVD: " << (hasDVD ? "YES" : "No")
        << " | " << price << " грн ]" << endl;
}




