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
void add_to_heap(vector <T> &v, T& element);

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
    // create and add a new element
    int new_element = 10;
    add_to_heap(v, new_element);
    // print the new heap vector
    cout << "New heap vector \n";
    cout << v;

    return 0;
}

// Creates a max heap
template<typename T>
void create_heap(vector <T> &v) {
    for (int i = (v.size() - 2) / 2; i >= 0; i--) {
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

// Adds a new element to the heap
template<typename T>
void add_to_heap(vector <T> &v, T& element){
    // get the index for the new element
    int index = v.size();

    // extend the vector
    v.resize(v.size() + 1);

    // calculate the index of the parent
    int parent_index = (index - 1) / 2;

    // if the element is greater than its parent, 
    // move parent down
    while(index > 0 && element > v[parent_index]){
        // move the parent value to the current index
        v[index] = move(v[parent_index]);

        // recalculate indexes
        index = parent_index;
        parent_index = (index - 1) / 2;
    }

    // insert the element on the correct index
    v[index] = move(element);
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

