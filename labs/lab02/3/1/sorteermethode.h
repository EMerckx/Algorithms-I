#ifndef __SORTEERMETHODE
#define __SORTEERMETHODE
#include "sortvector.h"
#include "chrono.h"
#include <iostream>
    using std::move;
    using std::swap;
    using std::endl;
    using std::cout;
#include <algorithm>   // voor sort()-methode uit STL

/** class Sorteermethode
    \brief abstracte klasse van methodes die een vector sorteren
*/
template <typename T>
class Sorteermethode{
    public:
/// \fn operator() sorteert de vector gegeven door het argument
        virtual void operator()(vector<T> & v) const = 0;

/// \fn vulrange Deze externe procedure schrijft naar os een overzicht (met de nodige ornamenten)
/// met de snelheid van de opgegeven sorteermethode *this. Er wordt 1 lijn uitgedrukt voor elke mogelijke
/// grootte. Deze groottes zijn kleinste, 10*kleinste, 100*kleinste,
/// enzovoorts, tot aan grootste.
/// Op een lijn staat de snelheid van de methode toegepast op
/// (1) een random tabel
/// (2) een al gesorteerde tabel.
/// (3) een omgekeerd gesorteerde tabel.

/// Deze functie werkt alleen als T een toekenning van een int toelaat,
/// zodat bv.
///    T a=5;
/// geldig is.
        void meet(int kortste, int langste, ostream& os);

};

template <typename T>
void Sorteermethode<T>::meet(int kortste, int langste, ostream& os){
    int out_length = 15;
    int test_no = 0;

    os << setw(out_length + 3) << "lengte" << setw(out_length + 2) << "omgekeerd" 
        << setw(out_length + 2) << "gesorteerd" << setw(out_length + 2) 
        << "random" << endl;

    while(kortste <= langste){
        test_no++;

        // create the sortvector
        Sortvector<T> sv(kortste);
        os << " " << test_no << "." << setw(out_length) << kortste;
        flush(os);

        Chrono tijd_gewoon;
        Chrono tijd_omgekeerd;
        Chrono tijd_random;

        // reversed
        sv.vul_omgekeerd();
        tijd_omgekeerd.start();
        this->operator()(sv);
        tijd_omgekeerd.stop();
        os << setw(out_length);
        if(sv.is_gesorteerd()){
          os << tijd_omgekeerd.tijd() << " s";
        }
        else{
          os << "not sorted";
        }
        flush(os);

        // sorted
        tijd_gewoon.start();
        this->operator()(sv);
        tijd_gewoon.stop();
        os << setw(out_length);
        if(sv.is_gesorteerd()){
          os << tijd_gewoon.tijd() << " s";
        }
        else{
          os << "not sorted";
        }
        flush(os);

        // random
        sv.shuffle();
        tijd_random.start();
        this->operator()(sv);
        tijd_random.stop();
        os << setw(out_length);
        if(sv.is_gesorteerd()){
          os << tijd_random.tijd() << " s";
        }
        else{
          os << "not sorted";
        }
        flush(os);

        os << "\n";
        
        kortste *= 10;
    }
}

/** 
    \class STLSort
    \brief STANDARD TEMPLATE LIBRARY SORT
*/
template <typename T>
class STLSort : public Sorteermethode<T>{
    public:
        void operator()(vector<T> & v) const;
};

template <typename T>
void STLSort<T>::operator()(vector<T> & v) const{
    sort(v.begin(),v.end());
}

/** 
    \class InsertionSort
*/
template <typename T>
class InsertionSort : public Sorteermethode<T>{
    public:
        void operator()(vector<T> & v) const;   
};

template <typename T>
void InsertionSort<T>::operator()(vector<T> & v) const{
    for(int i=1; i<v.size(); i++){
        T h;
        h=move(v[i]);
        int j=i-1;
        while(j>=0 && h<v[j]){
            v[j+1] = move(v[j]);
            j--;
        }
        v[j+1] = move(h);
    }
}

/** 
    \class Shellsort
*/
 
template <typename T>
class ShellSort : public Sorteermethode<T>{
    public:
        void operator()(vector<T> & v) const;
};

#endif 