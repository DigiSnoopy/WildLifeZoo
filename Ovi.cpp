/*
 * Ovi.cpp
 *
 *  Created on: Aug 23, 2020
 *      Author: 1104602_snhu
 */

#include "Ovi.h"
#include "Animal.h"
#include <iostream>
namespace std {


Ovi::Ovi() {
	type = "Oviparous";
	subType="none";
	eggs = 0;
}
void Ovi::setSubType(string sub){
	subType=sub;
}
void Ovi::setEggs(int numEggs) {
	eggs = numEggs;
}
string Ovi::getType(){
	return type;
}
string Ovi::getSubType(){
	return subType;
}
int Ovi::getEggs() {
	return eggs;
}

void Ovi::printAnimal(){
	Animal::printAnimal();
	cout << " " << type << " " << subType << " " << eggs << " 0" << endl;
}
Ovi::~Ovi() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
