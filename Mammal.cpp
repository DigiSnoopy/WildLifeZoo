/*
 * Mammal.cpp
 *
 *  Created on: Aug 23, 2020
 *      Author: 1104602_snhu
 */

#include "Mammal.h"
#include "Animal.h"

Mammal::Mammal() {
	type="Mammal";
	subType="none";
	nursing=-1;
}

void Mammal::setSubType(string sub){
	subType=sub;
}
void Mammal::setNurse(int nurse){
	nursing=nurse;
}
string Mammal::getType() {
	return type;
}
string Mammal::getSubType(){
	return subType;
}
int Mammal::getNurse(){
	return nursing;
}
void Mammal::printAnimal(){
	Animal::printAnimal();
	cout << " " << type << " " << subType << " 0 " << nursing << endl;
}

Mammal::~Mammal() {
	// TODO Auto-generated destructor stub
}

