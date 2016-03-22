#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using std::cout;
using std::ostream;
using std::endl;
using std::vector;
using std::min;
using std::max;
using std::swap;
using std::move;

const int MAX_SUBVECTOR_LENGTH = 17;

template<typename T>
void quicksort(vector <T> &v, int l, int r);

template<typename T>
ostream &operator<<(ostream &os, vector <T> &v);

template<typename T>
void getpivots(vector <T> &v, int l, int r, T & pivotl, T & pivotr);

template<typename T>
void insertionsort(vector <T> &v, int l, int r);

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
    // if less than 17 elements, use insertion sort
    if(r - l < 17){
        insertionsort(v, l, r);
    }
    // else use jdk quicksort
    else {
        // get the pivots
        T pivotl, pivotr;
        getpivots(v, l, r, pivotl, pivotr);

        // sorting mechanism
        int k = l, m = l, g = r;
        while(m < g){
            if(v[m] < pivotl){
                swap(v[k], v[m]);
                k++;
                m++;
            }
            else if(v[m] > pivotr){
                swap(v[m], v[g]);
                g--;
            }
            else {
                m++;
            }
        }

        // call quicksort recursively on the parts
        quicksort(v, l, k);
        quicksort(v, k+1, g);
        quicksort(v, g+1, r);
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

// gets the 2 required pivots for quiksort JDK
template<typename T>
void getpivots(vector <T> &v, int l, int r, T & pivotl, T & pivotr) {
    // get the 5 elements with the formula
    vector<T> temp(5);
    for(int i=0; i<5; i++){
        int index = l + (i + 1 ) * ((int) ((r - l - 1) / 6));
        temp[i] = v[index];
    }

    // use insertion sort to get them in order
    insertionsort(temp, 0, temp.size()-1);

    // return the second and fourth element
    pivotl = move(temp[1]);
    pivotr = move(temp[3]);
}

// insertionsort used for little subtables
template<typename T>
void insertionsort(vector <T> &v, int l, int r) {
    for (int i = l+1; i <= r; i++) {
        T temp = move(v[i]);
        int j = i - 1;
        while (j >= l && temp < v[j]) {
            v[j + 1] = move(v[j]);
            j--;
        }
        v[j + 1] = move(temp);
    }
}
