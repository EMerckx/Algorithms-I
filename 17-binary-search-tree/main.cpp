#include "zoekboom.h"

template<typename T>
ostream &operator<<(ostream &os, vector <T> &v);

int main(){

    vector<int> v = {1, 5, 3, 7, 2, 9, 2, 4};
    cout << v;

    Zoekboom<int> z(v);
    cout << z << endl << endl;

    z.print_tree();
    cout << endl;

    cout << "Maximum depth: " << z.max_depth() << endl;
    cout << "Average depth: " << z.avg_depth() << endl;

    return 0;
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