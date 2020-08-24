/*
 * Mammal.h
 *
 *  Created on: Aug 23, 2020
 *      Author: 1104602_snhu
 */

#ifndef THEZOO_MAMMAL_H_
#define THEZOO_MAMMAL_H_
#include "Animal.h"
#include <iostream>
using namespace std;
class Mammal:public Animal {
public:
	Mammal();
	virtual ~Mammal();
	void setNurse(int nurse);
	void setSubType(string sub);
	int getNurse();
	string getType();
	string getSubType();
	void printAnimal();
private:
	int nursing;
	string type;
	string subType;
};

#endif /* THEZOO_MAMMAL_H_ */
