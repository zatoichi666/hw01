/*
 * DoubleNode.h
 *
 *  Created on: 10 Feb 2015
 *      Author: osboxes
 */

#ifndef DOUBLENODE_H_
#define DOUBLENODE_H_

#include <stdio.h>
#include "Interfaces01.h"

struct DoubleNode : public IDoubleNode {
private:
	DoubleNode* mNext;
	DoubleNode* mPrev;
	int mValue;
public:
	DoubleNode();
	~DoubleNode();
	void setValue(int value);
	int getValue();
	IDoubleNode* getPrev();
	IDoubleNode* getNext();
	void setPrev(IDoubleNode* prev);
	void setNext(IDoubleNode* next);
};

//struct IDoubleNode {
//  IDoubleNode() {}
//  virtual ~IDoubleNode() {}
//  virtual void setValue(int value) = 0;
//  virtual int getValue() = 0;
//  virtual IDoubleNode * getPrev() = 0;
//  virtual IDoubleNode * getNext() = 0;
//  virtual void setPrev(IDoubleNode * prev) = 0;
//  virtual void setNext(IDoubleNode * next) = 0;
//};


#endif /* DOUBLENODE_H_ */
