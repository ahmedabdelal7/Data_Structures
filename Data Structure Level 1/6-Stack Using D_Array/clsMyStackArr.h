#pragma once

#include "clsMyQueueArr.h"
template <typename T>
class clsMyStackArr : public clsMyQueueArr<T>
{

public:
	void push(T Value) {
		clsMyQueueArr<T>::_MyList.InsertAtBeginning(Value);
	}
	T Top() {
		return clsMyQueueArr<T>::front();
	}
	T Bottom() {
		return clsMyQueueArr<T>::back();
	}
	void InsertAtTop(T Value) {
		clsMyQueueArr<T>::InsertAtFront(Value);
	}
	void InsertAtBottom(T Value) {
		clsMyQueueArr<T>::InsertAtBack(Value);
	}
};

