/*
 * SingleNode.cpp
 *
 *  Created on: 6 Feb 2015
 *      Author: osboxes
 */

#include "SingleNode.h"

void SingleNode::setValue(int value) {
	this->mValue = value;
}

int SingleNode::getValue() {
	return this->mValue;
}

ISingleNode * SingleNode::getNext() {
	return this->mNext;
}

void SingleNode::setNext(ISingleNode * next) {
	this->mNext = (SingleNode*)next;
}


