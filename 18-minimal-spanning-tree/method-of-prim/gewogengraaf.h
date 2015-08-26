#ifndef __GEWOGENGRAAF_H
#define __GEWOGENGRAAF_H
#include "graaf.h"
template<class Takdata>
class GewogenGraaf: public virtual Graaf<ONGERICHT>{
public:
    GewogenGraaf(int n=0):Graaf<ONGERICHT>(n){};
    //Noot: toevoegfunctie zonder takdata op te geven kan alleen gebruikt als de klasse
    //      Takdata een defaultconstructor heeft.

    virtual int voeg_verbinding_toe(int van, int naar);
    virtual int voeg_verbinding_toe(int van, int naar, const Takdata&);

    //Noot: verwijder_verbinding niet voorzien; wordt ongewijzigd overgenomen van Graaf
    //      indien daar bekend.

    //TakData vrijgeven (eventueel voor wijziging). Geeft nullpointer als tak niet bestaat
    //Noot: pointers teruggegeven door geef_takdata worden ongeldig
    //door toevoegen van een tak.
    const Takdata* geef_takdata(int van,int naar) const;
    Takdata* geef_takdata(int van,int naar)      ;

    // wist alle gegevens uit de graaf; aantal knopen is dan ook nul!
    virtual void wis();

    // Schrijft de gegevens van de verbinding met verbindingsnummer v naar outputstream os.
    virtual void schrijf_verbinding(std::ostream &os, int v) const;

    //own implementation
    std::vector <bool> get_mst() const;

protected:
    std::vector<Takdata> takdatavector;
};


template< class Takdata>
int GewogenGraaf<Takdata>::voeg_verbinding_toe(int van, int naar){
    return this->voeg_verbinding_toe(van,naar,Takdata());
}


template< class Takdata>
int GewogenGraaf<Takdata>::voeg_verbinding_toe(int van, int naar, const Takdata& td){
    int taknummer=Graaf<ONGERICHT>::voeg_verbinding_toe(van,naar);
    takdatavector.push_back(td);
    return taknummer;
}



template< class Takdata>
const Takdata* GewogenGraaf<Takdata>::geef_takdata(int van,int naar) const{
    int taknummer=this->verbindingsnummer(van,naar);
    if (taknummer!=-1)
        return &takdatavector[taknummer];
    else
        return 0;
}


/*
// Voeg in de klasse graaf (header graaf.h) volgende lidfunctie toe:
template <GraafType TYPE>
int Graaf<TYPE>::verbindingsnummer(int van, int naar)const{
	if((*this)[van].count(naar)==1){
		return (*this)[van].at(naar);   // return (*this)[van][naar] is niet mogelijk omdat de oproep
		                                // van de operator[] de map niet const laat
		                                // vandaar het gebruik van at(...)
	}
	else return -1;
}
*/

template< class Takdata>
Takdata* GewogenGraaf<Takdata>::geef_takdata(int van,int naar){
    int taknummer=this->verbindingsnummer(van,naar);
    if (taknummer!=-1)
        return &takdatavector[taknummer];
    else
        return 0;
}


template< class Takdata>
void GewogenGraaf<Takdata>::wis(){
    Graaf<ONGERICHT>::init(0);
    takdatavector.clear();
}

template< class Takdata>
void  GewogenGraaf<Takdata>::schrijf_verbinding(std::ostream &os, int v) const{
    os << " via verbinding nr. " << v <<" (Data: "<<takdatavector[v]<<")"<< std::endl;
}

#endif