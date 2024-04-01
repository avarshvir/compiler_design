//using <map> STL
#include <iostream>
#include <stack>
#include <map>
using namespace std;

// knowing precedence using map
//key,pair value
map<char, int> precedence = {
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2}
};

// function to check operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

/*
this function performs the reduction operation using stack.
it pop top operator from the operators stack, and two operands from the operands stack.
the result of the operation is pushed to operands stack.
*/
void reduce(stack<char>& operators, stack<int>& operands) {
    char op = operators.top();
    operators.pop();
    int b = operands.top();
    operands.pop();
    int a = operands.top();
    operands.pop();

    switch (op) {
        case '+':
            operands.push(a + b);
            break;
        case '-':
            operands.push(a - b);
            break;
        case '*':
            operands.push(a * b);
            break;
        case '/':
            operands.push(a / b);
            break;
    }
}

// perator precedence parsing function
//it take arithmetic input 
int operatorPrecedenceParser(string input) {
    stack<char> operators;
    stack<int> operands;

//using for each loop
    for (char c : input) {
        if (isdigit(c)) {
            operands.push(c - '0');                                                                                                       // convert char digit to int
        } else if (isOperator(c)) {
            while (!operators.empty() && precedence[c] <= precedence[operators.top()]) {
                reduce(operators, operands);
            }
            operators.push(c);
        }
        else{
            cout << "Enter valid input";
        }
    }

    while (!operators.empty()) {
        reduce(operators, operands);
    }

    return operands.top();
}

int main() {
    string input = "3+4/2*2-5"; 
    int result = operatorPrecedenceParser(input);
    cout << "result: " << result << endl;
    return 0;
}
