#ifndef __ZOEKBOOM_H
#define __ZOEKBOOM_H

#include <iostream>   // voor test/debugfase
#include <fstream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include <iomanip>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::istream;
using std::string;
using std::unique_ptr;
using std::vector;
using std::sort;
using std::setw;
using std::move;
using std::swap;

template<class T>
class Knoop;

template<class T>
class Zoekboom : protected unique_ptr<Knoop<T> > {
    using unique_ptr<Knoop<T> >::unique_ptr;
public:
    Zoekboom();

    Zoekboom(const Zoekboom &) = delete;

    Zoekboom(Zoekboom &&);

    Zoekboom &operator=(const Zoekboom<T> &) = delete;

    Zoekboom &operator=(Zoekboom<T> &&);

    ~Zoekboom();

    bool voeg_toe(const T &sl);  // return false indien sl al aanwezig was in de boom

    // own implementation
    Zoekboom(vector <T> &v);

    void print_tree(int width = 0);

    int max_depth() const;

    double avg_depth() const;

    void delete_key(const T &sl);

protected:
    Zoekboom *plaats_van_sleutel(
            const T &sl);      // geen const-pointer, anders kan je op die plaats niets toevoegen...
    void voeg_wortel_toe(const T &sl);

    void schrijf(ostream &out) const;  // zal inorder uitschrijven;
    // enkel sleutels (zelfs zonder linker/rechterkind -
    // best aan te passen als je structuur wil controleren!)
    // hier nog zonder iterator geimplementeerd

    friend ostream &operator<<(ostream &out, const Zoekboom<T> &b) {
        b.schrijf(out);
        out << " X";
        return out;
    }

private:
    // own implementation
    void vector_to_binary_search_tree(vector <T> &v, int l, int r);

    void create_depth_vector(vector <int> &v, int depth = 0) const;
};

//________________________________________________________________

template<class T>
class Knoop {

    friend class Zoekboom<T>;

public:
    Knoop(const T &sl_) : sl(sl_) { };

private:
    const T sl;
    Zoekboom<T> links, rechts;

};

//////////////////////////////////////////////////////////////////
/////////   GEGEVEN IMPLEMENTATIE                    /////////////

template<class T>
Zoekboom<T>::Zoekboom() {
    //cout<<" --defaultconstructor-- ";
}
// moet niets speciaals in

template<class T>
Zoekboom<T>::Zoekboom(Zoekboom &&ander) : unique_ptr<Knoop<T> >(move(ander)) {
    //cout<<" --moveconstructor-- ";
}


template<class T>
Zoekboom<T> &Zoekboom<T>::operator=(Zoekboom<T> &&ander) {
    unique_ptr<Knoop<T> >::operator=(move(ander));
    return *this;
}

template<class T>
Zoekboom<T>::~Zoekboom() {
}
// moet niets speciaals in

template<class T>
bool Zoekboom<T>::voeg_toe(const T &sl) {
    Zoekboom *hier = plaats_van_sleutel(sl);
    if (*hier == nullptr) {
        hier->voeg_wortel_toe(sl);
        return true;
    }
    return false;
}

// wordt alleen opgeroepen als *this == nullptr
template<class T>
void Zoekboom<T>::voeg_wortel_toe(const T &sl) {
    *this = unique_ptr<Knoop<T> >(new Knoop<T>(sl));
}


template<class T>
Zoekboom<T> *Zoekboom<T>::plaats_van_sleutel(const T &sl) {
    if (*this == nullptr) {
        return this;
    }
    if (this->get()->sl == sl) {
        return this;
    }
    if (this->get()->sl < sl) {
        return this->get()->rechts.plaats_van_sleutel(sl);
    }
    else {
        return this->get()->links.plaats_van_sleutel(sl);
    }
}

template<class T>
void Zoekboom<T>::schrijf(ostream &out) const {
    if (*this != nullptr) {
        this->get()->links.schrijf(out);
        out << this->get()->sl << " ";
        this->get()->rechts.schrijf(out);
    }
}

