#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
    vector<int> stack;
public:
    Stack() {}

    Stack(vector<int> s) : stack(s) {}

    void push(int value) {
        if (isFull() == 0) {
            stack.push_back(value);
        }
        else {
            cout << "Stack is full!";
        }
    }

    int pop() {
        if (isEmpty() == 0) {
            int value = stack.back();
            stack.pop_back();
            return value;
        }
        else {
            cout << "Stack is empty!";
            return -1;
        }
    }

    int top() {
        if (isEmpty() == 0) {
            return stack.back();
        }
        else {
            cout << "Stack is empty!";
            return -1;
        }
    }

    bool isEmpty() {
        return stack.empty();
    }

    bool isFull() {
        if (stack.capacity() == size()) {
            return 1;
        }
        else {
            return 0;
        }
    }

    int size() {
        return stack.max_size();
    }
};

int main()
{
    Stack s;

    if (s.isEmpty()) {
        cout << "Stack is empty." << endl;
    }
    else {
        cout << "Stack is not empty." << endl;
    }

    s.push(5);
    s.push(10);
    s.push(15);

    cout << "Top element: " << s.top() << endl;

    int removed = s.pop();
    cout << "Removed: " << removed << endl;

    cout << "Top element: " << s.top() << endl;

    s.pop();
    s.pop();

    s.pop();
}