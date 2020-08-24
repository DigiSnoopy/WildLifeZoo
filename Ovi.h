/*
 * Ovi.h
 *
 *  Created on: Aug 23, 2020
 *      Author: 1104602_snhu
 */

#ifndef OVI_H_
#define OVI_H_

namespace std {
#include "Animal.h"
#include <iostream>
class Ovi: public Animal {
public:
	Ovi();
	virtual ~Ovi();
	void setEggs(int eggNum);
	void setSubType(string sub);
	int getEggs();
	string getType();
	string getSubType();
	void printAnimal();
private:
	string type;
	string subType;
	int eggs;
};

} /* namespace std */

#endif /* OVI_H_ */
