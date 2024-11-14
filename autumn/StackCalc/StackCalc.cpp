#include <iostream>
#include <cmath>
#include <cctype>
#include "Stack.h"

using namespace std;

Stack<double> stack(256);

void onAdd();
void onSub();
void onMul();
void onDiv();
void display();
void onShow();
void onDup();
void onExch();

void distance();
void distanceToLine();
void intersectLines();
void inCircle();
void circumCircle(); 

void printHelp();

int main() {
    printHelp();
    while (true) {
        string s;
        cin >> s;
        if (!cin.good()) 
            break;
        try {
            if (s == "+") {
                onAdd();
            } else if (s == "-") {
                onSub();
            } else if (s == "*") {
                onMul();
            } else if (s == "/") {
                onDiv();
            } else if (s == "=") {
                display();
            } else if (s == "pop") {
                stack.pop();
            } else if (s == "clear") {
                stack.clear();
            } else if (s == "show") {
                onShow();
            } else if (s == "dup") {
                onDup();
            } else if (s == "exch") {
                onExch();
            } else if (
                isdigit(s[0]) ||
                (
                    s.size() > 1 &&
                    (s[0] == '+' || s[0] == '-') &&
                    isdigit(s[1])
                )
            ) {
                double x = stod(s);
                stack.push(x);
            } else if (s[0] == 'q') {
                break;
            } else {    
                printHelp();
            }
        } catch (underflow_error& e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}

void onAdd() {
    double y = stack.top();
    stack.pop();
    double x = stack.top();
    stack.pop();
    double res = x + y;
    stack.push(res);
    display();
}

void onSub() {
    double y = stack.top();
    stack.pop();
    double x = stack.top();
    stack.pop();
    double res = x - y;
    stack.push(res);
    display();
}

void onMul() {
    double y = stack.top();
    stack.pop();
    double x = stack.top();
    stack.pop();
    double res = x * y;
    stack.push(res);
    display();
}

void onDiv() {
    double y = stack.top();
    stack.pop();
    double x = stack.top();
    stack.pop();
    double res = x/y;
    stack.push(res);
    display();
}

void display() {
    cout << "= " << stack.top() << endl;
}

void onShow() {
    cout << "Stack depth = " << stack.size() << endl;
    if (stack.size() > 0) {
        cout << "Stack contents:" << endl;
        for (size_t i = 0; i < stack.size(); ++i) {
            cout << "    " << stack[i] << endl;
        }
    }
}

void onDup() {
    double x = stack.top();
    stack.push(x);
    // display();
}

void onExch() {
    double y = stack.top();
    stack.pop();
    double x = stack.top();
    stack.pop();
    stack.push(y);
    stack.push(x);
    // display();
}



void printHelp() {
    cout << 
    "StackCalc commands:\n"
    "\tnumber        push a number into the stack,\n"
    "\t+, -, *, /    arithmetic operations,\n"
    "\tpop           remove the stack top,\n"
    "\tclear         clear the stack,\n"
    "\t=             display the stack top,\n"
    "\tshow          show the stack contents,\n"
    "\tdup           duplicate the stack top,\n"
    "\texch          exchange (swap) two upper elements of stack,\n"
    "\tquit or q     quit.\n"
    "Commands should be separated by whitespaces." << endl;
}
