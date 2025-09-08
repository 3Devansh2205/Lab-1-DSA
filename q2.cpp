#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;


    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Elements pushed: 10, 20, 30\n";


    if (!s.empty()) {
        cout << "Top element: " << s.top() << endl;
    }


    s.pop();
    cout << "One element popped\n";


    if (!s.empty()) {
        cout << "New top element: " << s.top() << endl;
    }


    cout << "Current stack size: " << s.size() << endl;


    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}
