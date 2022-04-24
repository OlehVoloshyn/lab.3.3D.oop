#pragma once
#include "Liquid.h"
#include"Alcohol.h"
class AlcoholPrivate :
    private Liquid
{
private:
	double strength;
public:
	double getStrength() { return strength; }

	void setStrength(double strength);

	AlcoholPrivate() { strength = 0; setDensity(0); setName(""); }
	AlcoholPrivate(const string name, const double density, const double strength);
	AlcoholPrivate(const AlcoholPrivate& s);

	void changeStrength(Liquid l);

	friend ostream& operator << (ostream& out, const AlcoholPrivate& s);
	friend istream& operator >> (istream& in, AlcoholPrivate& s);

	operator string () const;

	~AlcoholPrivate(void) {};
};

