#include <iostream>
using namespace std;

#define MAX 100

class Stack {
public:
    char arr[MAX];
    int top;

    Stack() {
        top = -1;
    }

    void push(char x) {
        if (top < MAX - 1) {
            arr[++top] = x;
        }
    }

    char pop() {
        if (top >= 0) {
            return arr[top--];
        }
        return '\0';
    }

    char peek() {
        if (top >= 0) {
            return arr[top];
        }
        return '\0';
    }

    bool isEmpty() {
        return top == -1;
    }
};

int isOperand(char ch) {
    if ((ch >= 'a' && ch <= 'z') ||
        (ch >= 'A' && ch <= 'Z') ||
        (ch >= '0' && ch <= '9'))
        return 1;
    return 0;
}

string reverseString(string str) {
    Stack s;
    for (int i = 0; str[i] != '\0'; i++) {
        s.push(str[i]);
    }

    string rev = "";
    while (!s.isEmpty()) {
        rev += s.pop();
    }
    return rev;
}

bool isBalanced(string expr) {
    Stack s;
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') {
            s.push(expr[i]);
        }
        else if (expr[i] == ')') {
            if (s.isEmpty()) {
                return false;
            }
            s.pop();
        }
    }
    return s.isEmpty();
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string expr) {
    Stack s;
    string postfix = "";

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (isOperand(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop();
        }
        else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                postfix += s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

int main() {
    string str, expr;

    cout << "Enter a string: ";
    cin >> str;
    cout << "Reversed String: " << reverseString(str) << endl;

    cout << "Enter expression to check parentheses: ";
    cin >> expr;
    if (isBalanced(expr))
        cout << "Balanced Parentheses\n";
    else
        cout << "Not Balanced\n";

    cout << "Enter infix expression: ";
    cin >> expr;
    cout << "Postfix Expression: " << infixToPostfix(expr) << endl;

    return 0;
}