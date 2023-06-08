#include <iostream>
#include <climits>

using namespace std;


#define V 6 // number of vertices in the graph

void primalgorithm(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    // Initialize arrays for storing minimum key values and parent nodes
    for (int i=0; i<V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count=0; count<V-1; count++) {
         int min = INT_MAX, index;

        // Find the vertex with the minimum key value
        for (int v=0; v<V; v++)
            if(not mstSet[v] && key[v]<min)
                min = key[v], index = v;
        int u = index;

        mstSet[u] = true;

        for (int v=0; v<V; v++)
            if (graph[u][v] && not mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    //print the mst
    cout<<"Edge    Weight\n";
    for (int i=1; i<V; i++)
        cout<<parent[i]<< " - " << i <<"\t"<<graph[i][parent[i]] <<"\n";
}

int main() {
    int graph[V][V] = {{0,3,0,0,0,1},
                       {3,0,2,1,10,0},
                       {0,2,0,3,0,5},
                       {0,1,3,0,5,0},
                       {0,10,0,5,0,4},
                       {1,0,5,0,4,0}};

    primalgorithm(graph);

    return 0;
}
