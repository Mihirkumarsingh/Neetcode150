#include <iostream>
#include <vector>
using namespace std;

/*
    Find function with Path Compression
    -----------------------------------
    - Finds the ultimate parent (root) of a node
    - Path compression flattens the tree
*/
int findParent(int node, vector<int>& parent) {
    if (parent[node] == node)
        return node;

    // Path compression
    return parent[node] = findParent(parent[node], parent);
}

/*
    Union function
    --------------
    - Connects two nodes if they belong to different components
    - Returns true if a union happened (i.e., components merged)
*/
bool unionSet(int u, int v, vector<int>& parent) {
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);

    // Already in the same component
    if (pu == pv)
        return false;

    // Merge components
    parent[pv] = pu;
    return true;
}

/*
    Function to count connected components
*/
int countConnectedComponents(int n, vector<vector<int>>& edges) {
    // Parent array initialization
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int components = n; // Initially, each node is its own component

    // Process all edges
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // If union happens, one component reduces
        if (unionSet(u, v, parent)) {
            components--;
        }
    }

    return components;
}

int main() {
    // -------- Example 1 --------
    int n1 = 3;
    vector<vector<int>> edges1 = {
        {0, 1},
        {0, 2}
    };

    cout << "Example 1 Output: "
         << countConnectedComponents(n1, edges1) << endl;
    // Expected Output: 1


    // -------- Example 2 --------
    int n2 = 6;
    vector<vector<int>> edges2 = {
        {0, 1},
        {1, 2},
        {2, 3},
        {4, 5}
    };

    cout << "Example 2 Output: "
         << countConnectedComponents(n2, edges2) << endl;
    // Expected Output: 2

    return 0;
}
