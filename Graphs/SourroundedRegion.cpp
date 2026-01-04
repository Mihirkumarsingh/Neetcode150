#include<iostream>
using namespace std;

void check(vector<vector<char>>& board, int i, int j){

    int row = board.size();
    int col = board[0].size();

    if(i < 0 || i >= row || j < 0 || j >= col){
        return;
    }

    // mark as safe
    if (board[i][j] != 'O'){
        return;
    }

    // explore 4 directions
    board[i][j] = '1';

    check(board, i + 1, j);
    check(board, i - 1, j);
    check(board, i, j + 1);
    check(board, i, j - 1);
}

void solve(vector<vector<char>>& board){
    int row = board.size();
    int col = board[0].size();

    // first & last column
    for(int i = 0; i < row; i ++){
        check(board, i , 0);
        check(board, i, col - 1);
    }

    // first & last row
    for (int j = 0; j < col; j++) {
        check(board, 0, j);
        check(board, row - 1, j);
    }


    // final conversion
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == 'O')
                board[i][j] = 'X';   // surrounded
            else if (board[i][j] == '1')
                board[i][j] = 'O';   // safe
        }
    }
}
int main(){
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    solve(board);

    // print output
    for (auto &row : board) {
        for (auto &cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}