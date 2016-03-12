#include <iostream>
#include <vector>
#include <utility>

using std::cout;
using std::ostream;
using std::endl;
using std::vector;
using std::swap;
using std::move;

template<typename T>
void create_heap(vector <T> &v);

template<typename T>
void heapify(vector <T> &v, int i);

template<typename T>
void delete_root(vector <T> &v);

template<typename T>
ostream &operator<<(ostream &os, vector <T> &v);

int main() {
    // create the vector of items
    vector <int> v = {1, 5, 3, 7, 2, 9, 8, 4};
    // print the unsorted vector
    cout << "Original vector \n";
    cout << v;
    // sort the vector
    create_heap(v);
    // print the heap vector
    cout << "Heap vector \n";
    cout << v;
    // delete the root
    delete_root(v);
    // print the new heap vector
    cout << "New heap vector \n";
    cout << v;

    return 0;
}

// Creates a max heap
template<typename T>
void create_heap(vector <T> &v) {
    for (int i = (v.size() - 1) / 2; i >= 0; i--) {
        heapify(v, i);
    }
}

template<typename T>
void heapify(vector <T> &v, int i) {
    int index_left = i * 2 + 1;
    int index_right = i * 2 + 2;

    int greatest = i;
    if (index_left < v.size() && v[index_left] > v[greatest]) {
        greatest = index_left;
    }
    if (index_right < v.size() && v[index_right] > v[greatest]) {
        greatest = index_right;
    }

    if (greatest != i) {
        swap(v[i], v[greatest]);
        heapify(v, greatest);
    }
}

template<typename T>
void delete_root(vector <T> &v){
    // swap the root with the last element
    swap(v[0], v[v.size() - 1]);

    // remove the last element
    v.resize(v.size() - 1);

    // reconstruct heap
    heapify(v, 0);
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

