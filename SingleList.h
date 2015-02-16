/*
 * SingleList.h
 *
 *  Created on: 6 Feb 2015
 *      Author: osboxes
 */

#ifndef SINGLELIST_H_
#define SINGLELIST_H_

#include "Interfaces01.h"
#include "SingleNode.h"

struct SingleList : public ISingleList{

private:
	SingleNode* mHead;

public:
	void PrintSingleList();
	SingleList() :mHead(NULL){};
	~SingleList() {};
	SingleNode * getHead();
	void setHead(ISingleNode * head);
	void addHead(int value);
	void orderSort2();
	void orderSort3();
	void orderSort2_2();
	void RecursiveSetback(int count, SingleNode* startNode);
	void sequenceOrderSort();
	void reverse();
	void swap(SingleNode* n1, SingleNode* n2);

};

#endif /* SINGLELIST_H_ */
