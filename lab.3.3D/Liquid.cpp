#include <sstream>
#include <iostream>
#include "Liquid.h"

Liquid::Liquid(const string name)
	:name(name), density(0)
{
}

Liquid::Liquid(const double density)
	: name(""), density(density)
{
}

Liquid::Liquid(const string name, const double density)
	: name(name), density(density)
{
}

Liquid::Liquid(const Liquid& r)
	: name(r.name), density(r.density)
{
}

Liquid& Liquid::operator=(const Liquid& m)
{
	this->name = m.name;
	this->density = m.density;

	return *this;
}

Liquid::operator string() const
{
	stringstream sout;
	sout << endl;
	sout << "name = " << getName() << endl;
	sout << "density = " << getDensity() << endl;

	return sout.str();
}

void Liquid::changeDensity()
{
	double density;
	cout << endl;
	cout << "new density =  "; cin >> density;
	setDensity(density);
}

Liquid& Liquid::operator++()
{
	++density;
	return *this;
}

Liquid& Liquid::operator--()
{
	--density;
	return *this;
}

Liquid Liquid::operator++(int)
{
	Liquid t(*this);
	density++;
	return t;

}

Liquid Liquid::operator--(int)
{
	Liquid t(*this);
	density--;
	return t;
}

ostream& operator<<(ostream& out, const Liquid& q)
{
	out << string(q);
	return out;
}

istream& operator>>(istream& in, Liquid& q)
{
	string name;
	double density;
	cout << endl;
	cout << "name =  "; in >> name;
	cout << "density =  "; in >> density;
	q.setName(name);
	q.setDensity(density);
	return in;
}