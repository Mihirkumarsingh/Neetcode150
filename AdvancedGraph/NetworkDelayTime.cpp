#include<iostream>
#include<queue>
#include<set>
using namespace std;

/*
Function: networkDelayTime
--------------------------
times : list of edges {u, v, w}
k     : starting node
NOTE  : n is NOT given, we compute it ourselves
*/
int networkDelayTime(vector<vector<int>>& times, int k){
    /*
    Step 1: Find total number of nodes (n)
    */
   set<int> nodes;

   for(auto t: times){
    nodes.insert(t[0]);
    nodes.insert(t[1]);
   }

   int n = nodes.size();

   /*
    STEP 2: Build adjacency list
    ----------------------------
    edges[u] = list of {v, w}
    */
    unordered_map<int, vector<pair<int, int>>> edges;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for (auto &t : times) {
        int u = t[0];
        int v = t[1];
        int w = t[2];
        edges[u].push_back({v, w});
    }

    minHeap.push({0,k});

    // STEP 3: Visited nodes
    set<int> visited;

    int maxTime = 0;

    // STEP 4: Dijkstra Algorithm
    while (!minHeap.empty()) {

        auto top = minHeap.top();
        minHeap.pop();

        int currTime = top.first;
        int currNode = top.second;

        // If already visited, skip
        if (visited.count(currNode)) {
            continue;
        }

        // Mark as visited
        visited.insert(currNode);

        // Update max time
        maxTime = currTime;

        // Visit neighbors
        for (auto &next : edges[currNode]) {
            int nextNode = next.first;
            int weight = next.second;

            if (!visited.count(nextNode)) {
                minHeap.push({currTime + weight, nextNode});
            }
        }
    }

    // STEP 5: Check if all nodes were reached
    return visited.size() == n ? maxTime : -1;
}

int main(){
    vector<vector<int>> times = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };

    int k = 2;

    int result = networkDelayTime(times, k);
    cout << "Network Delay Time = " << result << endl;

    return 0;
}