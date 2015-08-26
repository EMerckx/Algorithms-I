#include "weighted-graph.h"

int main() {

    GewogenGraaf<int> graph(6);
    graph.voeg_verbinding_toe(0, 1, 4);
    graph.voeg_verbinding_toe(3, 1, 5);
    graph.voeg_verbinding_toe(2, 3, 8);
    graph.voeg_verbinding_toe(0, 2, 3);
    graph.voeg_verbinding_toe(0, 3, 2);
    graph.voeg_verbinding_toe(5, 4, 1);


    cout << "Minimal Spanning Tree : edge sequence" << endl;
    vector <bool> mst = graph.get_mst();
    cout << endl;

    for (int i = 0; i < mst.size(); i++) {
        cout << "edge " << i << " is element of MST: " << mst[i] << endl;
    }

    return 0;
}