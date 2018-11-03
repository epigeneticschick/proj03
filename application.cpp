/* Purpose: This creates an application allowing the user to create a vector with certain values and add those vectors
 * application.cpp
 * Lorrayya Williams
 *  Created on: Oct 1, 2018
 *      Author: llw5
 */

#include "application.h"
#include "Vec.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

application::application(){

}

void application::interface(){
	//intializes variables of Dimension size and Vectors
	unsigned numDim;
	unsigned numVecs;

	//Allows user to input the Dimension size
	cout << "Enter the number of dimensions in your space: ";
	cin >> numDim;

	//intializes a vector with the Starting positions
	Vec startPos(numDim);

	//intializes vector with the Sum
	Vec vecSum(numDim);

	string currentNum;

	//The user enters the starting points for the vectors
	for (unsigned i = 0; i < numDim; i++) {
		cout << "Enter starting position " << i + 1 << " in that space: ";
		cin >> currentNum;
		startPos[i] = atof(currentNum.c_str());
	}

	//Outputs Starting positions
	for (unsigned i = 0; i < numDim; i++) {
		cout << startPos[i] << '\t';
	}

	//Allows the user to enter the number of vectors
	cout << "Enter the number of vectors in that space: ";
	cin >> numVecs;


	Vec currentVec(numDim);
	vecSum = vecSum + startPos;

	// The user adds values to the vector in each dimension
	for(unsigned i = 0; i < numVecs; i++){
		for(unsigned j = 0; j < numDim; j++){
			cout << "Enter position " << j + 1 << " in that space"
					<< " for vector v" << i + 1 << ": ";
			cin >> currentNum;
			currentVec[j] = atof(currentNum.c_str());
		}

		vecSum = currentVec + vecSum;
	}


	//prints the starting positions
	for (unsigned i = 0; i < numDim; i++) {
		cout << startPos[i] << '\t';
	}

	//prints sum of vectors
	cout << "Sum of Vectors";
	for(unsigned i =0; i< numDim -1; ++i){
		cout << vecSum[i] << " , ";
	}
	cout << vecSum[numDim -1] << ">" << flush;

}
