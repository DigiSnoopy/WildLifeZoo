/*
 * Animal.cpp
 *
 *  Created on: Aug 23, 2020
 *      Author: 1104602_snhu
 */

#include "Animal.h"
#include <iostream>
using namespace std;
Animal::Animal() {
	name="none";
	trackNum=0;
}

void Animal::setName(string aName){
	name=aName;
}
void Animal::setTrackNum(int num){
	trackNum=num;
}

string Animal::getName(){
	return name;
}
int Animal::getTrackNum(){
	return trackNum;
}

void Animal::printAnimal(){
	cout << trackNum << " " << name;
}

Animal::~Animal() {
	// TODO Auto-generated destructor stub
}

