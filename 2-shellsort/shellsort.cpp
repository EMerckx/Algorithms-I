#include <iostream>
	using std::cout;
	using std::ostream;
	using std::endl;
#include <vector>
	using std::vector;

template <typename T>
void shellsort(vector<T> & v);
template <typename T>
void operator<<(ostream & os, vector<T> & v);

int main(){
	// create the vector of items
	vector<int> v = { 1, 5, 3, 7, 2, 9 };
	// print the unsorted vector
	cout << v;
	// sort the vector
	shellsort(v);
	// print the sorted vector
	cout << v;

	return 0;
}

// Sorting method with decreasing increments
template <typename T>
void shellsort(vector<T> & v){
	int k = v.size() / 2; // initial increment
	while(k>=1){
		for(int i=k; i<v.size(); i++){
			T temp = v[i];
			int j = i - k;
			while(j>=0 && temp<v[j]){
				v[j+k] = v[j];
				j -= k;
			}
			v[j+k] = temp;
		}
		k /= 2;
	}
}

// Shows the operator << how to print the vector
template <typename T>
void operator<<(ostream & os, vector<T> & v){
	for(int i=0; i<v.size(); i++){
		os << v[i] << " ";
	}
	os << endl;
}

