#include "sorteermethode.h"
#include <iostream>
	using std::cout;

int main(){

	srand(time(0));

	CsvData csv("results.csv");

	/* STLSort */
	STLSort<int> stlSort;
	cout << "STLSort \n";
	stlSort.meet(10, 100000, csv);

	/* InsertionSort */
	cout << "InsertionSort \n";
	InsertionSort<int> insertionSort;
	insertionSort.meet(10, 100000, csv);

	return 0;
}