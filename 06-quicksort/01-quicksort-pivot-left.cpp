#include <iostream>
#include <vector>
#include <utility>

using std::cout;
using std::ostream;
using std::endl;
using std::vector;
using std::swap;

template<typename T>
void quicksort(vector <T> &v, int l, int r);

template<typename T>
ostream &operator<<(ostream &os, vector <T> &v);

int main() {
    // create the vector of items
    vector <int> v = {
        12,63,56,55,27,22,15,9,2,91,80,98,40,29,36,92,99,46,81,43,11,60,6,68,18,44,90,
        17,93,59,74,26,78,7,8,24,71,73,37,48,82,49,67,4,62,20,25,84,1,87,30,31,39,86,
        61,76,100,47,10,51,23,58,45,5,41,34,85,77,57,95,52,66,75,19,28,42,96,79,88,70,
        16,50,69,53,89,94,65,33,3,64,32,21,72,97,54,14,83,38,13,35
    };
    // print the unsorted vector
    cout << "Unsorted: \n";
    cout << v;
    cout << "\n";
    // sort the vector
    quicksort(v, 0, v.size() - 1);
    // print the sorted vector
    cout << "Sorted: \n";
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
