#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::ostream;
using std::endl;
using std::vector;
using std::srand;
using std::rand;

template<typename T>
void quicksort(vector <T> &v, int l, int r);

template<typename T>
ostream &operator<<(ostream &os, vector <T> &v);

template<typename T>
void swap(T &a, T &b);

template<typename T>
T getrandompivot(vector <T> &v, int l, int r);

int main() {
    // initialize the random seed
    srand(time(NULL));

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
        // Partition with the median of 3 as pivot
        T pivot = getrandompivot(v, l, r);
        int i = l, j = r;

        while (v[j] > pivot) {
            j--;
        }
        while (v[i] < pivot) {
            i++;
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

template<typename T>
T getrandompivot(vector <T> &v, int l, int r) {
    int length = r - l;

    int pivot_index = l + rand() % (length + 1);

    return v[pivot_index];
}