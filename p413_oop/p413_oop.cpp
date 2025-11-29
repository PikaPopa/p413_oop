#include <iostream>

using namespace std;

class Stack {
private:
    int* arr;
    int capacity;
    int topIndex;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack is full!" << endl;
        }
        else {
            topIndex++;
            arr[topIndex] = value;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        else {
            int value = arr[topIndex];
            topIndex--;
            return value;
        }
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        else {
            return arr[topIndex];
        }
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == capacity - 1;
    }

    int size() {
        return topIndex + 1;
    }
};

int main()
{
    Stack s(5);

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    s.push(6);

    s.pop();
    s.pop();
    s.pop();

    cout << "Top element: " << s.top() << endl;
    cout << "Size: " << s.size() << endl;

    s.pop();
    s.pop();

    s.pop();
}