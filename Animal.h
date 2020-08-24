/*
 * Animal.h
 *
 *  Created on: Aug 23, 2020
 *      Author: 1104602_snhu
 */

#ifndef THEZOO_ANIMAL_H_
#define THEZOO_ANIMAL_H_
#include <iostream>
using namespace std;

class Animal {
public:
	Animal();
	virtual ~Animal();
	void setName(string aName);
	void setTrackNum(int num);
	void printAnimal();
	string getName();
	int getTrackNum();
private:
	string name;
	int trackNum;

};

#endif /* THEZOO_ANIMAL_H_ */
