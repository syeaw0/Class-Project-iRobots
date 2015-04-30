
#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

template<class Type>
struct Node {
	Type data;	// Data of Node
	Node *next;	// Next Node
	Node *prev;	// Previous Node
};

template<class Type>
class DoublyLinkedList {
public:
	/********************************
	 ****CONSTRUCTOR & DESTRUCTOR****
	 ********************************/
	DoublyLinkedList();				// Constructor
	virtual ~DoublyLinkedList();	// Destructor

	/****************
	 ****MUTATORS****
	 ****************/
	void 		AddNode(Type toAdd);			// Add node
	Node<Type>* Search(Type toFind);			// Search for node
	void 		SortList(Node<Type> *toAdd);	// Sort the list
	bool 		RemoveNode(Type removeInfo);	// Remove a node
	bool		ClearList();					// Clear entire list

	/*****************
	 ****ACCESSORS****
	 *****************/
	Node<Type>* GetHead() const;				// Get Head of list
	bool 		IsEmpty() const;				// Get if empty list
	void 		PrintList() const;				// Prints the list

private:
	Node<Type> *head;	// Head of list
	Node<Type> *tail;	// Tail of list
	int        count;	// Count Nodes in list
};

/**************************************************************************
 * CONSTRUCTOR
 *************************************************************************/
template <class Type>
DoublyLinkedList<Type>::DoublyLinkedList() {
	head = NULL;
	tail = NULL;
	count = 0;
}

/**************************************************************************
 * DESTRUCTOR
 *************************************************************************/
template <class Type>
DoublyLinkedList<Type>::~DoublyLinkedList() {
	ClearList();
}

/**************************************************************************
 * 							MUTATORS
 * ------------------------------------------------------------------------
 * 						AddNode
 * 						Search
 * 						SortList
 * 						RemoveNode
 * 						ClearList
 *************************************************************************/

/**************************************************************************
 * AddNode
 * 		This method adds an item to the list.
 *
 * 		Return: empty (bool)
 *************************************************************************/
template <class Type>
void DoublyLinkedList<Type>::AddNode(Type addInfo) // IN & CALC - Node info
{
	// PROCESSING - Add new node
	Node<Type> *addNode = new Node<Type>;

	// PROCESSING - Get data for node & then sort the node into the list
	addNode->data = addInfo;
	SortList(addNode);
	count++;
}

/**************************************************************************
 * Search
 * 		This method receives information about the item to search for.
 * 		Then the method will loop through the list until the item is found.
 *
 * 		Return: addNode (Node<Type>)
 *************************************************************************/
template <class Type>
Node<Type>* DoublyLinkedList<Type>::Search(Type toFind) // IN & CALC - Node
{
	// Variable List
	Node<Type> *addNode;	// CALC & OUT - Find node
	bool 		found;		// CALC		  - If node found

	found   = false;
	addNode = head;

	// PROCESSING - Loop through list while not end and not found
	while(addNode != NULL && !found)
	{
		// PROCESSING - If node found set to true or go to next node
		if(addNode->data == toFind)
		{
			found = true;
		}
		else
		{
			addNode = addNode->next;
		}
	}

	return addNode;
}

/**************************************************************************
 * SortList
 * 		This method receives a Node that is to be added into the
 * 		sorted list.
 *
 * 		Return: nothing (Adds node to sorted list)
 *************************************************************************/
template <class Type>
void DoublyLinkedList<Type>::SortList(Node<Type> *addNode) // IN & CALC - Node
{
	// Variable List
	Node<Type> *tempPtr; // CALC - Temp pointer to list

	// PROCESSING - Add to an empty list
	if(head == NULL)
	{
		head = addNode;
		tail = addNode;
	}
	// PROCESSING - Add to the head of the list
	else if(head->data > addNode->data)
	{
		addNode->next = head;
		head->prev    = addNode;
		head		  = addNode;
	}
	// PROCESSING - Add to the tail of the list
	else if(tail->data < addNode->data)
	{
		tail->next    = addNode;
		addNode->prev = tail;
		tail 		  = addNode;
	}
	// PROCESSING - Add to the middle of the list
	else
	{
		tempPtr = head;

		// PROCESSIGN - Keep looping until found spot of where to add node
		while(tempPtr != NULL && tempPtr->data < addNode->data)
		{
			tempPtr = tempPtr->next;
		}

		// PROCESSING - Add the new node in the middle
		addNode->prev = tempPtr->prev;
		addNode->next = tempPtr;

		tempPtr->prev->next = addNode;
		tempPtr->prev = addNode;
	}

	tempPtr = NULL;
}