//////////////////////////////////////////////////////////////////
/////////   OWN IMPLEMENTATION                       /////////////

// CREATE BINARY SEARCH TREE FROM VECTOR

template<class T>
Zoekboom<T>::Zoekboom(vector <T> &v) {
    // first sort the vector
    sort(v.begin(), v.end());
    vector_to_binary_search_tree(v, 0, v.size() - 1);
}

template<class T>
void Zoekboom<T>::vector_to_binary_search_tree(vector <T> &v, int l, int r) {
    if (l <= r) {
        int m = l + (r - l) / 2;
        voeg_toe(v[m]);
        vector_to_binary_search_tree(v, l, m - 1);
        vector_to_binary_search_tree(v, m + 1, r);
    }
}

// PRINT THE BINARY SEARCH TREE IN TREE FORM

template<class T>
void Zoekboom<T>::print_tree(int width) {
    if (this->get()) {
        this->get()->links.print_tree(width + 4);
        cout << setw(width) << this->get()->sl << endl;
        this->get()->rechts.print_tree(width + 4);
    }
}

// GET THE MAXIMUM DEPTH OF THE BINARY SEARCH TREE //

template<class T>
int Zoekboom<T>::max_depth() const {
    if (this->get()) {
        int left_depth = this->get()->links.max_depth();
        int right_depth = this->get()->rechts.max_depth();

        return (left_depth > right_depth) ? left_depth + 1 : right_depth + 1;
    }
    else {
        return -1;
    }
}

// GET THE AVERAGE DEPTH OF THE BINARY SEARCH TREE

template<class T>
double Zoekboom<T>::avg_depth() const {
    vector <int> depths;
    create_depth_vector(depths);

    double sum = 0;
    for(int i=0; i<depths.size(); i++){
        sum += depths[i];
    }

    // return the average, depths.size() gives the amount of nodes
    return sum / depths.size();
}

// Saves the depth of every node in a vector
template<class T>
void Zoekboom<T>::create_depth_vector(vector <int> &v, int depth) const {
    if(this->get()) {
        v.push_back(depth);
        this->get()->links.create_depth_vector(v, depth + 1);
        this->get()->rechts.create_depth_vector(v, depth + 1);
    }
}

// Deletes the node with the specified key
template <class T>
void Zoekboom<T>::delete_key(const T& sl) {
    Zoekboom<T>* here = plaats_van_sleutel(sl);
    if(here->get()){
        if(here->get()->links.get() && here->get()->rechts.get()){
            // if two children detected: find pointer to successor
            Zoekboom<T>* successor_parent = here;
            Zoekboom<T>* successor = &here->get()->rechts;
            while(successor->get()->links){
                successor_parent = successor;
                successor = &successor->get()->links;
            }

            // move the successor pointer to a successor node
            Zoekboom<T> suc = move(*successor);

            // if the successor has a right child, 
            // move it into the successor's place
            if(suc.get()->rechts){
                successor_parent->get()->links = move(suc.get()->rechts);
            }

            // move the children of the current node to the successor node
            // move the successor node into the current node 
            suc.get()->links = move(here->get()->links);
            suc.get()->rechts = move(here->get()->rechts);
            (*here) = move(suc);
        }
        else if(here->get()->links.get()){
            // moving the left child into the current node
            (*here) = move(here->get()->links); 
        }
        else if(here->get()->rechts.get()){
            // moving the right child into the current node
            (*here) = move(here->get()->rechts);   
        }
        else {
            // since no children, we can reset the current node
            here->reset();
        }
    }
}
/*
template<class T>
bool Zoekboom<T>::voeg_toe(const T &sl) {
    Zoekboom *hier = plaats_van_sleutel(sl);
    if (*hier == nullptr) {
        hier->voeg_wortel_toe(sl);
        return true;
    }
    return false;
}
*/

#endif