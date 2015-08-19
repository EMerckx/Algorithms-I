#include <iostream>
#include <vector>

using std::cout;
using std::ostream;
using std::endl;
using std::vector;

template<typename T>
void selectionsort(vector <T> &v);

template<typename T>
ostream &operator<<(ostream &os, vector <T> &v);

template<typename T>
void swap(T &a, T &b);

int main() {
    // create the vector of items
    vector <int> v = {1, 5, 3, 7, 2, 9};
    // print the unsorted vector
    cout << v;
    // sort the vector
    selectionsort(v);
    // print the sorted vector
    cout << v;

    return 0;
}

// Sorting by selection
template<typename T>
void selectionsort(vector <T> &v) {
    for (int i = v.size() - 1; i > 0; i--) {
        // find the index of the max element
        int imax = i;
        for (int j = 0; j < i; j++) {
            if (v[j] > v[imax]) {
                imax = j;
            }
        }
        swap(v[i], v[imax]);
    }
}

// Shows the operator << how to print the vector
template<typename T>
ostream &operator<<(ostream &os, vector <T> &v) {
    for (int i = 0; i < v.size(); i++) {
        os << v[i] << " ";
    }
    os << endl;
    return os;
}

// Swaps the value of a with the value of b
template<typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}