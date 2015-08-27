#ifndef __BINBOOM_H
#define __BINBOOM_H

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::istream;
using std::ifstream;
using std::string;
using std::unique_ptr;
using std::move;
using std::vector;

template<class T>
class Binknoop;

template<class T>
using Binknoopptr=unique_ptr <Binknoop<T>>;

template<class T>
class BinaireBoom : protected Binknoopptr<T> {
public:
    // DON'T FORGET : using
    using Binknoopptr<T>::Binknoopptr;

    static int aantal_boom_constructor;
    static int aantal_boom_destructor;

private:
    void lees(const string &);  // leest bestand in en bouwt boom op

    void schrijf_inorder(ostream &os) const;

    void schrijf_preorder(ostream &os) const;

    void schrijf_postorder(ostream &os) const;

public:
    BinaireBoom<T>() { aantal_boom_constructor++; }

    BinaireBoom<T>(const string &);   // construeert boom aan de hand van gegevens in bestand
    BinaireBoom<T>(const BinaireBoom &);

    ~BinaireBoom<T>() {
        aantal_boom_destructor++;
        //...
    }

    // DON'T FORGET : move assignment operator
    BinaireBoom<T> &operator=(unique_ptr <Binknoop<T>> &&unique_pointer);

    void schrijf(ostream &os, const string &volgorde = "in") const {
        if (volgorde == "inorder" || volgorde == "in") schrijf_inorder(os);
        else if (volgorde == "preorder" || volgorde == "pre") schrijf_preorder(os);
        else schrijf_postorder(os);
    }

    friend ostream &operator<<(ostream &os, const BinaireBoom<T> &b) {
        b.schrijf(os, "inorder", true);
        return os;
    }

};

template<class T>
class Binknoop {

public:
    static int aantal_knoop_constructor_default;
    static int aantal_knoop_constructor_param;
    static int aantal_knoop_destructor;

    friend class BinaireBoom<T>;

    const T inhoud;
    BinaireBoom<T> links, rechts;

    Binknoop<T>() { aantal_knoop_constructor_default++; }

    Binknoop<T>(const T &geg) : inhoud(geg) { aantal_knoop_constructor_param++; }

    ~Binknoop<T>() { aantal_knoop_destructor++; }

};

//________________________________________________________________________________________________

template<class T>
int BinaireBoom<T>::aantal_boom_constructor = 0;
template<class T>
int BinaireBoom<T>::aantal_boom_destructor = 0;

//________________________________________________________________________________________________

template<class T>
int Binknoop<T>::aantal_knoop_constructor_default = 0;
template<class T>
int Binknoop<T>::aantal_knoop_constructor_param = 0;
template<class T>
int Binknoop<T>::aantal_knoop_destructor = 0;

// OWN IMPLEMENTATION ____________________________________________________________________________

// READ TREE //

// Reads the tree from a file
template<class T>
void BinaireBoom<T>::lees(const string &filename) {
    ifstream input(filename);

    if (input.fail()) {
        cout << "Failed to read: " << filename << endl;
    }
    else {
        int n;
        input >> n;

        // in the file: key value, line of left child, line of right child
        vector <T> keys(n);
        vector <int> left_children(n);
        vector <int> right_children(n);
        vector <int> frequency(n);

        // read each line one by one
        for (int i = 0; i < n; i++) {
            input >> keys[i] >> left_children[i] >> right_children[i];

            if (left_children[i]) {
                frequency[left_children[i] - 1]++;
            }
            if (right_children[i]) {
                frequency[right_children[i] - 1]++;
            }
        }
        // and close the input stream
        input.close();

        // the line which is not referenced by any other line
        // that is the line of the root node ( = j )
        // in the frequency vector, that line has the value 0
        int j = 0;
        while (frequency[j]) {
            j++;
        }

        // to work with unique pointers, we need 2 vectors
        // 1 vector of Binknoop pointers
        // 1 vector of the unique pointers to these Binknoop pointers
        vector < Binknoop<T> * > nodes;
        vector <unique_ptr<Binknoop<T> >> unique(n);

        // for each key, we create a node
        // and a unique pointer to the node
        for (int i = 0; i < n; i++) {
            nodes.push_back(new Binknoop<T>(keys[i]));
            unique[i] = unique_ptr<Binknoop<T> >(nodes[i]);
        }

        // create the tree
        for (int i = 0; i < n; i++) {
            // if there is a left child, move it to the left child of the node
            if (left_children[i]) {
                nodes[i]->links = move(unique[left_children[i] - 1]);
            }
            // if there is a right child, move it to the right child of the node
            if (right_children[i]) {
                nodes[i]->rechts = move(unique[(right_children[i] - 1)]);
            }
        }

        // at the end, we just need to move the root
        *this = move(unique[j]);
    }
}

template<class T>
BinaireBoom<T>::BinaireBoom(const string &filename) {
    lees(filename);
}

// copy operator
template<class T>
BinaireBoom<T>::BinaireBoom(const BinaireBoom<T> &tree) {
    // nothing here !!!
}

// move assignment operator
template<class T>
BinaireBoom<T> &BinaireBoom<T>::operator=(unique_ptr <Binknoop<T>> &&unique_pointer) {
    Binknoopptr<T>::operator=(move(unique_pointer));
    return *this;
}

// WRITE TREE //

// write the tree in prefix notation (preorder)
// output: key left right
template<class T>
void BinaireBoom<T>::schrijf_preorder(ostream &os) const {
    if (this->get()) {
        os << this->get()->inhoud << " ";
        this->get()->links.schrijf_preorder(os);
        this->get()->rechts.schrijf_preorder(os);
    }
}

// write the tree in infix notation (inorder)
// output: left key right
template<class T>
void BinaireBoom<T>::schrijf_inorder(ostream &os) const {
    if (this->get()) {
        this->get()->links.schrijf_inorder(os);
        os << this->get()->inhoud << " ";
        this->get()->rechts.schrijf_inorder(os);
    }
}

// write the tree in postfix notation (postorder)
// output: left right key
template<class T>
void BinaireBoom<T>::schrijf_postorder(ostream &os) const {
    if (this->get()) {
        this->get()->links.schrijf_postorder(os);
        this->get()->rechts.schrijf_postorder(os);
        os << this->get()->inhoud << " ";
    }
}


#endif