#include <iostream> 
#include <string> 
using namespace std; 
const int SIZE = 100;   
class Stack { 
    string arr[SIZE]; 
    int top; 
public: 
    Stack() { top = -1; } 
    bool isEmpty() { return top == -1; } 
    bool isFull() { return top == SIZE - 1; } 
    void push(string val) { 
        if (isFull()) { 
            cout << "Stack Overflow!" << endl; 
            return; 
        } 
        arr[++top] = val; 
    } 
    string pop() { 
        if (isEmpty()) { 
            return "";  
        } 
        return arr[top--]; 
    } 
    string peek() { 
        if (isEmpty()) return ""; 
        return arr[top]; 
    } 
    void clear() { top = -1; } 
}; 
 
class Editor { 
    Stack undoStack, redoStack; 
    string text; 
public: 
    void addOperation(const string& op) { 
        undoStack.push(text);  
        if (!text.empty()) 
            text += " "; 
        text += op;              
        redoStack.clear();       
    } 
    void undo() { 
        if (undoStack.isEmpty()) { 
            cout << "Nothing to undo!" << endl; 
            return; 
        } 
        redoStack.push(text);    
        text = undoStack.pop();  
    } 
    void redo() { 
        if (redoStack.isEmpty()) { 
            cout << "Nothing to redo!" << endl; 
            return; 
        } 
        undoStack.push(text);    
        text = redoStack.pop();  
    } 
 
    void showText() { 
        cout << "Current Text: " << text << endl; 
    } 
}; 
int main() { 
    Editor editor; 
    int choice; 
    string input; 
    cout << "=== Simple Text Editor (Undo/Redo) ===" << endl; 
    do { 
        cout << "\nMenu:" << endl; 
        cout << "1. Add Text" << endl; 
        cout << "2. Undo" << endl; 
        cout << "3. Redo" << endl; 
        cout << "4. Show Current Text" << endl; 
        cout << "5. Exit" << endl; 
        cout << "Enter choice: "; 
        cin >> choice; 
        cin.ignore();  
        switch (choice) { 
            case 1: 
                cout << "Enter text to add: "; 
                getline(cin, input); 
                editor.addOperation(input); 
                break; 
            case 2: 
                editor.undo(); 
                break; 
            case 3: 
                editor.redo(); 
                break; 
            case 4: 
                editor.showText(); 
                break; 
            case 5: 
                cout << "Exiting program..." << endl; 
                break; 
            default: 
                cout << "Invalid choice!" << endl; 
        } 
    } while (choice != 5); 
    return 0; 
} 