#include <iostream>
#include <string>
#include <cctype>

using namespace std;

enum class TokenType {
    UNKNOWN,
    NUMBER,
    OPERATOR,
    LEFT_PAREN,
    RIGHT_PAREN
};

struct Token {
    string lexeme;
    TokenType type;
};

class Lexer {
public:
    Lexer(const string& input) : input(input), currentPos(0) {}

    Token getNextToken() {
        while (currentPos < input.size() && isspace(input[currentPos])) {
            currentPos++; // Skip whitespace
        }

        if (currentPos == input.size()) {
            return { "", TokenType::UNKNOWN }; // End of input
        }

        char currentChar = input[currentPos];
        Token token;

        switch (currentChar) {
            case '(':
                token.lexeme = currentChar;
                token.type = TokenType::LEFT_PAREN;
                break;
            case ')':
                token.lexeme = currentChar;
                token.type = TokenType::RIGHT_PAREN;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                token.lexeme = currentChar;
                token.type = TokenType::OPERATOR;
                break;
            default:
                if (isdigit(currentChar)) {
                    token.lexeme += currentChar;
                    token.type = TokenType::NUMBER;

                    while (currentPos + 1 < input.size() && isdigit(input[currentPos + 1])) {
                        token.lexeme += input[currentPos + 1];
                        currentPos++;
                    }
                } else {
                    token.lexeme = currentChar;
                    token.type = TokenType::UNKNOWN;
                }
                break;
        }

        currentPos++;
        return token;
    }

private:
    string input;
    size_t currentPos;
};

int main() {
    string input;
    cout << "Enter arithmetic expression: ";
    getline(cin, input);

    Lexer lexer(input);

    cout << "Tokens:" << endl;
    Token token;
    do {
        token = lexer.getNextToken();
        switch (token.type) {
            case TokenType::NUMBER:
                cout << "Number: " << token.lexeme << endl;
                break;
            case TokenType::OPERATOR:
                cout << "Operator: " << token.lexeme << endl;
                break;
            case TokenType::LEFT_PAREN:
                cout << "Left Parenthesis: " << token.lexeme << endl;
                break;
            case TokenType::RIGHT_PAREN:
                cout << "Right Parenthesis: " << token.lexeme << endl;
                break;
            default:
                cout << "Unknown: " << token.lexeme << endl;
                break;
        }
    } while (token.type != TokenType::UNKNOWN);

    return 0;
}
