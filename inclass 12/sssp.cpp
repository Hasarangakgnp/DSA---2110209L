#include<bits/stdc++.h>
using namespace std;

int n = 6; //number of cities
vector<pair<int, int>> adjList[6]; //create an adjacency list

//implement the dijkstra's algorithm
void dijkstra(int city) {
    priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int , int>>> pq;
    vector<int> distance(n,INT_MAX );
    distance[city] = 0;
    pq.push({0, city});

    while(not pq.empty()) {
        int u =pq.top().second;
        pq.pop();

    for(const auto& e : adjList[u]){
        int v =e.first;
        int weight =e.second;

        int newDistance =distance[u]+weight;
        if(distance[v] > newDistance) {
            distance[v] = newDistance;
            pq.push({distance[v] ,v});
        }
    }

    }
    cout<< "Shortest time between city "<<city<< " to all other cities:";
    cout<<endl;
    for(int i = 0; i < n; i++){
        cout<<"City "<< i << ": "<<distance[i];
        cout<<endl;
    }
}

int main() {
    //adjacency matrix
    int matrix[6][6] = {
        {0, 10, INT_MAX, INT_MAX, 15, 5},
        {10, 0, 10, 30, INT_MAX, INT_MAX},
        {INT_MAX, 10, 0, 12, 5, INT_MAX},
        {INT_MAX, 30, 12, 0, INT_MAX, 20},
        {15, INT_MAX, 5, INT_MAX, 0, INT_MAX},
        {5, INT_MAX, INT_MAX, 20, INT_MAX, 0}
    };

    //convert adjacency matrix to adjacency list
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(matrix[i][j] != INT_MAX){
                adjList[i].push_back({j,matrix[i][j]});
            }
        }
    }

    //run Dijkstra's algorithm for each city as source vertex
    for (int i=0; i<n; i++) {
        dijkstra(i);
        cout<<endl;
    }
    return 0;
}
