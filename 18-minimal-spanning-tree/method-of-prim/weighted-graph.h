#ifndef __WEIGHTED_GRAPH_H
#define __WEIGHTED_GRAPH_H

#include "gewogengraaf.h"
#include <tuple>
#include <queue>
#include <functional>
#include <iostream>

using std::vector;
using std::pair;
using std::priority_queue;
using std::greater;
using std::cout;
using std::endl;

template <class Edgedata>
using Mstdata = pair < Edgedata, pair < int, int >>;

enum Color {
    WHITE, BLACK
};

// returns the minimal spanning tree
// as a vector where the edge numbers are mapped to booleans
// to indicate whether the edge is in the mst or not 
template<class Edgedata>
vector <bool> GewogenGraaf<Edgedata>::get_mst() const {
    if (knopen.size() > 0) {
        // init
        vector <bool> mst_edges(aantal_verbindingen(), false);
        vector <Color> colors(aantal_knopen(), WHITE);
        priority_queue < Mstdata<Edgedata>, vector< Mstdata<Edgedata> >, 
            greater< Mstdata<Edgedata> > > q;

        for( int i = 0; i < aantal_knopen(); i++ ){
            if (colors[i] == WHITE) {
                // add all the egdes of the firste node to the queue
                for (auto &kv : knopen[i]) {
                    // kv.first is destination node
                    // kv.second is edge number
                    q.push( Mstdata<Edgedata>(takdatavector[kv.second], kv) );
                }
                colors[i] = BLACK;

                while (!q.empty()) {
                    // get the edge with the lowest cost
                    Mstdata<Edgedata> lowest_cost_edge = q.top();
                    q.pop();

                    // get the number of the next node
                    int j = lowest_cost_edge.second.first;
                    // if the node is not yet discovered, use it
                    if (colors[j] == WHITE) {
                        // add the edge to the MST
                        mst_edges[lowest_cost_edge.second.second] = true;


                        // handle functionality
                        // here: print the edge
                        cout << "edge " << lowest_cost_edge.second.second
                        << " from node ?" << " to node " << lowest_cost_edge.second.first
                        << " with weight " << lowest_cost_edge.first << endl;

                        // add the edges of the current node to the queue
                        // BUT only when the neighbour is a white node!
                        for (auto &kv : knopen[j]) {
                            if (colors[kv.first] == WHITE) {
                                q.push(Mstdata<Edgedata> (takdatavector[kv.second], kv));
                            }
                        }

                        // set the current node as handled
                        colors[j] = BLACK;
                    }
                }
            }
        }
        return mst_edges;
    }
    else {
        vector <bool> v;
        return v;
    }
}

#endif //__WEIGHTED_GRAPH_H
