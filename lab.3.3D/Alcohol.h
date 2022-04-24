#pragma once
#include "Liquid.h"
class Alcohol :
	public Liquid
{
private:
	double strength;
public:
	double getStrength() { return strength; }

	void setStrength(double strength);

	Alcohol() { strength = 0; setDensity(0); setName(""); }
	Alcohol(const string name, const double density, const double strength);
	Alcohol(const Alcohol& s);

	void changeStrength(Liquid l);

	friend ostream& operator << (ostream& out, const Alcohol& s);
	friend istream& operator >> (istream& in, Alcohol& s);

	operator string () const;

	~Alcohol(void) {};
};
