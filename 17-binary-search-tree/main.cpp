#include "zoekboom.h"

template<typename T>
ostream &operator<<(ostream &os, vector <T> &v);

int main(){

    //vector<int> v = {1, 5, 3, 7, 2, 9, 2, 4};
    vector<int> v = {8, 3, 3, 1, 2, 4, 5, 4, 6, 7, 6, 10, 9, 1, 7, 
        6, 11, 8, 8, 7, 7, 10, 10, 12, 2, 2, 2, 2, 3, 1, 1, 2, 1, 2, 5};
    cout << v;

    Zoekboom<int> z(v);
    cout << z << endl << endl;

    z.print_tree();
    cout << endl;

    cout << "Maximum depth: " << z.max_depth() << endl;
    cout << "Average depth: " << z.avg_depth() << endl;

    cout << endl << "--------------------" << endl << endl;

    z.print_tree();
    cout << endl;

    int key_to_delete = 5;
    cout << "Deleting the key: " << key_to_delete << endl << endl;
    z.delete_key(key_to_delete);

    z.print_tree();
    cout << endl;

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