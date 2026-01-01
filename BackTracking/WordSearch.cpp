#include<iostream>
using namespace std;
/*
dfs(0,0, idx=0/6) → need 'A'
│
├── dfs(0,-1, idx=1/6) ❌ out of bounds
│
├── dfs(0,1, idx=1/6) → need 'B' ✅
│   │
│   ├── dfs(0,0, idx=2/6) ❌ visited
│   │
│   ├── dfs(0,2, idx=2/6) → need 'C' ✅
│   │   │
│   │   ├── dfs(0,1, idx=3/6) ❌ visited
│   │   │
│   │   ├── dfs(0,3, idx=3/6) ❌ 'E' != 'C'
│   │   │
│   │   ├── dfs(1,2, idx=3/6) → need 'C' ✅
│   │   │   │
│   │   │   ├── dfs(1,1, idx=4/6) ❌ 'F' != 'E'
│   │   │   │
│   │   │   ├── dfs(1,3, idx=4/6) ❌ 'S' != 'E'
│   │   │   │
│   │   │   ├── dfs(2,2, idx=4/6) → need 'E' ✅
│   │   │   │   │
│   │   │   │   ├── dfs(2,1, idx=5/6) → need 'D' ✅
│   │   │   │   │   │
│   │   │   │   │   ├── dfs(any, any, idx=6/6) 🎯 BASE CASE → TRUE
│   │   │   │   │
│   │   │   │   ├── dfs(2,3, idx=5/6) ❌ 'E' != 'D'
│   │   │   │   ├── dfs(3,2, idx=5/6) ❌ out of bounds
│   │   │   │   └── dfs(1,2, idx=5/6) ❌ visited
│   │   │   │
│   │   │   └── dfs(0,2, idx=4/6) ❌ visited
│   │   │
│   │   └── dfs(-1,2, idx=3/6) ❌ out of bounds
│   │
│   └── dfs(1,1, idx=2/6) ❌ 'F' != 'C'
│
├── dfs(1,0, idx=1/6) ❌ 'S' != 'B'
│
└── dfs(-1,0, idx=1/6) ❌ out of bounds

Stack Grows
===========
dfs(0,0,0/6)
 dfs(0,1,1/6)
  dfs(0,2,2/6)
   dfs(1,2,3/6)
    dfs(2,2,4/6)
     dfs(2,1,5/6)
      dfs(_,_,6/6) → true


Stack UNWINDS
=============

visited[i][j] = 0;
return true;

=============
dfs(2,1,5/6) → true
dfs(2,2,4/6) → true
dfs(1,2,3/6) → true
dfs(0,2,2/6) → true
dfs(0,1,1/6) → true
dfs(0,0,0/6) → true

*/
bool dfs(vector<vector<char>> &board, vector<vector<int>> &visited, string &word, int i, int j, int idx){
    if(idx == word.size()){
        return true;
    }
    if(i<0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] == 1 || board[i][j] != word[idx]){
        return false;
    }

    // Marking Visited
    visited[i][j] = 1;

    bool ls = dfs(board, visited, word, i, j-1, idx+1);
    bool rs = dfs(board, visited, word, i, j+1, idx+1);
    bool ds = dfs(board, visited, word, i+1, j, idx+1);
    bool us = dfs(board, visited, word, i-1, j, idx+1);

    visited[i][j] = 0;

    return ls | rs | ds | us;
}

bool exist(vector<vector<char>>& board, string word){
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> visited(n, vector<int>(m,0));
    for(int i = 0; i <n; i++){
        for(int j = 0; j <m ; j++){
            if(visited[i][j] == 0 && word[0] == board[i][j]){
                if(dfs(board, visited, word, i, j, 0 )){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";
    cout << exist(board, word);
    return 0;
}