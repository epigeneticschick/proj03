/* Vec.h provides a simple vector class named Vec.
 * Student Name:Lorrayya Williams
 * Date: October 1, 2018
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
using namespace std;

typedef double Item;

class Vec {
public:
	Vec();
	Vec(unsigned size);
	Vec(const Vec& original);
	~Vec();
	Vec& operator=(const Vec& original);
	unsigned getSize() const;
	void setItem(unsigned index, const Item& it);
	Item getItem( unsigned index) const;
	void setSize(unsigned newSize);
	bool operator==(const Vec& v2);
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	void readFrom(string filename);
	void writeTo(const string& fileName);
	Item& operator[](unsigned index);
	const Item& operator[](unsigned index) const;
	bool operator!=(const Vec& v2);
	Vec operator+(const Vec& v2);
	Vec operator-(const Vec& v2);
	double operator*(const Vec& other) const;

private:
	unsigned mySize;
	Item * myArray;
	Item * copyArray;
	Item * newArray;
	friend class VecTester;
	friend class application;
};

#endif /*VEC_H_*/
