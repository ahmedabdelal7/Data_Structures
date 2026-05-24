#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;

template <typename T>
class clsMyQueue
{
protected:
	
	//using Composition
	clsDblLinkedList <T>_MyList;

public:



	void push(T Value) {

		_MyList.InsertAtEnd(Value);
	}

	void pop() {
		
		_MyList.DeleteFirstNode();
	}

	int Size() {
		return _MyList.Size();
	}

	T front() {
		return _MyList.GetItem(0);
	}

	T back() {
		return _MyList.GetItem(Size() - 1);
	}

	void Print() {

		_MyList.PrintList();
	}


	T GetItem(int Index) {
		return _MyList.GetItem(Index);
	}

	void Reverse() {
		_MyList.Reverse();
	}

	void UpdateItem(int Index, T NewValue) {
		_MyList.UpdateItem(Index, NewValue);
	}
	void InsertAfter(int Index, T Value) {
		_MyList.InsertAfter(Index, Value);
	}

	void InsertAtFront(T Value) {
		_MyList.InsertAtBeginning(Value);
	}

	void InsertAtBack(int Value) {
		_MyList.InsertAtEnd(Value);
	}

	void Clear() {
		_MyList.Clear();
	}



};

