#pragma once
#include <iostream>
using namespace std;

template <typename T>
class clsDblLinkedList
{
	
protected:
	int _Size =0;
public:
	class Node
	{
	public:
		T value;
		Node* next;
		Node* prev;
	};

	Node * head = NULL;

	void PrintList() {
		if (head == NULL)
			return;

		Node* current = head;
		while (current != NULL)
		{
			cout << current->value << " ";
			current = current->next;
		}
		cout << "\n";
		//delete current;
	}

	void InsertAtBeginning(T Value) {
		Node* NewNode = new Node();
		NewNode->value = Value;
		NewNode->prev = NULL;
		NewNode->next = head;

		if (head != NULL) {
			head->prev = NewNode;
		}
		head = NewNode;
		_Size++;
	}

	void InsertAtEnd(T Value) {

		Node* NewNode = new Node();
		NewNode->value = Value;
		NewNode->next = NULL;

		if (head == NULL){
			NewNode->prev = NULL;
			head = NewNode;
		}
		else {
			Node* current = head;
			while (current->next != NULL)
			{
				current = current->next;
			}

			current->next = NewNode;
			NewNode->prev = current;
		}		
		_Size++;

	}

	void InsertAfter(Node* current, T Value) {

		//if (current == NULL) {
		//	return;
		//}
		//Node* NewNode = new Node();
		//NewNode->_value = Value;
		//NewNode->_prev = NULL;
		//

		//if (current->_next == NULL)
		//{
		//	NewNode->_prev = current;
		//	NewNode->_next = current->_next;
		//	current->_next = NewNode;
		//	return;
		//}
		//if (current->_next != NULL) {
		//	NewNode->_next = current->_next;
		//	NewNode->_prev = current;
		//	current->_next->_prev = NewNode;
		//	current->_next = NewNode;

		//}


		Node* NewNode = new Node();
		NewNode->value = Value;
		NewNode->next = current->next;
		NewNode->prev = current;

		if (current->next != NULL) {
			current->next->prev = NewNode;
		}
		current->next = NewNode;
		_Size++;
	}

	Node* Find(T Value) {

		Node* current = head;

		while (current != NULL)
		{

			if (current->value == Value)
				return current;

			current = current->next;
		}

		return NULL;
	}

	void DeleteNode(Node* &NodeToDelete) {

		if (head == NULL || NodeToDelete == NULL)
			return;

		if (head = NodeToDelete) {
			head = NodeToDelete->next;
		}

		if (NodeToDelete->next != NULL) {
			NodeToDelete->next->prev = NodeToDelete->prev;
		}

		if (NodeToDelete->prev != NULL) {
			NodeToDelete->prev->next = NodeToDelete->next;
		}
		_Size--;

		delete NodeToDelete;

	}

	void DeleteFirstNode(){
		
		if (head == NULL)
			return;

		Node* Temp = head;

		head = head->next;

		if (head != NULL) {
			head->prev = NULL;
		}
		delete Temp;
		_Size--;

	}

	void DeleteLastNode(){
	
		if (head == NULL)
			return;

		if (head->next == NULL) {
			head = NULL;
			delete head;
			_Size--;
			return;
		}

		Node* current = head;
		while (current->next->next != NULL)
		{
			current = current->next;
		}
		Node* Temp = current->next;
		current->next = NULL;
		delete Temp;
		_Size--;
	}

	int Size() {

		return _Size;

	}

	bool IsEmpty() {
		return (_Size == 0);
	}

	void Clear() {

		while (_Size > 0)
		{
			DeleteFirstNode();
		}
	}
	
	void Reverse()
	{
		Node* current = head;
		Node* temp = NULL;

		while (current != NULL)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;

			current = current->prev;
		}

		if (temp != NULL)
			head = temp->prev;
	}

	Node* GetNode(int index) {

		if (index > _Size - 1 || index < 0)
			return NULL;

		Node* current = head;
		int counter = 0;

		while (current != NULL)
		{	
			if (index == counter)
				return current;
			current = current->next;
			counter++;
		}
	
	}

	T GetItem(int index) {

		Node* ItemNode = GetNode(index);

		if (ItemNode == NULL)
			return NULL;
		else
			return ItemNode->value;

	}

	bool UpdateItem(int Index,T NewValue) {

		Node* ItemNode = GetNode(Index);

		if (ItemNode != NULL) {

			ItemNode->value = NewValue;
			return true;
		}
		else
			return false;

	}

	bool InsertAfter(int Index, T Value) {

		Node* ItemNode = GetNode(Index);

		if (ItemNode != NULL) {
			InsertAfter(ItemNode, Value);
			return true;
		}
		return false;

	}


};

