#include <iostream>
#include <vector>
using namespace std;

/*
------------------------------------------------------------
Find function with PATH COMPRESSION
------------------------------------------------------------
- Finds the ultimate parent (root) of a node
- Path compression flattens the tree for efficiency
*/
int findParent(int node, vector<int>& parent) {
    // Base case:
    // If a node is its own parent, it is the leader
    if (parent[node] == node)
        return node;

    // Recursive case:
    // Attach node directly to ultimate parent
    return parent[node] = findParent(parent[node], parent);
}

/*
------------------------------------------------------------
Union function
------------------------------------------------------------
- Tries to connect u and v
- Returns false if u and v already belong to same component
  (cycle detected)
- Returns true if merge is successful
*/
bool unionSet(int u, int v, vector<int>& parent) {
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);

    // If both nodes have same parent → cycle
    if (pu == pv)
        return false;

    // Merge components
    parent[pv] = pu;
    return true;
}

/*
------------------------------------------------------------
Main function to find redundant connection
------------------------------------------------------------
*/
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();

    // Parent array (1-based indexing)
    vector<int> parent(n + 1);

    // Initially, each node is its own parent
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    // Process each edge
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // If union fails → cycle detected
        if (!unionSet(u, v, parent)) {
            return {u, v}; // redundant edge
        }
    }

    return {}; // never reached
}

/*
------------------------------------------------------------
Example Driver Code
------------------------------------------------------------
*/
int main() {
    vector<vector<int>> edges = {{1,2}, {1,3}, {2,3}};

    vector<int> ans = findRedundantConnection(edges);

    cout << "Redundant Edge: [" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}
