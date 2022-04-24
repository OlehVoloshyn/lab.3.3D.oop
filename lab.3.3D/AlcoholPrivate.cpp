#include "AlcoholPrivate.h"
#include <iostream>
#include<sstream>
using namespace std;

void AlcoholPrivate::setStrength(double strength)
{
	if (strength >= 0 && strength <= 99)
		this->strength = strength;
	else
	{
		cout << "incorrect parameters" << endl;
		exit(1);
	}
}

AlcoholPrivate::AlcoholPrivate(const string name, const double density, const double strength)
{
	setStrength(strength);
	setName(name);
	setDensity(density);
}

AlcoholPrivate::AlcoholPrivate(const AlcoholPrivate& s)
{
	strength = s.strength;
	setName(s.getName());
	setDensity(s.getDensity());
}

void AlcoholPrivate::changeStrength(Liquid l)
{
	double strength;
	cout << endl;
	//l.changeDensity();
	cout << "new strength = "; cin >> strength;
	setStrength(strength);
}

AlcoholPrivate::operator string() const
{
	Liquid l;
	l.setName(getName());
	l.setDensity(getDensity());
	stringstream ss;
	ss << "strength = " << strength << endl;
	return string(l) + ss.str();
}

ostream& operator<<(ostream& out, const AlcoholPrivate& s)
{
	out << string(s);
	return out;
}

istream& operator>>(istream& in, AlcoholPrivate& s)
{
	double strength;
	Liquid l;
	cout << endl;
	cout << "liquid =  "; in >> l;
	cout << "strength =  "; in >> strength;
	s.setStrength(strength);
	s.setName(l.getName());
	s.setDensity(l.getDensity());
	return in;
}
