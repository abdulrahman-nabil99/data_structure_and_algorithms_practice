#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

template<class T>
struct Node {
    T value;
    Node<T>* next;
};

template<class T>
class ArrayStack {
private:
    int _size = 0;
    int _index = -1;
    T* _stackArray;
public:
    #pragma region CTRS
    // Constructor
    ArrayStack(int size) {
        _size = size;
        _stackArray = new T[_size];
    }

    // Copy constructor
    ArrayStack(const ArrayStack& other) : _size(other._size), _index(other._index) {
        _stackArray = new T[_size];
        for (int i = 0; i <= _index; ++i)
            _stackArray[i] = other._stackArray[i];
    }

    // Copy assignment
    ArrayStack& operator=(const ArrayStack& other) {
        if (this != &other) {
            delete[] _stackArray;
            _size = other._size;
            _index = other._index;
            _stackArray = new T[_size];
            for (int i = 0; i <= _index; ++i)
                _stackArray[i] = other._stackArray[i];
        }
        return *this;
    }

    ~ArrayStack() {
        delete[] _stackArray;
    }
    #pragma endregion

    #pragma region Methods
    bool push(const T& element) {
        if (isFull()) {
            return false;
        }
        _stackArray[++_index] = element;
        return true;
    }

    bool pop(T& outValue) {
        if (isEmpty()) {
            return false;
        }
        outValue = _stackArray[_index--];
        return true;
    }

    bool peek(T& outValue) const {
        if (isEmpty())
            return false;

        outValue = _stackArray[_index];
        return true;
    }

    bool peekAt(int position, T& outValue) const {
        int target = (_index - position + 1);
        if (_index < 0 || target < 0 || target > _index)
            return false;
        outValue = _stackArray[target];
        return true;
    }

    int size() const {
        return _index + 1;
    }

    bool isEmpty() const {
        return size() == 0;
    }

    bool isFull() const {
        return size() == _size;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        int currentSize = size();
        cout << "[Top] ";
        for (int i = 1; i <= currentSize; i++) {
            T element;
            bool hasValue = peekAt(i, element);
            if (hasValue)
                cout << element;
            if (i != currentSize) {
                cout << " -> ";
            }
        }
        cout << " [Bottom]\n";
        cout << "\n";
    }
    #pragma endregion

};

template<class T>
class LinkedListStack {
private:
    Node<T>* _top;

public:
    #pragma region CTORS
    LinkedListStack() : _top(nullptr) {}

    ~LinkedListStack() {
        while (_top) {
            Node<T>* temp = _top;
            _top = _top->next;
            delete temp;
        }
    }

    LinkedListStack(const LinkedListStack&) = delete;
    LinkedListStack& operator=(const LinkedListStack&) = delete;
    #pragma endregion

    #pragma region Methods
    bool push(const T& element) {
        Node<T>* item = new(std::nothrow) Node<T>;
        if (!item) return false;

        item->value = element;
        item->next = _top;
        _top = item;

        return true;
    }

    bool pop(T& outValue) {
        if (isEmpty()) return false;

        Node<T>* item = _top;
        _top = _top->next;

        outValue = item->value;
        delete item;

        return true;
    }

    bool isFull() const {
        Node<T>* item = new(std::nothrow) Node<T>;
        if (!item) return true;
        delete item;
        return false;
    }

    bool isEmpty() const{
        return _top == nullptr;
    }

    bool peek(T& outValue) const {
        if (isEmpty())
            return false;

        outValue = _top->value;
        return true;
    }

    bool peekAt(int position, T& outValue) const {
        if (position <= 0) return false;

        Node<T>* current = _top;
        int i = 1;

        while (current) {
            if (i == position) {
                outValue = current->value;
                return true;
            }
            current = current->next;
            i++;
        }

        return false;
    }
    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        Node<T>* current = _top;
        cout << "[Top] ";
        while (current) {
            cout << current->value;
            current = current->next;
            if (current)
                cout << " -> ";
        }
        cout << " [Bottom]\n";
    }
    #pragma endregion
};

bool parentheses_matching(const char[], size_t);

char* infix_to_postfix(const char[], size_t);

int evaluate_postfix(char*, size_t);

template<class T>
void display_array_then_delete(T* array, size_t size) {
    if (!array) return;

    for (size_t i = 0; i < size; i++) {
        cout << array[i];
    }
    cout << endl;
    int total = evaluate_postfix(array, strlen(array));
    delete[] array;
}



