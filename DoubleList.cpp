/*
 * DoubleList.cpp
 *
 *  Created on: 10 Feb 2015
 *      Author: osboxes
 */

#include "DoubleList.h"
#include <iostream>

DoubleList::DoubleList() :
		mHead(NULL), mTail(NULL)
{
	// TODO Auto-generated constructor stub

}

DoubleList::~DoubleList()
{
	// TODO Auto-generated destructor stub
}

void DoubleList::InsertAt(DoubleNode* node, int value)
{
	if (node != NULL)
	{
		DoubleNode* new_node = new DoubleNode();
		new_node->setValue(value);

		if (node->getPrev() != NULL)
		{

			// 1. Set previous node's next ptr to the new node
			node->getPrev()->setNext(new_node);

			// 2. Set new node's previous ptr to the previous node
			new_node->setPrev(node->getPrev());

		}

		// 3. Set new node's next ptr to the current node
		new_node->setNext(node);

		// 4. Set the node's previous ptr to the new node
		node->setPrev(new_node);

		if (this->getHead() == node)
		{
			this->setHead(new_node);
		}

		if (this->getTail() == new_node)
		{
			this->setTail(node);
		}

	}
	else
	{
		// Do nothing
	}
}

void DoubleList::InsertAfter(DoubleNode* node, int value)
{
	if (node != NULL)
	{
		DoubleNode* new_node = new DoubleNode();
		new_node->setValue(value);

		// Connect the new node to the target node's next node and vice versa
		if (node->getNext() != NULL)
		{
			node->getNext()->setPrev(new_node);
			new_node->setNext(node->getNext());
		}

		//Point the current node to the new node
		node->setNext(new_node);

		//Point the new node back to the current node
		new_node->setPrev(node);

		//Update the new tail
		if (this->getTail() == node)
		{
			this->setTail(new_node);
		}

	}
	else
	{
		DoubleNode* new_node = new DoubleNode();
		new_node->setValue(value);

		this->setHead(new_node);
		this->setTail(new_node);
		// Do nothing
	}
}

void DoubleList::InsertHead(int value)
{
	DoubleNode* new_node = new DoubleNode();
	new_node->setValue(value);

	if (mHead != NULL)
	{
		new_node->setNext(mHead);
		mHead->setPrev(new_node);
		mHead = new_node;

	}
	else
	{
		mHead = new_node;
		mTail = new_node;

	}

}

void DoubleList::InsertTail(int value)
{
	DoubleNode* new_node = new DoubleNode();
	new_node->setValue(value);

	if (mTail != NULL)
	{
		new_node->setPrev(mTail);
		mTail->setNext(new_node);
		mTail = new_node;

	}
	else
	{
		mTail = new_node;
		mHead = new_node;

	}

}

void DoubleList::PrintList()
{

	std::cout << "head: " << this->getHead()->getValue() << "| ";

	DoubleNode* n1 = (DoubleNode*) this->getHead();

	for (; n1; n1 = (DoubleNode*) n1->getNext())
	{

		std::cout << n1->getValue() << " ";

	}
	std::cout << std::endl;

}

DoubleNode* DoubleList::getHead()
{
	return mHead;
}

DoubleNode* DoubleList::getTail()
{
	return mTail;
}

void DoubleList::setHead(IDoubleNode* head)
{
	mHead = (DoubleNode*) head;
}
void DoubleList::setTail(IDoubleNode* tail)
{
	mTail = (DoubleNode*) tail;
}

void DoubleList::addSorted(int value)
{

	DoubleNode* n1 = (DoubleNode*) this->getHead();
	if (n1 != NULL)
	{
		for (; n1; n1 = (DoubleNode*) n1->getNext())
		{
			if (n1->getValue() >= value)
			{
				this->InsertAt(n1,value);
				return;
			}
		}
		this->InsertTail(value);
	}
	else
	{
		this->InsertHead(value);
	}
}
void DoubleList::orderSort2()
{

}
void DoubleList::orderSort3()
{

}
void DoubleList::sequenceOrderSort()
{

}
void DoubleList::reverse()
{

	DoubleNode* temp_node = NULL;
	DoubleNode* current_node = mHead;

	DoubleNode* backup_head = mHead;

	/* swap next and prev for all nodes of
	 doubly linked list */
	while (current_node != NULL)
	{
		temp_node = (DoubleNode*) current_node->getPrev();
		current_node->setPrev(current_node->getNext());
		current_node->setNext(temp_node);
		current_node = (DoubleNode*) current_node->getPrev();
	}

	if (temp_node != NULL)
	{
		mHead = (DoubleNode*) temp_node->getPrev();
		mTail = backup_head;
	}
}
