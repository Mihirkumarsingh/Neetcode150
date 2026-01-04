#include<iostream>
#include<unordered_set>
#include<queue>
using namespace std;

struct Node {
    int val;
    vector<Node*> neighbors;
    Node(int _val){
        val = _val;
    }
};
Node* dfs(Node* cur, unordered_map<Node*, Node*>& mp){
    Node* clone = new Node(cur->val);
    mp[cur] = clone;
    for(Node* nei : cur->neighbors){
        if (mp.count(nei)) {
            clone->neighbors.push_back(mp[nei]);
        }else{
            clone->neighbors.push_back(dfs(nei, mp));
        }
        
    }
    return clone;
}

// Helper to print graph (BFS)
void printGraph(Node* node) {
    unordered_set<Node*> visited;
    queue<Node*> q;

    q.push(node);
    visited.insert(node);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        cout << "Node " << cur->val << " -> ";
        for (Node* nei : cur->neighbors) {
            cout << nei->val << " ";
            if (!visited.count(nei)) {
                visited.insert(nei);
                q.push(nei);
            }
        }
        cout << endl;
    }
}

Node* cloneGraph(Node* node){
    if(node == nullptr){
        return nullptr;
    }
    unordered_map<Node*, Node*> mp;
    return dfs(node, mp);
}

int main(){
    // Graph
    // 1 -- 2
    // |    |
    // 4 -- 3

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    cout << "Original Graph:\n";
    printGraph(n1);

    Node* cloned = cloneGraph(n1);

    cout << "\nCloned Graph:\n";
    printGraph(cloned);

    return 0;
}