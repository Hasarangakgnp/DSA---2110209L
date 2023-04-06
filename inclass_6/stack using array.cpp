#include <iostream>

using namespace std;

class Stack {
private:
    int top;
    int length;
    int* arr;

public:
    Stack(int size) {
        top = -1;
        length = size;
        arr = new int[length];
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        int value = arr[top--];
        return value;
    }

    bool isEmpty() {
        if(top == -1){
            return 1;
        }else{
            return 0;
        }
    }

    bool isFull() {
        return top == length - 1;
    }

    int stackTop() {
        if (isEmpty()) {
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Elements in the stack are: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
};

int main() {
    Stack s(10);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    s.display();

    return 0;
}
