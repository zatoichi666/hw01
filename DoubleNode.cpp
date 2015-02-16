/*
 * DoubleNode.cpp
 *
 *  Created on: 10 Feb 2015
 *      Author: osboxes
 */

#include "DoubleNode.h"

DoubleNode::DoubleNode() :
		mPrev(NULL), mNext(NULL), mValue(0) {

}

DoubleNode::~DoubleNode() {

}

void DoubleNode::setValue(int value) {

	mValue = value;
}

int DoubleNode::getValue() {
	return mValue;

}

IDoubleNode* DoubleNode::getPrev() {
	return mPrev;

}

IDoubleNode* DoubleNode::getNext() {
	return mNext;

}

void DoubleNode::setPrev(IDoubleNode* prev) {
	mPrev = (DoubleNode*)prev;

}

void DoubleNode::setNext(IDoubleNode* next) {
	mNext = (DoubleNode*)next;

}
