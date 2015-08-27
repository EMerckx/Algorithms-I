#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::ostream;
using std::vector;

template <class T>
bool is_sorted(vector<T> & v);

template <class T>
bool sort_by_backtracking(vector<T> input, vector<T> output, int level);

template<typename T>
ostream &operator<<(ostream &os, vector <T> &v);

int main(){

    vector<int> input = {3,4,1};
    vector<int> output;

    sort_by_backtracking(input, output, 0);

    return 0;
}

template <class T>
bool is_sorted(vector<T> & v){
    if(v.size()>1) {
        int i = 1;
        while (i < v.size() && v[i - 1] <= v[i]) {
            i++;
        }
        return (i == v.size()) ? true : false;
    }
    else {
        return true;
    }
}

template <class T>
bool sort_by_backtracking(vector<T> input, vector<T> output, int level){
    cout << "input: " << input << " - output: " << output << "level: " << level << endl;
    if(!is_sorted(output)){
        // the output vector is not sorted : backtrack
        return false;
    }
    else if(input.size()==0){
        // we have found the solution
        return true;
    }
    else {
        // we are still searching for a solution
        for(int i=0; i<input.size(); i++){
            // create new input vector = the input vector without input[i]
            vector<T> new_input(input.size()-1);
            int k = 0;
            for(int j=0; j<input.size(); j++){
                if(i!=j){
                    new_input[k++] = input[j];
                }
            }

            // create new output vector = the output vector with input[i]
            vector<T> new_output(output);
            new_output.push_back(input[i]);

            if(sort_by_backtracking(new_input, new_output, level+1)){
                return true;
            }
        }

        return false;
    }
}

// Shows the operator << how to print the vector
template<typename T>
ostream &operator<<(ostream &os, vector <T> &v) {
    for (int i = 0; i < v.size(); i++) {
        os << v[i] << " ";
    }
    return os;
}