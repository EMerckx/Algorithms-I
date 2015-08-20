#include <iostream>
#include <vector>

using std::cout;
using std::ostream;
using std::endl;
using std::vector;

template<typename T>
void mergesort(vector <T> &v);

template<typename T>
void mergesort(vector <T> &v, int l, int r, vector <T> &temp);

template<typename T>
void merge(vector <T> &v, int l, int m, int r, vector <T> &temp);

template<typename T>
ostream &operator<<(ostream &os, vector <T> &v);

int main() {
    // create the vector of items
    vector <int> v = {1, 5, 3, 7, 2, 9};
    // print the unsorted vector
    cout << v;
    // sort the vector
    mergesort(v);
    // print the sorted vector
    cout << v;

    return 0;
}

// Sorts the vector v recursively
// Uses a temporary vector of half the size
template<typename T>
void mergesort(vector <T> &v) {
    vector <T> temp(v.size() / 2);
    mergesort(v, 0, v.size() - 1, temp);
}

// Sorts the subvector v[l..r] by merging
// Uses a temporary vector
// Uses recursion
template<typename T>
void mergesort(vector <T> &v, int l, int r, vector <T> &temp) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergesort(v, l, m, temp);
        mergesort(v, m + 1, r, temp);

        merge(v, l, m, r, temp);
    }
}

template<typename T>
void merge(vector <T> &v, int l, int m, int r, vector <T> &temp) {
    // Copy the values to the temp vector
    for (int i = l; i <= m; i++) {
        temp[i - l] = v[i];
    }

    int i = l;
    int li = 0;
    int ri = m + 1;

    while (li + l <= m && ri <= r) {
        if (temp[li] < v[ri]) {
            v[i++] = temp[li++];
        }
        else {
            v[i++] = v[ri++];
        }
    }

    while (li + l <= m) {
        v[i++] = temp[li++];
    }
    while (ri <= r) {
        v[i++] = v[ri++];
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

