#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::sqrt;

template<typename T>
int get_index_of_hashfunction_by_division(const T &key);

template<typename T>
int get_index_of_hashfunction_by_multiplication(const T &key);

template<typename T>
int get_index_of_hashfunction_by_universal_hashing(const T &key);

int main() {

    double key = 2354.12;
    cout << "key: " << key << endl << endl;

    int index;

    // hashfunction by division
    cout << "Hashfunction by division" << endl;
    index = get_index_of_hashfunction_by_division(key);
    cout << "Calculated index: " << index << endl << endl;

    // hashfunction by multiplication
    cout << "Hashfunction by multiplication" << endl;
    index = get_index_of_hashfunction_by_multiplication(key);
    cout << "Calculated index: " << index << endl << endl;

    // hashfunction by universal hashing
    cout << "Hashfunction by universal hashing" << endl;
    index = get_index_of_hashfunction_by_universal_hashing(key);
    cout << "Calculated index: " << index << endl;

    return 0;
}

// gets the index for the key
// uses a hashfunction by division
// formula: h(s) = s modulo m
template<typename T>
int get_index_of_hashfunction_by_division(const T &key) {
    // best choice of m is a prime number
    int m = 97;
    int index = ((int) key) % m;

    return index;
}

// gets the index for the key
// uses a hashfunction by multiplication
// formula: h(s) = floor( m * ( s * c - floor( s * c ) ) )
template<typename T>
int get_index_of_hashfunction_by_multiplication(const T &key) {
    // best choice of m is a power of 2
    // but the value of m is not critical
    int m = 97;
    // best choice of c is the golden ratio
    double c = (sqrt(5) - 1) / 2.0;

    int index = (int) (m * (key * c - (int) (key * c)));

    return index;
}

// gets the index for the key
// uses a hashfunction by universal hashing
// ~= a family of hashfunctions
// formula: h(s) = ( ( a * s + b ) mod p ) mod m
template<typename T>
int get_index_of_hashfunction_by_universal_hashing(const T &key) {
    // best choice of m is a prime number
    int m = 97;

    // best choice of p is a prime number
    // and is prime with m
    int p = 839;
    // the number a is a number between 1 and p-1
    // normally random generated
    int a = 138;
    // the number a is a number between 0 and p-1
    // normally random generated
    int b = 724;

    int index = ((a * (int) key + b) % p) % m;

    return index;
}

