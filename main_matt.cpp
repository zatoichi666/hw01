/*
 * main.cpp
 *
 *  Created on: 6 Feb 2015
 *      Author: osboxes
 */

#include <iostream>

#include "Interfaces01.h"
#include "SingleList.h"
#include "SingleNode.h"
#include "DoubleList.h"
#include "DoubleNode.h"

//#define doMainMatt

#ifdef doMainMatt

int main()
{
	std::cout << "Matt's version of main\n";

//	SingleList* l1 = new SingleList();
//	l1->addHead(1);
//	l1->addHead(2);
//	l1->addHead(3);
//	l1->addHead(4);
//	l1->addHead(5);
//	l1->PrintSingleList();
//	l1->orderSort2();
//	l1->PrintSingleList();
//	l1->reverse();
//	l1->PrintSingleList();

// Test for orderSort3()
	SingleList* l2 = new SingleList();
	std::cout << "----" << std::endl;
	for (int i = 5; i >=0; i--)
	{
		l2->addHead(i);
	}
	l2->PrintSingleList();
	l2->orderSort3();
	l2->PrintSingleList();

//	// Test for InsertTail, InsertHead, InsertAfter, InsertAt()
//	DoubleList* dl1 = new DoubleList();
//	dl1->InsertTail(0);
//	dl1->InsertAfter(dl1->getTail(),1);
//	dl1->InsertAt((DoubleNode*)dl1->getHead()->getNext(),3);
//	dl1->reverse();
//	dl1->InsertHead(-1);
//	dl1->PrintList();
//	dl1->InsertAfter((DoubleNode*)dl1->getTail()->getPrev(),-4);
//	dl1->PrintList();

//// Test for addSorted()
//	DoubleList* dl2 = new DoubleList();
//	dl2->addSorted(4);
//	dl2->addSorted(2);
//	dl2->addSorted(0);
//
//	dl2->addSorted(5);
//	dl2->addSorted(3);
//	dl2->addSorted(1);
//
//	std::cout << std::endl;
//	dl2->PrintList();

//	// Test for reverse
//	DoubleList* dl1 = new DoubleList();
//	dl1->InsertTail(0);
//	dl1->InsertTail(1);
//	dl1->InsertTail(2);
//	dl1->InsertTail(3);
//	dl1->InsertTail(4);
//	dl1->PrintList();
//	DoubleNode* n1 = dl1->getTail();
//	std::cout << "Tail value " << n1->getValue() << std::endl;
//	DoubleNode* n2 = dl1->getHead();
//	std::cout << "Head value " << n2->getValue() << std::endl;
//	dl1->reverse();
//	dl1->PrintList();
//	n1 = dl1->getTail();
//	std::cout << "Tail value " << n1->getValue() << std::endl;
//	n2 = dl1->getHead();
//	std::cout << "Head value " << n2->getValue() << std::endl;

	return 0;
}

#endif
