// visualization: https://www.youtube.com/watch?v=zhDmVF_NdjM

#include <iostream>
#include <vector>
#include <utility>

using std::cout;
using std::ostream;
using std::endl;
using std::vector;
using std::move;

template<typename T>
void countingsort(vector <T> &v);

template<typename T>
void find_min_and_max(vector <T> &v, T &min, T &max);

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
    countingsort(v);
    // print the sorted vector
    cout << "Sorted: \n";
    cout << v;

    return 0;
}

template<typename T>
void countingsort(vector <T> &v) {
    // create result vector
    vector<T> res(v.size());

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

        // calculate all the last indexes of the items
        for(int i = 1; i < count.size(); i++) {
            count[i] += count[i-1];
        }

        // loop through the frequency vector
        // set the items of vector v in correct order
        for (int i = v.size() - 1; i>=0; i--) {
            // get the index in count
            int index = v[i] - min;
            count[index]--;

            // get the new index in the result
            int newindex = count[index];
            res[newindex] = move(v[i]);
        }
    }

    // move the result vector to the given vector
    v = move(res);
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
            // equivalent of 
            // small = min(v[i-1], v[i]);
            // big = max(v[i-1], v[i]);
            if (v[i - 1] < v[i]) {
                small = v[i - 1];
                big = v[i];
            }
            else {
                small = v[i];
                big = v[i - 1];
            }
            
            // check the values with the smallest 
            // and largest element
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