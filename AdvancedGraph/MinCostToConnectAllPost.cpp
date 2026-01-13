#include<iostream>
#include<queue>
using namespace std;
/*
Function: minCostConnectPoints
------------------------------
Uses Prim's Algorithm to find Minimum Spanning Tree (MST)

points[i] = {x, y} coordinate of point i
Cost to connect two points = Manhattan Distance
*/
int minCostConnectPoints(vector<vector<int>>& points){
    int  n = points.size();

    vector<bool> visited(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > minHeap;

    minHeap.push({0, 0});

    int totalCost = 0;
    int connected = 0;

    // Continue until all points are connected
    while (connected < n) {

        auto top = minHeap.top();
        minHeap.pop();

        int cost = top.first;
        int currPoint = top.second;

        // If already visited, skip
        if (visited[currPoint]) {
            continue;
        }

        // Mark current point as connected
        visited[currPoint] = true;
        totalCost += cost;
        connected++;

        // Try connecting to all other unvisited points
        for (int next = 0; next < n; next++) {
            if (!visited[next]) {

                // Manhattan distance
                int dist =
                    abs(points[currPoint][0] - points[next][0]) +
                    abs(points[currPoint][1] - points[next][1]);

                minHeap.push({dist, next});
            }
        }
    }
    return totalCost;
}

int main(){
    vector<vector<int>> points = {
        {0, 0},
        {2, 2},
        {3, 10},
        {5, 2},
        {7, 0}
    };

    int result = minCostConnectPoints(points);

    cout << result;
    return 0;
}