#ifndef __SORTVECTOR
#define __SORTVECTOR
/**
 \class sortvector
 \brief is een klasse van sorteerbare vectoren
 Bovenop de vectoreigenschappen zijn er hulpfuncties om sorteervergelijkingen
 te vergemakkelijken.
*/
#include <iostream>
    using std::istream;
    using std::ostream;
#include <algorithm>
    using std::move;
    using std::swap;
    using std::reverse;
    using std::random_shuffle;
#include <iomanip>   // voor setw
    using std::setw;
#include <cstdlib>   // voor rand - opletten!! 
    using std::srand;
#include <ctime>
    using std::time;
#include <vector>
    using std::vector;

template<class T>
class Sortvector:public vector<T>{
  public:

    /// \fn Constructor: het argument geeft de grootte aan
    /// bij constructie zal de tabel opgevuld worden met
    /// n verschillende getallen in random volgorde
    /// (zie hulplidfuncties)
    Sortvector(int);
    
    Sortvector(const Sortvector<T>& v) = delete;
    Sortvector<T>& operator=(const Sortvector<T>& v) = delete;
    Sortvector<T>& operator=(Sortvector<T>&& v) = delete;
    Sortvector(Sortvector<T>&& v) = delete;

    /// \fn vul_range vul vector met de waarden T(0)...T(size()-1) in volgorde
    void vul_range();
    void draai_om();
    void vul_omgekeerd();
    void shuffle();
    void vul_random_zonder_dubbels();
    void vul_random(); //< nog niet implementeren
    
    bool is_gesorteerd() const;
    /// \fn is_range controleert of *this eruit ziet als het resultaat van vul_range(), d.w.z.
    /// dat, voor alle i (*this)[i]==T(i);
    bool is_range() const;

    friend ostream& operator<<(ostream& os, const Sortvector<T>& s){
        s.schrijf(os);
        return os;
    }

  private: 
    void schrijf(ostream & os)const;
    
};

template <class T>
Sortvector<T>::Sortvector(int length){
    this->resize(length);
}

template <class T>
void Sortvector<T>::vul_range(){
    T value = 0;
    for(auto&& t : *this){
        t = value;
        value++;
    }
}

template <class T>
void Sortvector<T>::draai_om(){
    reverse(this->begin(), this->end());
}

template <class T>
void Sortvector<T>::vul_omgekeerd(){
    T value = (T) this->size() - 1;
    for(auto&& t : *this){
        t = value;
        value--;
    }
}

template <class T>
void Sortvector<T>::shuffle(){
    random_shuffle(this->begin(), this->end());
}

template <class T>
void Sortvector<T>::vul_random_zonder_dubbels(){
    this->vul_range();
    this->shuffle();
}

template <class T>
bool Sortvector<T>::is_gesorteerd() const {
    int length = this->size();

    if(length == 0){
        return true;
    }

    int i = 1;
    while(i < length && this->at(i-1) <= this->at(i) ){
        i++;
    }

    return (i == length);
}

template <class T>
bool Sortvector<T>::is_range() const {
    int length = this->size();

    if(length == 0){
        return true;
    }

    int i = 1;
    while(i < length && this->at(i-1) == this->at(i) - 1 ){
        i++;
    }

    return (i == length);
}


template <class T>
void Sortvector<T>::schrijf(ostream & os)const{
    for(auto&& t : *this){
        os<<t<<" ";
    }
    os<<"\n";
}


#endif