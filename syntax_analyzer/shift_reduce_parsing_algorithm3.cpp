#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool shiftReduceParsing(const string &input)
{
    stack<char> parseStack;

    cout << "step \t input \t  stack \n";
    cout << "---------------------------" << endl;

    for (char ch : input)
    {
        cout << " " << ch << "\t \t  ";
        if (ch == 'a')
        {
            parseStack.push(ch);
        }
        else if (ch == 'b')
        {
            cout << "\t\t";
            if (parseStack.size() >= 2 && parseStack.top() == 'a')
            {
                parseStack.pop();
                parseStack.pop();
                parseStack.push('b');
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }

        stack<char> printStack = parseStack;
        while (!printStack.empty())
        {
            cout << printStack.top();
            printStack.pop();
        }
        cout << endl;
    }
    return parseStack.size() == 1 && parseStack.top() == 'b';
}

int main()
{
    string input;
    cout << "Enter input string :";
    cin >> input;

    if (shiftReduceParsing(input))
    {
        cout << "Valid input" << endl;
    }
    else
    {
        cout << "Invalid input" << endl;
    }
    return 0;
}