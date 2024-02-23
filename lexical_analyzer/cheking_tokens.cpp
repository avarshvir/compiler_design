#include <iostream>
#include <string>
using namespace std;

void isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        cout << "Valid Operator" << endl;
    } else {
        cout << "Invalid Operator" << endl;
    }
}

void isKeyword(const string& s) {
    if (s == "for" || s == "while" || s == "do" || s == "if" || s == "else" || s == "int" || s == "float" || s == "char" || s == "double") {
        cout << s << " is a keyword" << endl;
    } else {
        cout << s << " is not a keyword" << endl;
    }
}

void input() {
    string inputStr;
    getline(cin, inputStr);

    // Separate operator and keyword
    char op = inputStr[0];
    string keyword = inputStr.substr(1);

    isOperator(op);
    isKeyword(keyword);
}

int main() {
    cout << "Enter the expression to know the type of tokens" << endl;
    input();
    return 0;
}
