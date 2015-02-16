/*
 * SingleList.cpp
 *
 *  Created on: 6 Feb 2015
 *      Author: osboxes
 */

#include "SingleList.h"
#include <iostream>

SingleNode *
SingleList::getHead()
{
	return mHead;
}

void SingleList::PrintSingleList()
{

	std::cout << "head: " << this->getHead()->getValue() << "| ";

	SingleNode* n1 = (SingleNode*) this->getHead();
	int count = 0;
	for (; n1; n1 = (SingleNode*) n1->getNext())
	{

		std::cout << n1->getValue() << " ";
		count++;
	}
	std::cout << std::endl;

}

void SingleList::setHead(ISingleNode * head)
{

	this->mHead = (SingleNode*) head;

}

void SingleList::addHead(int value)
{
	SingleNode* newNode = new SingleNode();
	newNode->setValue(value);
	newNode->setNext(this->mHead);
	this->setHead(newNode);

}

void SingleList::orderSort2_2()
{

	//PrintSingleList();
	SingleNode* first_node = NULL;
	SingleNode* next_node = NULL;
	SingleNode* second_node = NULL;

	if (this->getHead() != NULL)
	{

		first_node = (SingleNode*) this->getHead();
		next_node = (SingleNode*) this->getHead();

		this->setHead(first_node->getNext());

		while (first_node->getNext() != NULL)
		{

			// start loop
			second_node = (SingleNode*) first_node->getNext(); 	// step 2

			if (second_node->getNext() != NULL) // if second node isn't the last node
			{
				next_node = (SingleNode*) second_node->getNext();
				if (second_node->getNext()->getNext() != NULL)
				{
					first_node->setNext(second_node->getNext()->getNext()); // step 2'
				}
				else
				{
					first_node->setNext(second_node->getNext());
					second_node->setNext(first_node);
					return;
				}
				second_node->setNext(first_node); 		// step 3
				first_node = (SingleNode*) next_node;

			}
			else
			{
				first_node->setNext(NULL); // terminate execution
				second_node->setNext(first_node);
			}
		}

	}

}

void SingleList::swap(SingleNode* n1, SingleNode* n2)
{
	SingleNode* temp;
	temp = (SingleNode*) n1;
	n1->setNext(n2->getNext());
	n2->setNext(temp);
}

void SingleList::RecursiveSetback(int count, SingleNode* startNode)
{
	if (count > 0)
	{
		this->RecursiveSetback(count - 1, (SingleNode*) startNode->getNext());
//		std::cout << "This node " << startNode->getValue() << " next node: "
//				<< startNode->getNext()->getValue();
		startNode->getNext()->setNext(startNode);
//		std::cout << std::endl;
	}

}

void SingleList::orderSort2()
{
	SingleNode* temp;
	SingleNode* n1;
	SingleNode* n2;
	const int SPACES = 2;
	n1 = (SingleNode*) this->getHead();

	this->setHead(this->getHead()->getNext());

	while (n1->getNext() != NULL)
	{
		int count = 0;
		n2 = n1;

		while (count < SPACES - 1)
		{
			n2 = (SingleNode*) n2->getNext();
			count++;
		}

		if (n2->getNext() != NULL)
			temp = (SingleNode*) n2->getNext();

		if (n2 != NULL)
		{
//			std::cout << "swapping pointers of " << n1->getValue() << " with "
//					<< n2->getValue() << std::endl;
			this->swap(n1, n2);
		}

		if (temp->getNext() != NULL)
		{
//			std::cout << "setting " << n1->getValue() << "'s next pointer to "
//					<< temp->getNext()->getValue() << std::endl;
			n1->setNext(temp->getNext());
		}

		//std::cout << "setting next node to " << temp->getValue() << std::endl;
		n1 = temp;

	}
}

void SingleList::orderSort3()
{

	SingleNode* temp;
	SingleNode* n1;
	SingleNode* n2;
	const int SPACES = 3;
	n1 = (SingleNode*) this->getHead();

	// Find new head
	SingleNode* newHead = this->getHead();
	for (int i = 0; i < SPACES - 1; i++)
	{
		newHead = (SingleNode*) newHead->getNext();
	}
	this->setHead(newHead);

//	std::cout << "Setting new head to " << newHead->getValue() << std::endl;

	while (n1->getNext() != NULL)
	{
		n2 = n1;

		// Set n2 ahead to end of segment
		int count = 0;

		while ((count < SPACES - 1) && (n2->getNext() != NULL))
		{
			n2 = (SingleNode*) n2->getNext();
			count++;
		}

		SingleNode* jump_pointer = NULL;
		if (n2->getNext() != NULL)
		{
			temp = (SingleNode*) n2->getNext();
			jump_pointer = (SingleNode*) n2->getNext(); // Has to be executed prior to RecursiveSetback()
		}

		//RecursiveSetback(SPACES - 1, n1);
		RecursiveSetback(count, n1); // If the last chunk has a different size, count reflects that being the length of the segment

		if (jump_pointer != NULL)
		{
			for (int i = 0; i < SPACES - 1; i++)
			{
				if (jump_pointer->getNext() != NULL)
				{
					//Advance the jump_pointer
					jump_pointer = (SingleNode*) jump_pointer->getNext();
				}
			}
		}

		n1->setNext(jump_pointer);

//		std::cout << "setting next node to " << temp->getValue() << std::endl;
		n1 = temp;

	}

}

//	//PrintSingleList();
//	SingleNode* first_node = NULL;
//	SingleNode* next_node = NULL;
//	SingleNode* second_node = NULL;
//	SingleNode* third_node = NULL;
//
//	if (this->getHead() != NULL)
//	{
//
//		first_node = (SingleNode*) this->getHead();
//		next_node = (SingleNode*) this->getHead();
//
//		this->setHead(first_node->getNext()->getNext());
//
//		while (first_node->getNext() != NULL)
//		{
//
//			// start loop
//			second_node = (SingleNode*) first_node->getNext(); 	// step 2
//			third_node = (SingleNode*) second_node->getNext();
//
//			if (third_node->getNext() != NULL) // if third node isn't the last node
//			{
//				next_node = (SingleNode*) third_node->getNext();
//
//				// This block causes a null pointer
//				if (third_node->getNext() != NULL)
//				{
//					first_node->setNext(third_node->getNext());
//
//				}
//				else
//				{
//
//					if (third_node->getNext()->getNext() != NULL)
//					{
//						first_node->setNext(third_node->getNext()->getNext());
//					}
//					else
//					{
//
//						if (third_node->getNext()->getNext()->getNext() != NULL)
//						{
//							first_node->setNext(
//									third_node->getNext()->getNext()->getNext()); // step 2'
//						}
//					}
//				}
//				third_node->setNext(second_node);
//				second_node->setNext(first_node); 		// step 3
//
//			}
//			else
//			{ // The list is 3 or less elements long
//
//				first_node->setNext(NULL); // terminate execution
//				second_node->setNext(first_node);
//				third_node->setNext(second_node);
//
//			}
//
//			first_node = (SingleNode*) next_node;
//		}
//
//	}

void SingleList::sequenceOrderSort()
{

}

void SingleList::reverse()
{
	SingleNode* prev_node = NULL;
	SingleNode* current_node = (SingleNode*) this->getHead();
	SingleNode* next_node;

	this->mHead = (SingleNode*) this->getHead()->getNext();

	while (current_node != NULL)
	{
		next_node = (SingleNode*) current_node->getNext();
		current_node->setNext(prev_node);
		prev_node = current_node;
		current_node = next_node;

	}
	this->mHead = prev_node;

}

