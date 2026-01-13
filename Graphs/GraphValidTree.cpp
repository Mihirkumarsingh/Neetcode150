#include <iostream>
#include <vector>
using namespace std;

/*
========================================================
DISJOINT SET / UNION FIND EXPLANATION (VERY IMPORTANT)

parent[i] = j  means:
node 'i' belongs to a group whose leader (boss) is 'j'

If parent[i] == i
→ i is the leader of its own group

Initially:
Every node is alone and is its own parent
========================================================
*/


/*
--------------------------------------------------------
findParent()
--------------------------------------------------------
PURPOSE:
Find the "ultimate parent" (leader) of a node.

WHY NEEDED?
Two nodes belong to the same connected component
if and only if their ultimate parent is the same.

PATH COMPRESSION:
While finding the parent, we directly attach the node
to the ultimate parent to make future searches faster.
--------------------------------------------------------
*/
int findParent(int node, vector<int>& parent) {

    // Base case:
    // If a node is its own parent,
    // then this node is the leader of the group
    if (parent[node] == node)
        return node;

    /*
    Recursive step:
    - Find parent of current parent
    - Attach current node directly to ultimate parent
    (This is PATH COMPRESSION)
    */
    return parent[node] = findParent(parent[node], parent);
}


/*
--------------------------------------------------------
unionSet()
--------------------------------------------------------
PURPOSE:
Connect (union) two nodes u and v.

STEPS:
1. Find parent (leader) of u
2. Find parent (leader) of v
3. If both leaders are same → cycle detected ❌
4. Otherwise, merge both groups ✔️

RETURN VALUE:
false → cycle detected
true  → union successful
--------------------------------------------------------
*/
bool unionSet(int u, int v, vector<int>& parent) {

    // Find leaders of u and v
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);

    /*
    If both nodes have the same leader,
    they are already connected.

    Trying to connect them again will form a CYCLE.
    */
    if (pu == pv)
        return false;   // cycle detected

    /*
    Merge two sets:
    Make leader of v point to leader of u
    (You can also do opposite; both are fine here)
    */
    parent[pv] = pu;

    return true;  // union successful
}


/*
--------------------------------------------------------
validTree()
--------------------------------------------------------
PURPOSE:
Check if the given graph is a VALID TREE

A graph is a TREE if:
1) Number of edges = n - 1
2) Graph is connected
3) Graph has no cycle

Union-Find helps us check condition (2) and (3)
--------------------------------------------------------
*/
bool validTree(int n, vector<vector<int>>& edges) {

    /*
    CONDITION 1:
    A tree with 'n' nodes MUST have exactly 'n - 1' edges.
    If not, it cannot be a tree.
    */
    if (edges.size() != n - 1)
        return false;

    /*
    Create parent array
    Initially, every node is its own parent (leader)
    */
    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    /*
    Process each edge
    Try to connect the two nodes of the edge
    */
    for (int i = 0; i < edges.size(); i++) {

        int u = edges[i][0];
        int v = edges[i][1];

        /*
        If unionSet returns false,
        a cycle is found → not a tree
        */
        if (!unionSet(u, v, parent))
            return false;
    }

    /*
    If:
    - No cycle found
    - Correct number of edges
    Then graph is connected and acyclic

    Hence, VALID TREE ✔️
    */
    return true;
}


/*
--------------------------------------------------------
MAIN FUNCTION
--------------------------------------------------------
Example:
n = 5
edges = [[0,1], [0,2], [0,3], [1,4]]

Graph:
        0
      / | \
     1  2  3
     |
     4

✔️ Connected
✔️ No cycle
✔️ edges = n - 1

Hence output = true
--------------------------------------------------------
*/
int main() {

    int n = 5;

    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {0, 3},
        {1, 4}
    };

    if (validTree(n, edges))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
