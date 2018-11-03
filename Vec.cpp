/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name:Lorrayya Williams
 * Date: October 1, 2018
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */
 
#include "Vec.h"
#include <cstdlib>
#include <fstream>
#include <cassert>

// Intializes Array with Null values
Vec::Vec() {
	myArray = NULL;
	mySize = 0;
}


//Intializes Array with an inputed value
Vec::Vec(unsigned size) {
		mySize = size;
	if (size> 0){
		myArray = new double[mySize];
	}
	else{
		myArray = NULL;
	}
	for(unsigned i=0; i < size; ++i){
		myArray[i]=0;
	}
}


//Changes the size of an array
Vec::Vec(const Vec& original) {
	mySize = original.mySize;
	if (original.mySize > 0){
		myArray = new Item[mySize];
		for (unsigned i = 0; i< mySize; ++i) {
			myArray[i] = original.myArray[i];
		}
	}
	else {
		mySize = 0;
		myArray = NULL;
	}
   }

//Destroys Array
Vec::~Vec() {
	delete []myArray;
	mySize = 0;
	myArray = NULL;
}

//Allows operator to compare te size of vectors
Vec& Vec::operator=(const Vec& original) {
	if (this != &original) {
		if (mySize != original.mySize) {
			if (mySize > 0) {
				delete []myArray;
				myArray = NULL;
			}
			if (original.mySize > 0) {
				myArray = new Item[original.mySize];
			}
			mySize = original.mySize;
		}
		for (unsigned i = 0; i < mySize; ++i) {
			myArray[i] = original.myArray[i];
		}
	}
	return *this;
}

//Accessor for Vector Size
unsigned Vec::getSize() const {
	return mySize;
}

//Sets item of an array to a certain value
void Vec::setItem(unsigned index, const Item& it){
	if (myArray == NULL){
		throw range_error("myArray is empty");
	}
	if(index > mySize - 1){
		throw range_error("Index Out of Bounds");
	}
	else{
		myArray[index] = it;
	}
}

//Accessor for Item
Item Vec::getItem(unsigned index) const {
	if (myArray == NULL){
		throw range_error("myArray is empty");
	}
	if(index > mySize - 1){
		throw range_error("Index Out of Bounds");
	}
	else{
		return myArray[index];
	}
}


//Sets the Sixe of the Vector
void Vec::setSize(unsigned newSize){
	if (mySize != newSize){
		if (newSize == 0){
			delete []myArray;
			myArray = NULL;
			mySize = 0;
		}
		else{
			newArray = new Item[newSize];
			if (mySize < newSize){
				for(unsigned i= 0; i < mySize; ++i){
					newArray[i] = myArray[i];
				}
				for(unsigned i =mySize; i < newSize; ++i) {
					newArray[i]= 0;
				}
			}
			else{
				for(unsigned i = 0; i < newSize ; ++i){
					newArray[i]= myArray[i];
				}
			}
			mySize = newSize;
			delete []myArray;
			myArray = newArray;
		}

	}
}

//Allows for expression to compar the size of vectors
bool Vec::operator==(const Vec& v2){
	if (mySize != v2.mySize){
		return false;
	}
	for(unsigned i =0; i < mySize; ++i){
		if(myArray[i] != v2.myArray[i]){
			return false;
		}
	}
	return true;

}

//Writes Value to a Vector
void Vec::writeTo(ostream& out) const{
	for(unsigned i; i < mySize; ++i){
		out << myArray[i] << '\t';
	}


}

//Reads Values in a Vector
void Vec::readFrom(istream& in){
	for(unsigned i = 0; i < mySize; i++){
			in >> myArray[i];
	}
}

//reads vectors stored in a file
void Vec::readFrom(string filename) {
	ifstream fin(filename.c_str());
	assert(fin.is_open());
	delete[] myArray;
	fin >> mySize;
	myArray = new Item[mySize];
	for(unsigned i = 0; i < mySize; i++){
		fin >> myArray[i];
	}
	fin.close();
}

//Writes vectors to a File
void Vec::writeTo(const string& fileName){
		ofstream myFile;
		myFile.open(fileName.c_str());

		double numValues = mySize;
		myFile << numValues << endl;

		for(unsigned i = 0; i < mySize; ++i){
			myFile << myArray[i] << endl;

		}
		myFile.close();
}

/* Subscript operator (read version)
 * Gets the value at a given index in myArray
 * @param: index, an unsigned
 * Return: myArray[index], an Item (aka double)
 * Written by: Zachary Chin
 */
const Item& Vec::operator[](unsigned index) const{
	if (index >= mySize) {
		throw range_error("index out of bounds of array's size");
	} else {
		return myArray[index];
	}
}

//Allows for the operator to be used for writing to a Vector
Item& Vec::operator[](unsigned index) {
	if(index >= mySize){
		throw range_error("The Index is too high!");
	}
	else{
		return myArray[index];
	}
}

/* Inequality operator
 * Compares two Vec objects to see if they are equal
 * @param: v2, a Vec object
 * Return: true if the two Vec objects have the same size and the
 * 		   same values in corresponding indexes; return false otherwise.
 * Written by: Zachary Chin
 */
bool Vec::operator!=(const Vec& v2){
	if (mySize != v2.mySize) {
		return true;
	} else {
		for (unsigned i = 0; i < mySize; i++) {
			if (myArray[i] != v2.myArray[i]) {
				return true;
			}
		}
	}
	return false;
}


//Allows for vectors to be added
Vec Vec::operator+(const Vec& other){
	if(mySize == other.mySize){
		Vec vec3(mySize);
		for (unsigned i= 0; i < mySize; i++){
			vec3.setItem(i, myArray[i] + other.myArray[i]);
		}
		return vec3;
	} else {
		throw invalid_argument("size is unequal");
	}



}

/* Subtraction operator
 * Subtracts the values in the array of the current Vec object by the
 *    values in the corresponding indexes in the Vec object passed
 * @param: v2, a Vec object
 * Return: v3, a Vec object, which contains the differences of values
 * 		   between the current Vec object and v2
 * Written by: Zachary Chin
 */
Vec Vec::operator-(const Vec& v2){
	if(mySize != v2.mySize){
		throw invalid_argument("Arrays are not of equal size");
	}
	else{
		Vec v3(v2.getSize());
		for(unsigned i = 0; i < mySize; i++){
			v3[i] = myArray[i] - v2[i];
		}

		return v3;
	}
}

//Allows for vectors t be multiplied
double Vec::operator*(const Vec& other) const{
	if (mySize == other.mySize){
		Vec vec3(mySize);
		for (unsigned i=0; i < mySize; ++i){
			vec3.setItem(i, myArray[i] * other.myArray[i]);
		}
		double product = 0;
		for(unsigned i=0; i < vec3.mySize; ++i) {
			product += vec3.myArray[i];
		}
		return product;
	}else {
		throw invalid_argument("size is unequal");
	}
}





