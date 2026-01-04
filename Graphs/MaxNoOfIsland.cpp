#include<iostream>
#include<queue>
using namespace std;
// O(n*m)
int bfsArea(vector<vector<int>>& grid, int i, int j){
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int,int>> q;
    q.push({i, j});
    grid[i][j] = 0;   // mark visited

    int area = 1;

    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                grid[nr][nc] == 1) {

                area++;
                grid[nr][nc] = 0;  // mark visited
                q.push({nr, nc});
            }
        }
    }
    return area;
}

int maxAreaOfIsland(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    int maxArea = 0;

    for(int i = 0; i <n; i++){
        for(int j = 0; j <m; j++){
            if(grid[i][j] == 1){
                maxArea = max(maxArea, bfsArea(grid, i, j));
            }
        }
    }
    return maxArea;
}
int main(){
    vector<vector<int>> grid = {
        {0,0,1,0,0},
        {1,1,1,0,0},
        {0,0,0,1,1}
    };
    int ans = maxAreaOfIsland(grid);
    cout << ans;
    return 0;
}