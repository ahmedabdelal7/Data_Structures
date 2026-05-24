#pragma once
#include <iostream>
using namespace std;
//static int _Size = 0;
template <typename T>
class clsDynamicArray
{
protected:

	int _Size = 0;
	T* _TempArray = NULL;

public:

	T* OrignalArray = NULL;

	clsDynamicArray(int Size = 0) {
		if (Size < 0)
			Size = 0;

		_Size = Size;

		OrignalArray = new T[_Size];
	}
	~clsDynamicArray() {
		
		delete[] OrignalArray;
		//delete[] _TempArray;
	}

	bool SetItem(int Index, T NewValue) {
		
		if (Index >= _Size || Index < 0) {
			return false;
		}
		else {
			OrignalArray[Index] = NewValue;
		}

	}

	int Size() {
		return _Size;
	}

	bool IsEmpty(){
		return (_Size == 0);
	}

	void PrintList() {
		cout << "\n";
		for (int i = 0; i < _Size; i++)
		{
			//cout << i[OrignalArray] << " ";
			//cout << OrignalArray[i] << " ";
			cout << *(OrignalArray + i) << " ";
		}cout << endl;
	}


	void Resize(int NewSize) {

		//if New Size < 0
		if (NewSize < 0)
			NewSize = 0;

		// careat Temp dynamic array in memmory heap
		_TempArray = new T[NewSize];

		 //if newSize < OrignalSize

		if (NewSize < _Size) {
			_Size = NewSize;
		}	

		//copy just (NewSize) orignal array elements  to Temp array: exp: temp array take first 2 elemnts of orignal array  
		for (int i = 0 ; i < _Size; i++)
		{
			_TempArray[i] = OrignalArray[i];
		}
		//delete orignal array from memory after copied.
		delete[] OrignalArray;

		//Make orignal array point at Temp array heap location.
		OrignalArray = _TempArray;
		
		_Size = NewSize; // reassign object (_Size) Variable with (NewSize)

	}

	T GetItem(int Index) {
		/*if (Index > _Size || Index < 0)
			return;*/

		return OrignalArray[Index];
	}
	void Reverse() {

		if (_Size < 2)
			return;

		_TempArray = new T[_Size];

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OrignalArray[_Size - 1 - i];
		}
		delete[] OrignalArray;

		OrignalArray = _TempArray;
	}
	void Clear() {

		_TempArray = new T[0];

		delete[] OrignalArray;

		OrignalArray = _TempArray;
		_Size = 0;

		// or this best
		
		//delete[] OrignalArray;
		//OrignalArray = nullptr;
		//_Size = 0;
	}

	bool DeleteItemAt(int Index) {
		if (Index >= _Size || Index < 0)
			return false;

		_Size--;
		_TempArray = new T[_Size];

		//Copy all elements to TempArray before index
		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OrignalArray[i];
		}

		//copy all elements after Index
		for (int i = Index +1; i <= _Size; i++) // Size+1 -> orignal size
		{
			_TempArray[i - 1] = OrignalArray[i];
		}

		delete[] OrignalArray;
		OrignalArray = _TempArray;

		return true;
	}

	void DeleteFirstItem() {

		//if (_Size <= 0)
		//	return;
		//for (int i = 0; i < _Size -1; i++)
		//{
		//	OrignalArray[i] = OrignalArray[i + 1];
		//}
		//_Size--;

		DeleteItemAt(0);
	}

	void DeleteLastItem() {

		//if (_Size <= 0)//5
		//	return;

		//for (int i = 0; i < _Size-1; i++)//4
		//{
		//	OrignalArray[ i ] = OrignalArray[i];
		//}
		//_Size--;

		DeleteItemAt(_Size - 1);

	}

	int Find(T Item) {

		for (int i = 0; i < _Size; i++)
		{
			if (Item == OrignalArray[i])
				return i;
		}
		return -1;

	}

	bool DeleteItem(T Item) {

		int ItemIndex = Find(Item);

		if (ItemIndex != -1) {
			DeleteItemAt(ItemIndex);
			return true;
		}
		return false;
	}

	bool InsertAt(int Index, T Value) {

		if (Index > _Size || Index < 0)
			return false;

		_Size++;
		_TempArray = new T[_Size];

		//copy elements before Index
		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OrignalArray[i];
		}
		_TempArray[Index] = Value;

		//copy elements After Index
		for (int i = Index; i < _Size -1; i++)
		{
			_TempArray[i + 1] = OrignalArray[i];
		}//

		delete[] OrignalArray;

		OrignalArray = _TempArray;
		return true;
	}

	bool InsertAtBeginning(T Value) {
		return InsertAt(0, Value);
	}

	bool InsertAtEnd(T Value) {
		return InsertAt(_Size, Value);
	}

	bool InsertAfter(int index, T value)
	{
		if (index >= _Size)
			return InsertAtEnd(value);
		else
			return InsertAt(index + 1, value);
	}

	bool InsertBefore(int Index, T Value) {

		return InsertAt(Index, Value);
	}
	

};
 