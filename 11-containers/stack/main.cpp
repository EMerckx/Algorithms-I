#include "stack.h"
#include <iostream>

using std::cout;
using std::endl;

int main(){

    Stack<int> s;
    vector<int> v = { 5, 2, 9, 4, 1, 6 };

    // print the given vector
    cout << "Given vector:" << endl;
    for (int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl << endl;

    // add every element of the vector to the stack
    for (int i=0; i<v.size(); i++){
        s.push(v[i]);
    }

    // print the stack
    cout << "Stack:" << endl;
    cout << s << endl << endl;

    // do some operations
    cout << "empty: " << s.empty() << endl;
    cout << "top  : " << s.top() << endl;
    cout << "pop()" << endl;
    s.pop();
    cout << "top  : " << s.top() << endl << endl;

    // print the stack
    cout << "Stack:" << endl;
    cout << s << endl;

    return 0;
}