#include <iostream>
	using std::cout;
	using std::ostream;
	using std::endl;
#include <vector>
	using std::vector;
#include <algorithm>
	using std::min;
	using std::max;

template <typename T>
void quicksort(vector<T> & v, int l, int r);
template <typename T>
void operator<<(ostream & os, vector<T> & v);
template <typename T>
void swap(T & a, T & b);
template <typename T>
T getmedianofthree(vector<T> & v, int l, int r);

int main(){
	// create the vector of items
	vector<int> v = { 1, 5, 3, 7, 2, 9 };
	// print the unsorted vector
	cout << v;
	// sort the vector
	quicksort(v, 0, v.size()-1);
	// print the sorted vector
	cout << v;

	return 0;
}

// Sorts the subvector v[l..r]
// l = left index
// r = right index
template <typename T>
void quicksort(vector<T> & v, int l, int r){
	if(l<r){
		// Partition with the median of 3 as pivot
		T pivot = getmedianofthree(v, l, r);
		int i = l, j = r;

		while(v[j]>pivot){
			j--;
		}
		while(v[i]<pivot){
			i++;
		}
		while(i < j){
			swap(v[i], v[j]);
			i++;
			j--;

			while(v[i]<pivot){
				i++;
			}
			while(v[j]>pivot){
				j--;
			}
		}

		// sort both subvectors recursively
		quicksort(v, l, j);
		quicksort(v, j+1, r);
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

// Swaps the value of a with the value of b
template <typename T>
void swap(T & a, T & b){
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T getmedianofthree(vector<T> & v, int l, int r){
	// calculate the middle index
	int m = l + (r - l)/2;

	// find the median
	// formula = max( min(a,b), min(max(a,b), c) )
	T median = max(min(v[l], v[m]), min(max(v[l], v[m]), v[r]));

	return median;
}