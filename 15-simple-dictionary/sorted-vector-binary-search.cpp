#include <iostream>
#include <vector>

using std::cout;
using std::ostream;
using std::endl;
using std::vector;

template<typename T>
int binary_search(vector <T> &v, T &key);

template<typename T>
ostream &operator<<(ostream &os, vector <T> &v);

int main() {
    // create the vector of items
    vector <int> v = {1, 2, 3, 5, 7, 9};
    // print the unsorted vector
    cout << v;
    // search the vector
    int key_to_find = 7;
    int found_index = binary_search(v, key_to_find);
    // print the sorted vector
    cout << endl << "The key " << key_to_find << " was found on index " << found_index << endl;
    cout << "in the following vector: " << v;

    return 0;
}

// Searches the sorted vector for the given key
// If found : the index of the key is returned
// If not : -1 is returned
template<typename T>
int binary_search(vector <T> &v, T &key) {
    int l = 0;
    int r = v.size() - 1;

    while (l < r) {
        int m = l + (r - l) / 2;
        if (key <= v[m]) {
            r = m;
        }
        else {
            l = m + 1;
        }
    }

    return key == v[l] ? l : -1;
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