/**************************************************************************
 * RemoveNode
 * 		This method receives information about the item to remove.
 * 		Then this method will call the search method find the item to
 * 		remove and if found the node will be deleted.
 *
 * 		Return: found (bool)
 *************************************************************************/
template <class Type>
bool DoublyLinkedList<Type>::RemoveNode(Type removeInfo) // IN & CALC - Info
{
	// Variable List
	Node<Type> *currPtr;	// CALC 	  - Pointer to traverse list
	Node<Type> *toRemove;	// CALC 	  - Node to remove
	bool		found;		// CALC & OUT - If removed

	found	  = false;
	currPtr   = head;
	toRemove  = Search(removeInfo);

	// PROCESSING - Check if node to remove exists
	if(toRemove != NULL)
	{
		currPtr = head;

		// PROCESSING - Traverse through list and find where to remove
		while(currPtr != NULL && !found)
		{
			if(currPtr == toRemove)
			{
				found = true;
			}
			else
			{
				currPtr = currPtr->next;
			}
		}
	}

	// PROCESSING - If found to remove
	if(found)
	{
		// PROCESSING - If to remove at head
		if(currPtr == head)
		{
			head = head->next;
			head->prev = NULL;
			delete currPtr;
		}
		// PROCESSING - If to remove at tail
		else if(currPtr == tail)
		{
			tail = tail->prev;
			tail->next = NULL;
			delete currPtr;
		}
		// PROCESSING - If to remove in middle
		else
		{
			currPtr->prev->next = currPtr->next;
			currPtr->next = currPtr->prev;
		}

		count--;
	}

	return found;
}

/**************************************************************************
 * ClearList
 * 		This method clears the entire list.
 *
 * 		Return: addNode (Node<Type>)
 *************************************************************************/
template <class Type>
bool DoublyLinkedList<Type>::ClearList()
{
	// Variable List
	Node<Type> *tempPtr;	// CALC 	  - Traverses through the list
	bool		cleared;	// CALC & OUT - Whether the list is cleared

	tempPtr = head;
	cleared = false;

	// PROCESSING - Check if empty
	if(IsEmpty())
	{
		cleared = true;
	}
	else
	{
		// PROCESSING - Traverse through entire list and delete each node
		while(tempPtr != NULL)
		{
			head = head->next;
			delete tempPtr;
			tempPtr = head;
			count--;
		}
		cleared = true;
	}

	head = NULL;
	tail = NULL;
	count = 0;

	return cleared;
}

/**************************************************************************
 * 							ACCESSORS
 * ------------------------------------------------------------------------
 * 						GetHead
 * 						IsEmpty
 * 						PrintList
 *************************************************************************/

/**************************************************************************
 * GetHead
 * 		This method gets the head of the list
 *
 * 		Returns: head (Node<Type>)
 *************************************************************************/
template <class Type>
Node<Type>* DoublyLinkedList<Type>::GetHead() const
{
	return head;
}

/**************************************************************************
 * IsEmpty
 * 		This method checks whether the doubly linked list is empty or not.
 *
 * 		Return: empty (bool)
 *************************************************************************/
template <class Type>
bool DoublyLinkedList<Type>::IsEmpty() const
{
	// Variable List
	bool empty;		// CALC & OUT - Empty list

	// PROCESSING - Check if empty list
	(count == 0) ? empty = true
				 : empty = false;

	return empty;
}

/**************************************************************************
 * PrintList
 * 		This method first checks if the list is empty. If the list is
 * 		not empty, the whole list will be printed to the console.
 * 		Otherwise, the user will be notified that the list is empty.
 *
 * 		Return: nothing (Displays list to console)
 *************************************************************************/
template <class Type>
void DoublyLinkedList<Type>::PrintList() const
{
	// Variable List
	Node<Type> *currPtr;	// CALC & OUT - Temp pointer to list

	currPtr = head;

	// PROCESSING - Check if list is empty or not
	if(IsEmpty())
	{
		cout << "iRobotsTheBomb has no customers in the customer list\n";
	}
	else
	{
		// OUTPUT - Display the entire list
		while(currPtr != NULL)
		{
			cout << currPtr->data;
			currPtr = currPtr->next;
		}

		cout << endl;
	}
}

#endif /* DOUBLYLINKEDLIST_H_ */
