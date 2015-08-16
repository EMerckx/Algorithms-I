#include <iostream>
	using std::cout;
	using std::ostream;
	using std::endl;
#include <vector>
	using std::vector;

template <typename T>
void insertionsort(vector<T> & v);
template <typename T>
void operator<<(ostream & os, vector<T> & v);

int main(){
	// create the vector of items
	vector<int> v = { 1, 5, 3, 7, 2, 9 };
	// print the unsorted vector
	cout << v;
	// sort the vector
	insertionsort(v);
	// print the sorted vector
	cout << v;

	return 0;
}

template <typename T>
void insertionsort(vector<T> & v){
	for(int i=1; i<v.size(); i++){
		T temp = v[i];
		int j = i - 1;
		while(j>=0 && temp<v[j]){
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = temp;
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

