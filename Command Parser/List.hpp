/******************************************************************
** Author: 			Artem Slivka
** Date: 			07/15/17
** Description:		List.hpp is the header file for class List.
**					It contains function declarations for the class.
******************************************************************/

#ifndef LIST_HPP
#define LIST_HPP
#include "Item.hpp"
#include <vector>
using std::vector;

class List
{
private:
	vector<Item*> inventory;
	int listSize;
	bool emptyItem = false;

public:
	List();
	//List(int size);
	~List();
	void printList();
	void addItem(string fitemName, int fquantity);
	void addItem(Item* newItem);
	void removeItem();
	void incrementList();
	int searchList(string newItem);
	void updateSize();
	int getSize();
	vector<Item*> getInventory();
	void clearList();
	
};

#endif 
