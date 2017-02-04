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
}
