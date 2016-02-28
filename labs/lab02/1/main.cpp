#include "sortvector.h"
#include <iostream>
	using std::cout;

int main(){

	srand(time(0));

	cout << "\n";

	cout << "Sortvector<int> s1(10)" << "\n";
	Sortvector<int> s1(10);
	cout << s1 << "\n";

	cout << "s1.vul_range()" << "\n";
	s1.vul_range();
	cout << s1 << "\n";

	cout << "s1.draai_om()" << "\n";
	s1.draai_om();
	cout << s1 << "\n";

	cout << "s1.vul_range()" << "\n";
	s1.vul_range();
	cout << s1 << "\n";

	cout << "s1.vul_omgekeerd()" << "\n";
	s1.vul_omgekeerd();
	cout << s1 << "\n";

	cout << "s1.shuffle()" << "\n";
	s1.shuffle();
	cout << s1 << "\n";

	cout << "s1.is_gesorteerd(): " << s1.is_gesorteerd() << "\n";
	cout << "s1.is_range(): " << s1.is_range() << "\n";
	cout << s1 << "\n";

	cout << "s1.vul_range()" << "\n";
	s1.vul_range();
	cout << s1 << "\n";

	cout << "s1.is_gesorteerd(): " << s1.is_gesorteerd() << "\n";
	cout << "s1.is_range(): " << s1.is_range() << "\n";
	cout << s1 << "\n";

	return 0;
}