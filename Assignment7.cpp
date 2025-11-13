#include <iostream>
#include <string> // Use C++ string header
// <conio.h> is non-standard and not needed
// <string.h> is C-style, replaced by <string> and <cstring>

using namespace std;
#define MAX 100

class Stack
{
private:
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    // Using bool for clarity, though int (1/0) also works
    bool isEmpty() { return (top == -1); }
    bool isFull() { return (top == MAX - 1); }

    void push(char ch)
    {
        if (!isFull())
        {
            arr[++top] = ch;
        }
        else
        {
            cout << "Stack Overflow!" << endl;
        }
    }

    char pop()
    {
        if (!isEmpty())
        {
            return arr[top--];
        }
        else
        {
            cout << "Stack Underflow!" << endl;
            return '\0'; // Return null character on underflow
        }
    }

    char peek()
    {
        if (!isEmpty())
            return arr[top];
        else
            return '\0'; // Return null character if empty
    }
};

// Class to check parentheses
class ParenthesisChecker
{
private:
    // Changed return type to bool (true/false) - more C++ idiomatic
    bool isMatchingPair(char opening, char closing)
    {
        if (opening == '(' && closing == ')')
            return true;
        if (opening == '{' && closing == '}')
            return true;
        if (opening == '[' && closing == ']')
            return true;
        return false;
    }

public:
    // Changed to accept a C++ string and return bool
    bool isWellParenthesized(const string &expr) // Use const string reference
    {
        Stack st;
        // int len = strlen(expr); // No longer needed

        // Use a modern C++ range-based for loop
        for (char ch : expr)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else if (ch == ')' || ch == '}' || ch == ']')
            {
                // isMatchingPair now returns bool
                if (st.isEmpty() || !isMatchingPair(st.peek(), ch))
                {
                    return false; // mismatch
                }
                st.pop();
            }
        }

        // Final check: stack must be empty
        return st.isEmpty();
    }
};

int main()
{
    // Use std::string instead of C-style char array
    string expression;

    cout << "Enter an expression: ";

    // FIX: Use std::getline for safe C++ line input
    // gets(expression); // <-- This was the unsafe C-function causing the error
    getline(cin, expression);

    ParenthesisChecker checker;

    // The if-statement works directly with the bool return type
    if (checker.isWellParenthesized(expression))
        cout << "The expression is well parenthesized." << endl;
    else
        cout << "The expression is NOT well parenthesized." << endl;

    return 0;
}