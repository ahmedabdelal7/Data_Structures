#pragma once
#include <stack>
#include <iostream>
using namespace std;
class clsMyString
{
private:
	string _Value;
	stack <string> _UndoStack;
	stack <string> _RedoStack;

public:
	string GetValue() {
		return _Value;
	}

	void SetValue(string Value) {
		_UndoStack.push(_Value);
		_Value = Value;
	}
	_declspec(property(get = GetValue, put = SetValue))string Value;

	void Undo() {
		if (!_UndoStack.empty()) {
			_RedoStack.push(_Value);
			_Value = _UndoStack.top();
			_UndoStack.pop();
		}
	}

	void Redo() {
		if (!_RedoStack.empty() ) {
			_UndoStack.push(_Value);
			_Value = _RedoStack.top();
			_RedoStack.pop();
		}
	}
};

