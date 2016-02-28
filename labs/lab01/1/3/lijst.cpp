// DEEL 0
// de opgave, startpunt voor de oefening op 'introductie unique pointers'

#include <iostream>
using namespace std;

typedef int T;

class Knoop;

class Lijst{
	public:
	    Lijst();
		Lijst(const T &);
		void append(Lijst & andereLijst);
        string to_string() const;	 // handig voor testen
        ~Lijst(){}
	private:
		Knoop* eerste;
		Knoop* laatste;	
		void schrijf(ostream & out)const;	
			
	friend ostream & operator<<(ostream & out, const Lijst & l){
		l.schrijf(out);
		return out;
	}	
	
};

class Knoop{
	friend class Lijst;
	private:
		T sl;
		Knoop* volgende; 
	public:
		Knoop(const T & _sl):sl(_sl){};
};

Lijst::Lijst(){
	eerste = 0;
	laatste = 0;
}

Lijst::Lijst(const T & t){
	eerste = new Knoop(t);
	laatste = eerste;	
}

void Lijst::append(Lijst & andereLijst){
	laatste->volgende = andereLijst.eerste;
	laatste = andereLijst.laatste;
	andereLijst.laatste = 0;
	andereLijst.eerste = 0;
}

void Lijst::schrijf(ostream & out)const{
	out<<to_string();
}

string Lijst::to_string()const{
	string str="";
	Knoop* loper = eerste;
	while(loper!=0){
		str = str + std::to_string(loper->sl) + "-";  // to_string(int) is nieuw voor C++11
		loper = loper->volgende;
	}
	str += "X";
	return str;
}

void test_append(Lijst & a, Lijst & b, const string & naam_a, const string & naam_b, const string & verwachte_uitkomst_a, const string & verwachte_uitkomst_b){	
	cout<<endl<<"    Voor append: \n    "<<naam_a<<": "<<a<<"\n    "<<naam_b<<": "<<b<<endl;	
	a.append(b);		
	cout<<endl<<"    Na append: \n    "<<naam_a<<": "<<a<<"\n    "<<naam_b<<": "<<b<<endl;
	if(a.to_string() == verwachte_uitkomst_a && b.to_string() == verwachte_uitkomst_b){
		cout<<"ok"<<endl;	
	}
	else{
		cout<<"niet ok"<<endl;
	}
}

void test_gelijkheid(const Lijst & a, const string & verwachte_voorstelling){
	if(a.to_string() == verwachte_voorstelling){
		cout<<"ok"<<endl;	
	}
	else{
		cout<<"niet ok"<<endl;
	}	
}

int main(){
		
	Lijst a(5);
	Lijst b(10);
	test_append(a,b,"a","b","5-10-X","X");
	
	Lijst x(0);
	for(int i=1; i<=5; i++){
		Lijst y(i);
		x.append(y);
	}
	test_gelijkheid(x,"0-1-2-3-4-5-X");
	
	return 0;
}
