#include "sorteermethode.h"
#include <iostream>
	using std::cout;

int main(){

	srand(time(0));

	/* STLSort */

	cout << "STLSort \n";

	Sortvector<int> s1(10);
	s1.vul_random_zonder_dubbels();	
	cout << s1 << "\n";

	STLSort<int> stlSort;
	stlSort(s1);
	cout << s1 << "\n";

	/* InsertionSort */

	cout << "InsertionSort \n";

	Sortvector<int> s2(10);
	s2.vul_random_zonder_dubbels();	
	cout << s2 << "\n";

	InsertionSort<int> insertionSort;
	insertionSort(s2);
	cout << s2 << "\n";

	return 0;
}