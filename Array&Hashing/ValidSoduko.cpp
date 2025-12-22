#include <iostream>
#include <unordered_set>
using namespace std;
bool isValidSoduko(vector<vector<char>>& badBoard){
    int n = badBoard.size(); // row
    int m = badBoard[0].size(); // col
    vector<unordered_set<char>> row(9), col(9), box(9);
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m; j++){
            char c = badBoard[i][j];
            if(c == '.'){
                continue;
            }
            if(row[i].count(c)){
                return false;
            }else{
                row[i].insert(c);
            }

            if(col[j].count(c)){
                return false;
            }else{
                col[j].insert(c);
            }

            int boxIndex = (i/3)*3 + (j/3);
            if(box[boxIndex].count(c)){
                return false;
            }else{
                box[boxIndex].insert(c);
            }
        }
    }
    return true;
}

int main(){
    vector<vector<char>> badBoard = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','5','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    bool ans = isValidSoduko(badBoard);
    cout << ans << endl;
    return 0;
}
