#include <iostream>
#include <vector>

using std::cout;
using std::ostream;
using std::endl;
using std::vector;

template<typename T>
void find_max(vector <T> &v, T &max);

template<typename T>
ostream &operator<<(ostream &os, vector <T> &v);

int main() {
    // create the vector of items
    vector <int> v = {1, 5, 3, 7, 2, 9};
    // print the unsorted vector
    cout << v;

    // declare maximum variable
    int max;
    // find the max value in the vector
    find_max(v, max);
    // print the value
    cout << "Maximum = " << max << endl;

    return 0;
}

// Finds the maximum value
// of all the elements in the vector
template<typename T>
void find_max(vector <T> &v, T &max) {
    if (v.size() > 0) {
        max = v[0];

        // check n-1 items
        for (int i = 1; i < v.size(); i++) {
            if(max < v[i]){
                max = v[i];
            }
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
