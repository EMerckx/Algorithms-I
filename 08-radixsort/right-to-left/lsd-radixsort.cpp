#include <iostream>
#include <vector>

using std::cout;
using std::ostream;
using std::endl;
using std::vector;

template<typename T>
void lsd_radixsort(vector <T> &v);

template<typename T>
void find_max(vector <T> &v, T &max);

template<typename T>
ostream &operator<<(ostream &os, vector <T> &v);

int main() {
    // create the vector of items
    vector <int> v = {170, 45, 75, 90, 802, 2, 24, 66};
    // print the unsorted vector
    cout << v;
    // sort the vector
    lsd_radixsort(v);
    // print the sorted vector
    cout << v;

    return 0;
}

template<typename T>
void lsd_radixsort(vector <T> &v) {
    if (v.size() > 1) {
        T max;
        find_max(v, max);

        int amount_buckets = 10;
        vector <vector<T>> buckets(amount_buckets);
        for (int i = 1; i <= max; i *= amount_buckets) {
            // fill the buckets
            for (int j = 0; j < v.size(); j++) {
                buckets[(int) (v[j] / i) % amount_buckets].push_back(v[j]);
            }

            // empty the buckets
            int index = 0;
            for (int j = 0; j < amount_buckets; j++) {
                for (int k = 0; k < buckets[j].size(); k++) {
                    v[index++] = buckets[j][k];
                }

                // don't forget to clear the buckets !!!
                buckets[j].clear();
            }
        }
    }
}

// Finds the maximum value
// of all the elements in the vector
template<typename T>
void find_max(vector <T> &v, T &max) {
    if (v.size() > 0) {
        max = v[0];

        // check n-1 items
        for (int i = 1; i < v.size(); i++) {
            if (max < v[i]) {
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