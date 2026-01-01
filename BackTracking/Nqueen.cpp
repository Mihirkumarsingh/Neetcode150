#include<iostream>
using namespace std;

bool is_valid(vector<string>& board, int row, int col){
    // check col
    for(int i=row;i>=0;--i)
        if(board[i][col] == 'Q') return false;
    // check left diagonal
    for(int i=row,j=col;i>=0&&j>=0;--i,--j)
        if(board[i][j] == 'Q') return false;
    //check right diagonal
    for(int i=row,j=col;i>=0&&j<board.size();--i,++j)
        if(board[i][j] == 'Q') return false;
    return true;
}

void dfs(vector<string>& board, int row, vector<vector<string>>& res){
    
    if(row == board.size()){
        res.push_back(board);
        return;
    }
    for(int i = 0; i <board.size(); i++){
        if(is_valid(board, row, i)){
            board[row][i] = 'Q';
            dfs(board, row+1, res);
            board[row][i] = '.';
        }
    }
}

void solveNQueens(int n){
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> res;
    dfs(board, 0, res);
    cout << "[";
    for(auto i:res){
        cout << "[";
        for(auto j: i){
            cout << j << " ";
        }
        cout << "]";
    }
    cout << "]";
}
int main(){
    int n = 4;
    solveNQueens(n);
    return 0;
}