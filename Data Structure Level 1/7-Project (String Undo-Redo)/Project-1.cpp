

#include <iostream>
#include "clsMyString.h"
using namespace std;

int main()
{
    clsMyString S1;

    cout << "\nS1 = " << S1.Value << endl;

    S1.Value = "Ahmed1";

    cout << "\nS1 = " << S1.Value << endl;

    S1.Value = "Ahmed2";

    cout << "\nS1 = " << S1.Value << endl;

    S1.Value = "Ahmed3";

    cout << "\nS1 = " << S1.Value << endl;

    S1.Value = "Ahmed4";

    cout << "\nS1 = " << S1.Value << endl;

    S1.Undo();
    cout << "\nS1 after undo = " << S1.Value << endl;

    S1.Undo();
    cout << "\nS1 after undo = " << S1.Value << endl;

    S1.Undo();
    cout << "\nS1 after undo = " << S1.Value << endl;

    S1.Undo();
    cout << "\nS1 after undo = " << S1.Value << endl;


    system("pause>0");

}