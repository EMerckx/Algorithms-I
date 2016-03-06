#include "sorteermethode.h"
#include <iostream>
	using std::cout;

int main(){

	srand(time(0));

	/* STLSort */
	STLSort<int> stlSort;
	cout << "STLSort \n";
	stlSort.meet(10, 100000, cout);
	cout << "\n";

	/* InsertionSort */
	cout << "InsertionSort \n";
	InsertionSort<int> insertionSort;
	insertionSort.meet(10, 10000, cout);
	
	/* ShellSedgewickSort */
	cout << "ShellSedgewickSort \n";
	ShellSedgewickSort<int> shellSedgewickSort;
	shellSedgewickSort.meet(10, 10000, cout);

	/* ShellShellSort */
	cout << "ShellShellSort \n";
	ShellShellSort<int> shellShellSort;
	shellShellSort.meet(10, 10000, cout);

	return 0;
}