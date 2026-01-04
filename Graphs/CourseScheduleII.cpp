#include<iostream>
#include<queue>

using namespace std;

vector<int> canFinish(int n, vector<vector<int>>& preReq){

    // graph and indegree array
    vector<vector<int>> graph(n);
    vector<int> indegree(n,0);
    vector<int> topOrder;

    for(auto p :preReq){
        int course = p[0];
        int pre = p[1];
        // pre->course
        graph[pre].push_back(course);
        indegree[course]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            topOrder.push_back(i);
            q.push(i);
        }
    }

    // BFS (Kahn's Algorithm)
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int next : graph[node]){
            indegree[next]--;
            if(indegree[next] == 0){
                q.push(next);
                topOrder.push_back(next);
            }
        }
    }
    if(topOrder.size() != n){
        return vector<int>();
    }
    return topOrder;
}

int main(){
    int n = 4;
    vector<vector<int>> preReq = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };

    vector<int> ans =  canFinish(n, preReq);
    for(auto o: ans){
        cout << o << " ";
    }
    return 0;
}
