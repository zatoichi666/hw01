/*
 * DoubleList.h
 *
 *  Created on: 10 Feb 2015
 *      Author: osboxes
 */

#ifndef DOUBLELIST_H_
#define DOUBLELIST_H_

#include "Interfaces01.h"
#include "DoubleNode.h"

struct DoubleList : public IDoubleList {
private:
	DoubleNode* mHead;
	DoubleNode* mTail;

public:
	DoubleList();
	~DoubleList();
	void InsertAt(DoubleNode* node, int value);
	void InsertAfter(DoubleNode* node, int value);
	void InsertHead(int value);
	void InsertTail(int value);
	void PrintList();
	DoubleNode* getHead();
	DoubleNode* getTail();
	void setHead(IDoubleNode* head);
	void setTail(IDoubleNode* tail);
	void addSorted(int value);
	void orderSort2();
	void orderSort3();
	void sequenceOrderSort();
	void reverse();
};


#endif /* DOUBLELIST_H_ */
