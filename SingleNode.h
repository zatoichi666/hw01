/*
 * SingleNode.h
 *
 *  Created on: 6 Feb 2015
 *      Author: osboxes
 */

#ifndef SINGLENODE_H_
#define SINGLENODE_H_

#include "Interfaces01.h"

struct SingleNode: public ISingleNode {

private:
	int mValue;
	SingleNode * mNext;

public:

	SingleNode() :
			mValue(0), mNext(NULL) {
	}
	~SingleNode() {
	}
	void setValue(int value);

	int getValue();

	ISingleNode * getNext();

	void setNext(ISingleNode * next);


};

#endif /* SINGLENODE_H_ */
