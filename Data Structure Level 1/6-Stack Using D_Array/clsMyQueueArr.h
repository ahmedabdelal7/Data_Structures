#pragma once
#include "clsDynamicArray.h"

template <typename T>
class clsMyQueueArr
{
protected:
	clsDynamicArray<T> _MyList;

public:
	void push(T Value) {
		_MyList.InsertAtEnd(Value);
	}
	void pop() {
		_MyList.DeleteFirstItem();
	}
	T front() {
		return _MyList.GetItem(0);
	}
	T back() {
		return _MyList.GetItem(_MyList.Size() -1);
	}
	int Size() {
		return _MyList.Size();
	}
	T GetItem(T Value) {
		return _MyList.GetItem(Value);
	}
	void Reverse() {
		_MyList.Reverse();
	}
	void Clear() {
		_MyList.Clear();
	}
	bool IsEmpty() {
		return _MyList.IsEmpty();
	}

	//-----------------------------------------------
	void InsertAtFront(T Value) {
		_MyList.InsertAtBeginning(Value);
	}
	void InsertAtBack(T Value) {
		_MyList.InsertAtEnd(Value);
	}
	void InsertAfter(int Index, T Value){
		_MyList.InsertAfter(Index, Value);
	}
	void UpdateItem(int Index, T Value) {
		_MyList.SetItem(Index, Value);
	}
	void Print() {
		_MyList.PrintList();
	}
};

