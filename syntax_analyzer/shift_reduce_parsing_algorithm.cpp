#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool shiftReduceParsing(const string &input){
    stack<char> stack;
    for(char ch : input){
        if(ch == 'a'){
            stack.push(ch);
        }
        else if(ch == 'b'){
            if(stack.size() >= 2 && stack.top() == 'a'){
                stack.pop();
                stack.pop();
                stack.push('b');
            }else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    return stack.size() == 1 && stack.top() == 'b';
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