#include<iostream>
#include<queue>
using namespace std;
int orangeRotting(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited = grid;
    queue<pair<int,int>> q;
    int countFreshOrange = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j <m; j++){
            if(visited[i][j] == 2){
                q.push({i,j});
            }
            if(visited[i][j] == 1){
                countFreshOrange++;
            }
        }
    }

    if(countFreshOrange == 0){
        return 0;
    }
    if(q.empty()){
        return -1;
    }

    int minutes = -1;
    vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,-1}, {0,1}};
    while(!q.empty()){
        int size = q.size();
        while(size--){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k = 0; k<dirs.size(); k++){
                int i = x + dirs[k].first;
                int j = y + dirs[k].second;
                if (i >= 0 && i < n && j >= 0 && j < m && visited[i][j] == 1) {
                    visited[i][j] = 2;
                    countFreshOrange--;
                    q.push({i,j});
                }
            }
        }
        minutes++;
    }

    if (countFreshOrange == 0){
            return minutes;
        }else{
            return -1;
        }
}
int main(){
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };
    cout << orangeRotting(grid);
    return 0;
}