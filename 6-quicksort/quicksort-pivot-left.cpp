#include <iostream>
#include <vector>

using std::cout;
using std::ostream;
using std::endl;
using std::vector;

template<typename T>
void quicksort(vector <T> &v, int l, int r);

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
    quicksort(v, 0, v.size() - 1);
    // print the sorted vector
    cout << v;

    return 0;
}

// Sorts the subvector v[l..r]
// l = left index
// r = right index
template<typename T>
void quicksort(vector <T> &v, int l, int r) {
    if (l < r) {
        // Partition with v[l] as pivot
        T pivot = v[l];
        int i = l, j = r;

        while (v[j] > pivot) {
            j--;
        }
        while (i < j) {
            swap(v[i], v[j]);
            i++;
            j--;

            while (v[i] < pivot) {
                i++;
            }
            while (v[j] > pivot) {
                j--;
            }
        }

        // sort both subvectors recursively
        quicksort(v, l, j);
        quicksort(v, j + 1, r);
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