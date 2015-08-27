#include <iostream>
#include <vector>
#include ""
#include <tuple>

using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::priority_queue;
using std::pair;

int main() {

    vector <int> v = {5, 6, 7, 9, 1, 2, 4, 2, 6, 1, 2, 9};

    // normal queue ______________________________________________________
    queue <int> q1;
    for (int i = 0; i < v.size(); i++) {
        q1.push(v[i]);
    }
    cout << "queue" << endl;
    while (!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl << endl;

    // priority queue ____________________________________________________
    priority_queue <int> q2;
    for (int i = 0; i < v.size(); i++) {
        q2.push(v[i]);
    }
    cout << "priority queue (standard = greater to smaller)" << endl;
    while (!q2.empty()) {
        cout << q2.top() << " ";
        q2.pop();
    }
    cout << endl << endl;

    // priority queue reversed ___________________________________________
    priority_queue <int, vector<int>, std::greater<int>> q3;
    for (int i = 0; i < v.size(); i++) {
        q3.push(v[i]);
    }
    cout << "priority queue (reversed = smaller to greater)" << endl;
    while (!q3.empty()) {
        cout << q3.top() << " ";
        q3.pop();
    }
    cout << endl << endl;

    // priority queue with pairs _________________________________________
    vector <char> c = {'a', 'k', 'p', 'n', 'v', 'v', 'm', 'd', 'a', 'w', 'y', 'b'};
    priority_queue <pair<int, char >> q4;
    for (int i = 0; i < v.size(); i++) {
        q4.push(pair<int, char>(v[i], c[i]));
    }
    cout << "priority queue with pairs" << endl << "(standard = greater to smaller)" << endl;
    while (!q4.empty()) {
        cout << q4.top().first << "," << q4.top().second << " ";
        q4.pop();
    }
    cout << endl << endl;

    // priority queue reversed with pairs ________________________________
    priority_queue < pair < int, char >, vector < pair < int, char >>, std::greater < pair < int, char >> > q5;
    for (int i = 0; i < v.size(); i++) {
        q5.push(pair<int, char>(v[i], c[i]));
    }
    cout << "priority queue with pairs" << endl << "(reversed = smaller to greater)" << endl;
    while (!q5.empty()) {
        cout << q5.top().first << "," << q5.top().second << " ";
        q5.pop();
    }
    cout << endl << endl;


    return 0;
}