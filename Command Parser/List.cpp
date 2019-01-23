/******************************************************************
** Author: 			Artem Slivka
** Date: 		    07/15/17
** Description:		List.cpp is the function implementation file
**					for class List. It allows a user to create a 
**					list, add/remove items, and display the current
**					grocery shopping list
******************************************************************/

#include "List.hpp"		//Link to class header

/*********************************************************************
** Description:		This is a default constructor for List class.
**					It creates an empty Item vector of pointers
*********************************************************************/
List::List()
{
	listSize = 0;
}


/*********************************************************************
** Description:		This destructor frees the allocated memory for the
**					item vector.
*********************************************************************/
List::~List()
{
	clearList();
}

/*********************************************************************
** Description:		This function prints all the items in the current
**					list,including relevant parameters.
*********************************************************************/
void List::printList()
{
	unsigned int strLen;
	if (inventory.empty() == false)
	{
		strLen = inventory[0]->getName().length();
		updateSize();
	}	

	else if (inventory.empty() == true)
	{
		strLen = 0;
	}

	cout << "======Printing current inventory list======" << endl;

	if (strLen > 0)
	{		
		
		for (int i = 0; i < listSize; i++)
			{
				cout << "Item: " << i + 1 << endl;
				inventory[i]->printItem();
			}
	}
}

/*********************************************************************
** Description:		This function supervises adding items to the list. 
**					It compares a user's item versus other items in the
**					list before actually adding the object, though.
*********************************************************************/
void List::addItem(string fitemName, int fquantity)
{
	int duplicateItem = searchList(fitemName);
	if (duplicateItem == -1)
	{
		inventory.push_back(new Item(fitemName, fquantity));
		updateSize();
	}
	else
	{
		int oldQuantity = inventory[duplicateItem]->getQty();
		oldQuantity += fquantity;
		inventory[duplicateItem]->setQty(oldQuantity);
	}

	cout << "Showing updated inventory now." << endl;
	printList();
}

/*********************************************************************
** Description:		This function adds item to the list.
*********************************************************************/
void List::addItem(Item* newItem)
{
	int duplicateItem = searchList(newItem->getName());

	if (duplicateItem == -1)
	{
		inventory.push_back(newItem);
		updateSize();
	}
	else
	{
		int oldQuantity = inventory[duplicateItem]->getQty();
		oldQuantity += newItem->getQty();
		inventory[duplicateItem]->setQty(oldQuantity);
	}
	
	cout << "Showing updated inventory now." << endl;
	printList();
}
/*********************************************************************
** Description:		This function manages removing item from the list
*********************************************************************/
void List::removeItem()
{
	delete inventory[listSize - 1];
	inventory.pop_back();
	updateSize();
	
	cout << "Showing updated list now." << endl;
	printList();
}

/*********************************************************************
** Description:		This function increases the size of the list
**					array by 1. It adds an empty element at the end;
*********************************************************************/
void List::incrementList()
{
	inventory.push_back(new Item());
	updateSize();
}

/*********************************************************************
** Description:		This function updates the size of the vector list.
**					
*********************************************************************/
void List::updateSize()
{
	listSize = static_cast<int>(inventory.size());
}

/*********************************************************************
** Description:		This function returns the size of the vector list.
**
*********************************************************************/
int List::getSize()
{
	return listSize;
}


/*********************************************************************
** Description:		This function removes all of items from vector.
**
*********************************************************************/
void List::clearList()
{
	for (unsigned int i = 0; i < inventory.size(); i++)
	{
		delete inventory[i];
		inventory[i] = NULL;
	}
	inventory.clear();
	listSize = 0;
}

/*********************************************************************
** Description:		This function searches the list array for a
**					duplicate element compared to the object passed in.
**					If found a duplicate element, it will return the
**					array index. If not found, it will return -1.
*********************************************************************/
int List::searchList(string newItem)
{
	int duplicateLocation = -1;

	for (int i = 0; i < listSize; i++)
	{
		if (newItem == inventory[i]->getName())
		{
			duplicateLocation = i;
		}
	}

	return duplicateLocation;
}

/*********************************************************************
** Description:		This function returns the current inventory vector.
**
*********************************************************************/
vector<Item*> List::getInventory()
{
	return inventory;
}