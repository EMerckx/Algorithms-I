#ifndef STACK_H
#define STACK_H

#include <vector>
#include <fstream>

using std::vector;
using std::ostream;

/*
 * friend ostream &operator<<(ostream &os, const BinaireBoom<T> &b) {
        b.schrijf(os, "inorder", true);
        return os;
    }
 */

template<class T>
class Stack : protected vector<T> {

private:
    int pointer;

public:
    Stack();

    void push(const T &value);

    T top() const;

    void pop();

    bool empty() const;

    ostream& write(ostream & os) const;

    template<class U>
    friend ostream &operator<<(ostream &os, const Stack<U> &s);
};

template<class T>
Stack<T>::Stack() {
    pointer = 0;
}

template<class T>
void Stack<T>::push(const T &value) {
    if (pointer >= this->size()) {
        this->push_back(value);
    }
    else {
        this->operator[](pointer) = value;
    }
    pointer++;
}

template<class T>
T Stack<T>::top() const {
    return this->operator[](pointer - 1);
}

template<class T>
void Stack<T>::pop() {
    pointer--;
}

template<class T>
bool Stack<T>::empty() const {
    return (pointer == 0);
}

template <class T>
ostream& Stack<T>::write(ostream &os) const {
    for (int i = 0; i < pointer; i++) {
        os << this->operator[](i) << " ";
    }
    return os;
}

template<class T>
ostream &operator<<(ostream &os, const Stack<T> &s) {
    return s.write(os);
}


#endif //STACK_H
