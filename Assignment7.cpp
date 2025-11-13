#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
#define MAX 100   

class Stack {
private:
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    int isEmpty() { return (top == -1); }
    int isFull() { return (top == MAX - 1); }

    void push(char ch) {
        if (!isFull()) {
            arr[++top] = ch;
        } else {
            cout << "Stack Overflow!" << endl;
        }
    }

    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        } else {
            cout << "Stack Underflow!" << endl;
            return '\0';
        }
    }

    char peek() {
        if (!isEmpty())
            return arr[top];
        else
            return '\0';
    }
};

// Class to check parentheses
class ParenthesisChecker {
private:
    int isMatchingPair(char opening, char closing) {
        if (opening == '(' && closing == ')') return 1;
        if (opening == '{' && closing == '}') return 1;
        if (opening == '[' && closing == ']') return 1;
        return 0;
    }

public:
    int isWellParenthesized(char expr[]) {
        Stack st;
        int len = strlen(expr);

        for (int i = 0; i < len; i++) {
            char ch = expr[i];

            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else if (ch == ')' || ch == '}' || ch == ']') {
                if (st.isEmpty() || !isMatchingPair(st.peek(), ch)) {
                    return 0; // mismatch
                }
                st.pop();
            }
        }
        return st.isEmpty();
    }
};

int main() {
    
    char expression[200];

    cout << "Enter an expression: ";
    gets(expression);   // old C-style input

    ParenthesisChecker checker;

    if (checker.isWellParenthesized(expression))
        cout << "The expression is well parenthesized." << endl;
    else
        cout << "The expression is NOT well parenthesized." << endl;

    return 0;
}

