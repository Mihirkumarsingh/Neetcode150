#include<iostream>
#include<queue>
using namespace std;

bool canFinish(int n, vector<vector<int>>& preReq){

    // graph and indegree array
    vector<vector<int>> graph(n);
    vector<int> indegree(n,0);

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
            q.push(i);
        }
    }

    int completed = 0;

    // BFS (Kahn's Algorithm)
    while(!q.empty()){
        int node = q.front();
        q.pop();
        completed++;
        for(int next : graph[node]){
            indegree[next]--;
            if(indegree[next] == 0){
                q.push(next);
            }
        }
    }
    return completed == n;
}

int main(){
    int n = 4;
    vector<vector<int>> preReq = {
        {1, 0},
        {2, 1},
        {3, 2}
    };

    cout << canFinish(n, preReq);
    return 0;
}
