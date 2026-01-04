#include<iostream>
using namespace std;

void dfs(vector<vector<int>>& arr, int x, int y, int prev, vector<vector<bool>>& ocean){
    // boundary check
    if(x < 0 || x >= arr.size() || y < 0 || y >= arr[0].size()){
        return;
    }

    if(ocean[x][y]){
        return;
    }

    if(ocean[x][y]){
        return;
    }

    if(arr[x][y]<prev){
        return;
    }

    // MARK VISITED
    ocean[x][y] = true;

    // EXPLORE ALL 4 DIRECTION
    dfs(arr,x+1,y,arr[x][y],ocean);
    dfs(arr,x-1,y,arr[x][y],ocean);
    dfs(arr,x,y+1,arr[x][y],ocean);
    dfs(arr,x,y-1,arr[x][y],ocean);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights){
    vector<vector<int>> res;
    int n = heights.size();
    int m = heights[0].size();

    vector<vector<bool>> pacifi(n, vector<bool>(m, false));
    vector<vector<bool>> atlan(n, vector<bool>(m, false));

    // Left and Right boards 
    for(int i=0; i < n; i++){
        dfs(heights, i, 0, INT_MIN, pacifi); // Pacific
        dfs(heights, i, m - 1, INT_MIN, atlan); // Atlantic
    }

    // Top & Bottom borders
    for (int j = 0; j < m; j++) {
        dfs(heights, 0, j, INT_MIN, pacifi);      // Pacific
        dfs(heights, n - 1, j, INT_MIN, atlan);   // Atlantic
    }

    // Cells reachable by both oceans
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacifi[i][j] && atlan[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
    return res;
}

int main(){
    vector<vector<int>> heights = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };

    vector<vector<int>> result = pacificAtlantic(heights);

    for (auto &cell : result) {
        cout << "[" << cell[0] << "," << cell[1] << "] ";
    }
    cout << endl;

    return 0;
}