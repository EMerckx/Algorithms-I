#include <iostream>
#include <vector>

using std::cout;
using std::ostream;
using std::endl;
using std::vector;

template<typename T>
void find_min_and_max(vector <T> &v, T &min, T &max);

template<typename T>
ostream &operator<<(ostream &os, vector <T> &v);

int main() {
    // create the vector of items
    vector <int> v = {1, 5, 3, 7, 2, 9};
    // print the unsorted vector
    cout << v;

    // init minimum and maximum variables
    int min = 9999, max = 0;
    // find the min and max values in the vector
    find_min_and_max(v, min, max);
    // print the values
    cout << "Minimum = " << min << endl;
    cout << "Maximum = " << max << endl;

    return 0;
}

// Finds the minimum value and the maximum value
// of all the elements in the vector
template<typename T>
void find_min_and_max(vector <T> &v, T &min, T &max) {
    T small, big;
    // check every pair of items
    for (int i = 1; i < v.size(); i += 2) {
        if (v[i - 1] < v[i]) {
            small = v[i - 1];
            big = v[i];
        }
        else {
            small = v[i];
            big = v[i - 1];
        }
        if (small < min) {
            min = small;
        }
        if (max < big) {
            max = big;
        }
    }
    // if there are uneven items
    // then 1 element is missed by the pairs
    if (v.size() % 2 == 1) {
        int i = v.size()-1;
        if (v[i] < min) {
            min = v[i];
        }
        else if (max < v[i]) {
            max = v[i];
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
