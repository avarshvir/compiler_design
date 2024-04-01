#include <iostream>
#include <stack>
using namespace std;

// finding precedence using arrays
const int MAX_OPERATORS = 4; 
const char operators[MAX_OPERATORS] = {'+', '-', '*', '/'};
const int precedence[MAX_OPERATORS] = {1, 1, 2, 2};

bool isOperator(char c) {
    /*
    for (int i = 0; i < MAX_OPERATORS; ++i) {
        if (c == operators[i]) {
            return true;
        }
    }
    return false;*/
    if(c == '+' || c == '-' || c == '*' || c == '/'){
        return true;
    }
    else{
        return false;
    }
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

    for (char c : input) {
        if (isdigit(c)) {
            operands.push(c - '0'); 
        } else if (isOperator(c)) {
            while (!operators.empty() && precedence[c - '+'] <= precedence[operators.top() - '+']) {
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
    string input ;
    cout << "Enter input : ";
    cin >> input;
    int result = operatorPrecedenceParser(input);
    cout << "Result: " << result << endl;
    return 0;
}
