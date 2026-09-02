#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

class MinStack {
    stack<int> st, minstack;

public:
    MinStack() {}

    void push(int value) {
        minstack.empty() ? minstack.push(value) : minstack.push(min(minstack.top(), value));
        st.push(value);
    }

    void pop() {
        if (!st.empty()) { // Added a quick guard safety check for popping empty stacks
            st.pop();
            minstack.pop();
        }
    }

    int top() { 
        return st.top(); 
    }

    int getMin() { 
        return minstack.top(); 
    }
    
    bool empty() {
        return st.empty();
    }
};

int main() {
    MinStack obj;
    string command;
    
    cout << "--- Interactive MinStack Terminal ---\n";
    cout << "Commands available: push [val], pop, top, getMin, exit\n\n";

    while (true) {
        cout << "Enter command: ";
        cin >> command;

        if (command == "push") {
            int value;
            cin >> value;
            obj.push(value);
            cout << "Pushed " << value << " onto the stack.\n";
        } 
        else if (command == "pop") {
            if (obj.empty()) {
                cout << "Error: Stack is empty! Cannot pop.\n";
            } else {
                obj.pop();
                cout << "Popped the top element.\n";
            }
        } 
        else if (command == "top") {
            if (obj.empty()) {
                cout << "Error: Stack is empty!\n";
            } else {
                cout << "Top element is: " << obj.top() << "\n";
            }
        } 
        else if (command == "getMin") {
            if (obj.empty()) {
                cout << "Error: Stack is empty! No minimum.\n";
            } else {
                cout << "Minimum element is: " << obj.getMin() << "\n";
            }
        } 
        else if (command == "exit") {
            cout << "Exiting program. Goodbye!\n";
            break;
        } 
        else {
            cout << "Invalid command. Try: push, pop, top, getMin, or exit\n";
        }
        cout << endl;
    }

    return 0;
}
