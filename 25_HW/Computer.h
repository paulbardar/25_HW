#pragma once
#include <iostream>
#include <string>
using namespace std;


class Computer
{
    string name;
    double frequency;
    int ramSize;
    bool hasDVD;
    double price;

public:
    Computer();
    Computer(string _name, double _frequency, int _ramSiz, bool _dvd, double _price);
    Computer(const Computer& obj);
    Computer& operator =(const Computer& obj);
    ~Computer();

    void setName(const string& _name);
    void setFrequency(double _frequency);
    void setRamSize(int _ramSize);
    void setHasDVD(bool _dvd);
    void setPrice(double _price);

};

