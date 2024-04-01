#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isOperator(char ch){
    return  ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

bool shiftReduceParsing(const string &input){
    stack<char> stack;
    for(char ch : input){
        stack.push(ch);
        while(stack.size() >= 3 && isOperator(stack.top())){
            char op2 = stack.top();
            stack.pop();
            char op1 = stack.top();
            stack.pop();
            char op = stack.top();
            stack.pop();

            if(isOperator(op) && !isOperator(op1) && !isOperator(op2)){
                stack.push('N');
            }
            else{
                stack.push(op);
                stack.push(op1);
                stack.push(op2);
                break;
            }
        }
    }
    return stack.size() == 1 && stack.top() == 'N';
}

int main(){
    string input;
    cout << "Enter input string :";
    cin >> input;

    if(shiftReduceParsing(input)){
        cout << "Valid input"<<endl;
    }
    else{
        cout << "Invalid input"<<endl;
    }
    return 0;
}