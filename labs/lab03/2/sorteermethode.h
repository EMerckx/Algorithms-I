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
    using std::reverse;
#include <math.h>

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
        virtual void calculateIncrements(vector<T> & v, vector<int> & inc) const;    
    //private:
        // the increments used for the sort
        //vector<int> & increments;
};

template <typename T>
void ShellSort<T>::operator()(vector<T> & v) const {

    vector<int> increments;
    this->calculateIncrements(v, increments);

    /*for(int i=0; i<increments.size(); i++){
        cout << increments[i] << " "; 
    }*/

    int inc = increments.size() - 1;
    while(inc>=0){

        int k = increments[inc];

        for(int i=k; i<v.size(); i++){
            T h = move(v[i]);
            int j = i - k;
            while(j>=0 && h < v[j]){
                v[j+k] = move(v[j]);
                j -= k;
            }
            v[j+k] = move(h);
        }

        inc--;
    }
}

/** 
    \class ShellSedgewickSort
*/

template <typename T>
class ShellSedgewickSort : public ShellSort<T>{
    public:
        //ShellSedgewickSort();
        void calculateIncrements(vector<T> & v, vector<int> & inc) const;
    private:
        //vector<int> increments;
};

/*template<typename T>
ShellSedgewickSort<T>::ShellSedgewickSort(){
    vector<int> myinc = { 1, 5, 19, 41, 109, 209, 505, 929, 2161, 3905, 8929,
            16001, 36289, 64769, 146305, 260609, 587521, 1045505, 2354689,
            4188161, 9427969, 16764929, 37730305, 67084289, 150958081,
            268386305, 603906049, 1073643521 };

    //increments = vector<int>(myinc.begin(), myinc.end()); 

}*/

template <typename T>
void ShellSedgewickSort<T>::calculateIncrements(vector<T> & v, vector<int> & inc) const{
    vector<int> myinc = { 1, 5, 19, 41, 109, 209, 505, 929, 2161, 3905, 8929,
            16001, 36289, 64769, 146305, 260609, 587521, 1045505, 2354689,
            4188161, 9427969, 16764929, 37730305, 67084289, 150958081,
            268386305, 603906049, 1073643521 };

    auto it = myinc.begin();
    while(it != myinc.end() && (*it) < v.size()){
        it++;
    }

    inc = vector<int>(myinc.begin(), it); 

    /*int powerof2 = 1;
    int powerof2half = 1;
    
    // we calculate the first increment 
    // and put it in the increments vector
    int increment = 1;
    int previousincrement = 0;

    // go until no further possible
    // this means: until we have overflow
    while (previousincrement < increment ){

        // if valid, add the increment to the increments vector
        ShellSort<T>::increments.push_back(increment);

        // recalculate the power of 2
        powerof2 *= 2 ;

        // calculate the increment
        // i = even -> 9 * 2^i - 9 * 2^(i/2) + 1
        // i = odd  -> 8 * 2^i - 6 * 2^((i+1)/2) + 1
        if(ShellSort<T>::increments.size() % 2 == 0){
            
            increment = 9 * powerof2 - 9 * sqrt(powerof2) + 1;
        }
        else {

            powerof2 *= 2 ;

            increment = 8 * powerof2 - 6 * sqrt(powerof2 * 2) + 1;
        }
    }*/
}

/** 
    \class ShellShellSort
*/
/*
template <typename T>
class ShellShellSort : public ShellSort<T>{
    public:
        void calculateIncrements(vector<T> & v);
};

template <typename T>
void ShellShellSort<T>::calculateIncrements(vector<T> & v){
    
    // calculate initial increment
    int increment = v.size() / 2;

    while (increment >= 1){
        // add the increment at the end of the vector
        ShellSort<T>::increments.push_back(increment);

        // calculate the new increment
        increment /= 2;
    }

    // but now we have the increments in the wrong order
    // so we will reverse our vector
    reverse(ShellSort<T>::increments.begin(), ShellSort<T>::increments.end());
}*/



#endif 