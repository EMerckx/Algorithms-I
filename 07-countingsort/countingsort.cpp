#include <iostream>
#include <vector>

using std::cout;
using std::ostream;
using std::endl;
using std::vector;

template<typename T>
void countingsort(vector <T> &v);

template<typename T>
void find_min_and_max(vector <T> &v, T &min, T &max);

template<typename T>
ostream &operator<<(ostream &os, vector <T> &v);

int main() {
    // create the vector of items
    vector <int> v = {1, 5, 3, 7, 2, 9};
    // print the unsorted vector
    cout << v;
    // sort the vector
    countingsort(v);
    // print the sorted vector
    cout << v;

    return 0;
}

template<typename T>
void countingsort(vector <T> &v) {
    if (v.size() > 1) {
        T min, max;
        find_min_and_max(v, min, max);

        // the length of the frequency vector
        int length = (int) (max - min) + 1;
        // init the counting vector
        vector <int> count(length, 0);
        for (int i = 0; i < v.size(); i++) {
            count[v[i] - min]++;
        }

        // loop through the frequency vector
        // set the items of vector v in correct order
        int j = 0;
        for (int i = 0; i<count.size(); i++) {
            while (count[i] > 0) {
                v[j++] = i + min;
                count[i]--;
            }
        }
    }
}

// Finds the minimum value and the maximum value
// of all the elements in the vector
template<typename T>
void find_min_and_max(vector <T> &v, T &min, T &max) {
    if (v.size() > 0) {
        min = v[0];
        max = v[0];

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
            int i = v.size() - 1;
            if (v[i] < min) {
                min = v[i];
            }
            else if (max < v[i]) {
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