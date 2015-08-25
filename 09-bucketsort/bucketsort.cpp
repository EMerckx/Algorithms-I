#include <iostream>
#include <vector>

using std::cout;
using std::ostream;
using std::endl;
using std::vector;

template<typename T>
void insertionsort(vector <T> &v);

template<typename T>
void bucketsort(vector <T> &v, int amount_buckets);

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
    bucketsort(v, 10);
    // print the sorted vector
    cout << v;

    return 0;
}

template<typename T>
void bucketsort(vector <T> &v, int amount_buckets) {
    if (v.size() > 1) {
        T max;
        find_max(v, max);

        int partition_size = (int) (max / amount_buckets) + 1;
        vector <vector<T>> buckets(amount_buckets);

        for (int i = 0; i < v.size(); i++) {
            buckets[(int) (v[i] / partition_size) % amount_buckets].push_back(v[i]);
        }

        for (int i = 0; i < buckets.size(); i++) {
            insertionsort(buckets[i]);
        }

        int index = 0;
        for (int i = 0; i < buckets.size(); i++) {
            for (int j = 0; j < buckets[i].size(); j++) {
                v[index++] = buckets[i][j];
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

template<typename T>
void insertionsort(vector <T> &v) {
    for (int i = 1; i < v.size(); i++) {
        T temp = v[i];
        int j = i - 1;
        while (j >= 0 && temp < v[j]) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = temp;
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