#include<iostream>
#include<queue>
using namespace std;

void islandAndTreasure(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    for(int i = 0; i <n; i++){
        for(int j= 0; j <m; j++){
            if(grid[i][j] == 0){
                q.push({i,j});
            }
        }
    }

    vector<int> rItr = {-1, 1, 0, 0};
    vector<int> cItr = {0, 0, -1, 1};

    while(!q.empty()){
        int ii=q.front().first;
        int jj=q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nr = ii + rItr[dir];
            int nc = jj + cItr[dir];

            if(nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                grid[nr][nc] == INT_MAX){
                    grid[nr][nc] = grid[ii][jj] + 1;
                    q.push({nr, nc});
                }
        }

    }
}

int main(){
    vector<vector<int>> grid = {
        {INT_MAX, -1, 0, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, -1},
        {INT_MAX, -1, INT_MAX, -1},
        {0, -1, INT_MAX, INT_MAX}
    };

    islandAndTreasure(grid);
    // Print output
    for(auto &row : grid){
        for(auto &val : row){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}