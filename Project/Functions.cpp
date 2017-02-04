/*
	Bijan Fazeli

*/

#include "DoublyList.h"

// Function pseudocode
/**
func switchEveryTwo
	If there are two or more nodes
		if the size of the list is even
			Switch every other node (starting with the first node) with the next node
		else
			Bring the last node to the front of the list and switch every other node (starting with the second node)
			with the next node.
*/

// Function definition
void DoublyList::switchEveryTwo()
{
	if (count >= 2)
	{
		Node * temp = first;
		int i = 0;

		if (count % 2 != 0)		// Check to see if the list has odd elements, then bring the last node to the front
		{
			temp->setPreviousLink(last);
			last->getPreviousLink()->setNextLink(nullptr);

			last->setNextLink(first);
			last = last->getPreviousLink();

			temp->getPreviousLink()->setPreviousLink(nullptr);
			first = temp->getPreviousLink();
			i = 1;
		}

		while (temp != NULL && i < count)	// Loop through the list
		{
			if (i == 0)		// Swap the first two nodes
			{
				temp->setPreviousLink(temp->getNextLink());
				temp->getPreviousLink()->setPreviousLink(NULL);
				temp->setNextLink(temp->getNextLink()->getNextLink());
				temp->getPreviousLink()->setNextLink(temp);
				temp->getNextLink()->setPreviousLink(temp);

				first = temp->getPreviousLink();
			}
			else if (i < count - 2)		// Swap every other node in the middle
			{
				temp->getPreviousLink()->setNextLink(temp->getNextLink());
				temp->getNextLink()->setPreviousLink(temp->getPreviousLink());
				temp->setPreviousLink(temp->getNextLink());
				temp->setNextLink(temp->getPreviousLink()->getNextLink());
				temp->getPreviousLink()->setNextLink(temp);
				temp->getNextLink()->setPreviousLink(temp);
			}
			else		// Swap the last two nodes
			{
				temp->getPreviousLink()->setNextLink(temp->getNextLink());
				temp->getNextLink()->setPreviousLink(temp->getPreviousLink());
				temp->setPreviousLink(temp->getNextLink());
				temp->getPreviousLink()->setNextLink(temp);
				temp->setNextLink(nullptr);

				last = temp;
			}
			i += 2;
			temp = temp->getNextLink();
		}
	}
}