int main()
{
    cout << "ARRAY STACK!\n";
    ArrayStack<int> stack(5);
    stack.push(1);
    stack.push(3);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.display();

    cout << "LINKEDLIST STACK!\n";
    LinkedListStack<int> linkedStack;
    linkedStack.push(1);
    linkedStack.push(3);
    linkedStack.push(5);
    linkedStack.push(6);
    int value;
    linkedStack.pop(value);
    linkedStack.push(7);
    linkedStack.display();
    linkedStack.peekAt(3, value);
    cout << "PEAK AT (3) = " << value << endl;

    char data[] = "(6 + 1) * (5 + 3)\0";
    cout << "parentheses_matching(\"" << data << "\") = " << parentheses_matching(data, strlen(data)) << endl;

    char data2[] = "((6 + 1) * (5 + 3)\0";
    cout << "parentheses_matching(\"" << data2 << "\") = " << parentheses_matching(data2, strlen(data2)) << endl;


    char data3[] = "([{}}])\0";
    cout << "parentheses_matching(\"" << data3 << "\") = " << parentheses_matching(data3, strlen(data3)) << endl;

    char data4[] = "([{}])\0";
    cout << "parentheses_matching(\"" << data4 << "\") = " << parentheses_matching(data4, strlen(data4)) << endl;


    //char infix[] = "a+b*c-d/e";
    //char* postfix = infix_to_postfix(infix, strlen(infix));
    //cout << "Result for a+b*c-d/e: ";
    //display_array_then_delete(postfix, strlen(postfix));


    //char infix2[] = "a+b+c";
    //char* postfix2 = infix_to_postfix(infix2, strlen(infix2));
    //cout << "Result for a+b+c: ";
    //display_array_then_delete(postfix2, strlen(postfix2));

    //char infix3[] = "a*b/c+d";
    //char* postfix3 = infix_to_postfix(infix3, strlen(infix3));
    //cout << "Result for a*b/c+d: ";
    //display_array_then_delete(postfix3, strlen(postfix3));

    //char infix4[] = "a+b*c+d*e";
    //char* postfix4 = infix_to_postfix(infix4, strlen(infix4));
    //cout << "Result for a+b*c+d*e: ";
    //display_array_then_delete(postfix4, strlen(postfix4));

    //char infix5[] = "a^(b+c*d)-e";
    //char* postfix5 = infix_to_postfix(infix5, strlen(infix5));
    //cout << "Result for a^(b+c*d)-e: ";
    //display_array_then_delete(postfix5, strlen(postfix5));

    //char infix6[] = "a^b^c";
    //char* postfix6 = infix_to_postfix(infix6, strlen(infix6));
    //cout << "Result for a^b^c: ";
    //display_array_then_delete(postfix6, strlen(postfix6));

    //char infix7[] = "(a^b)^c";
    //char* postfix7 = infix_to_postfix(infix7, strlen(infix7));
    //cout << "Result for (a^b)^c: ";
    //display_array_then_delete(postfix7, strlen(postfix7));

    char infix7[] = "(2^3)^4";
    char* postfix7 = infix_to_postfix(infix7, strlen(infix7));
    cout << "Result for (2^3)^4: ";
    display_array_then_delete(postfix7, strlen(postfix7));


    char infix8[] = "(9^2)^2";
    char* postfix8 = infix_to_postfix(infix8, strlen(infix8));
    cout << "Result for (2^3)^4: ";
    display_array_then_delete(postfix8, strlen(postfix8));
}

bool parentheses_matching(const char data[], size_t size)
{
    LinkedListStack<char> stack;
    for (int i = 0; i < size; i++) {
        if (data[i] == '(' || data[i] == '[' || data[i] == '{') {
            stack.push(data[i]);
        }
        else if (data[i] == ')' || data[i] == ']' || data[i] == '}') {
            char item;
            if (!stack.pop(item) || 
                (data[i] == ')' && item != '(')||
                (data[i] == ']' && item != '[')||
                (data[i] == '}' && item != '{')
                ) {
                return false;
            }
        }
    }
    return stack.isEmpty();
}

bool is_operand(char item) {
    return item != '+' &&
        item != '-' &&
        item != '*' &&
        item != '/' &&
        item != '(' &&
        item != ')' &&
        item != '^';
}

int op_pre_in(char op) {
    if (op == '+' || op == '-') return 2;
    if (op == '*' || op == '/') return 4;
    if (op == '^') return 5;
    if (op == '(') return 0;
    return 0;
}

int op_pre_out(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 3;
    if (op == '^') return 6;
    if (op == '(') return 7;
    if (op == ')') return 0;
    return 0;
}

int calc_value(int right, int left, char op) {
    int result;
    switch (op) {
    case '+':
        result = left + right;
        break;
    case '-':
        result = left - right;
        break;
    case '*':
        result = left * right;
        break;
    case '/':
        if (right == 0) return 0;
        result = left / right;
        break;
    case '^':
        result = pow(left, right);
        break;
    default: result = 0;
    }
    return result;
}

char* infix_to_postfix(const char infix[], size_t size) {
    if (size <= 0) return nullptr;
    LinkedListStack<char> stk;
    char *postfix = new char[size + 1];
    int i = 0, j = 0;

    while (i < size) {
        if (is_operand(infix[i])) {
            postfix[j++] = infix[i++];
        }
        else {
            char top, op;
            if (infix[i] == ')') {
                while (stk.pop(op) && op != '(') {
                    postfix[j++] = op;
                }
                i++;
            }
            else {
                while (stk.peek(top) && op_pre_in(top) >= op_pre_out(infix[i])) {
                    stk.pop(op);
                    if (op != '(' && op != ')')
                        postfix[j++] = op;
                }
                stk.push(infix[i++]);
            }

        }
    }
    char val;
    while (stk.pop(val)) {
        postfix[j++] = val;
    }

    postfix[j] = '\0';

    return postfix;
}

int evaluate_postfix(char* postfix, size_t size) {
    LinkedListStack<int> stk;
    for (size_t i = 0; i < size; i++) {
        if (is_operand(postfix[i])) {
            stk.push(postfix[i] - '0');
        }
        else {
            int right, left;
            char op;
            op = postfix[i];
            stk.pop(right);
            stk.pop(left);
            int result = calc_value(right, left, op);
            stk.push(result);
        }
    }

    int total;
    stk.pop(total);
    cout << "Postfix Result = " << total << endl;
    return total;
}
