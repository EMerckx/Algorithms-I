#include <iostream>
#include <vector>

using std::cout;
using std::ostream;
using std::endl;
using std::vector;

template<typename T>
void create_heap(vector <T> &v);

template<typename T>
void heapify(vector <T> &v, int index, int size);

template<typename T>
void heapsort(vector <T> &v);

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
    heapsort(v);
    // print the sorted vector
    cout << v;

    return 0;
}

// Creates a max heap
template<typename T>
void create_heap(vector <T> &v) {
    for (int i = (v.size() - 1) / 2; i >= 0; i--) {
        heapify(v, i, v.size());
    }
}

template<typename T>
void heapify(vector <T> &v, int index, int size) {
    int index_left = index * 2 + 1;
    int index_right = index * 2 + 2;

    int greatest = index;
    if (index_left < size && v[index_left] > v[greatest]) {
        greatest = index_left;
    }
    if (index_right < size && v[index_right] > v[greatest]) {
        greatest = index_right;
    }

    if (greatest != index) {
        swap(v[index], v[greatest]);
        heapify(v, greatest, size);
    }
}

template<typename T>
void heapsort(vector <T> &v) {
    if (v.size() > 1) {
        create_heap(v);

        for (int i = v.size() - 1; i > 0; i--) {
            swap(v[0], v[i]);
            heapify(v, 0, i);
        }
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

