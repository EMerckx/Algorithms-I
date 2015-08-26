#include "graaf.h"

int main() {

    Graaf<ONGERICHT> graph(4);
    graph.voeg_verbinding_toe(0, 1);
    graph.voeg_verbinding_toe(3, 1);
    graph.voeg_verbinding_toe(2, 3);
    graph.voeg_verbinding_toe(0, 2);
    graph.voeg_verbinding_toe(0, 3);

    graph.schrijf(cout);
    cout << endl;

    cout << "Breadth first search : node sequence" << endl;
    graph.breadth_first_search();
    cout << endl;

    return 0;
}