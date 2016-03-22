// still a bug in the code

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
void quicksort(vector <T> &v, int l, int r, int bin);

template<typename T>
ostream &operator<<(ostream &os, vector <T> &v);

int main() {
    // create the vector of items
    /*vector <int> v = {
        12,63,56,55,27,22,15,9,2,91,80,98,40,29,36,92,99,46,81,43,11,60,6,68,18,44,90,
        17,93,59,74,26,78,7,8,24,71,73,37,48,82,49,67,4,62,20,25,84,1,87,30,31,39,86,
        61,76,100,47,10,51,23,58,45,5,41,34,85,77,57,95,52,66,75,19,28,42,96,79,88,70,
        16,50,69,53,89,94,65,33,3,64,32,21,72,97,54,14,83,38,13,35
    };*/
    vector <int> v = {170, 45, 75, 90, 802, 2, 24, 66, 44, 12};
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
    int imax = 0;
    for(int i=1; i<v.size(); i++){
        if(v[imax] < v[i]){
            imax = i;
        }
    }

    int bin = 1;
    while (bin < v[imax]){
        bin = bin << 1;
    }
    bin = bin >> 1;

    quicksort(v, l, r, bin);
}

// Sorts the subvector v[l..r]
// l = left index
// r = right index
// bit = binary pattern
template<typename T>
void quicksort(vector <T> &v, int l, int r, int bin) {
    if (l < r && bin) {

        int i = l, j = r;

        while (!(v[i] & bin)) {
            i++;
        }
        while (v[j] & bin) {
            j--;
        }
        while (i < j) {
            cout << "bin " << bin << "\n";
            cout << v;
            swap(v[i], v[j]);
            i++;
            j--;

            while (!(v[i] & bin)) {
                i++;
            }
            while (v[j] & bin) {
                j--;
            }
        }

        bin = bin >> 1;

        // sort both subvectors recursively
        quicksort(v, l, j, bin);
        quicksort(v, j + 1, r, bin);
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
