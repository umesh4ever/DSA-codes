#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    system("cls");


    int a, b, operation;
    cout << "Enter the 1st numbers:" << endl;
    cin >> a;
    cout << "Enter the 2nd numbers:" << endl;
    cin >> b;
    cout << "what you wanna do:\n 1)Multiplication\n 2)Division\n 3)Addition \n 4)Substraction" << endl;
    cin >> operation;

    if (operation == 1)
    {
        cout << "The multiplication is:" << (a * b) << endl;
    }

    else if (operation == 2)
    {
        cout << "The division is:" << (a / b) << " and the remainder is " << a % b << endl;
    }

    else if (operation == 3)
    {
        cout << "The addition is:" << (a + b) << endl;
    }
    else if (operation == 4)
    {
        cout << "The substraction is:" << (a - b) << endl;
    }
    else
    {
        cout << "invalid operation" << endl;
    }
    return 0;
}