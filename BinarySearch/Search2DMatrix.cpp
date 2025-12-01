/*
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*/

#include<iostream>
using namespace std;
bool helper(vector<vector<int>> matrix, int target){
    for(int i = 0 ; i < matrix.size(); i++){
        int l = 0, r = matrix[i].size() - 1;
        while(l <= r){
            int m = (l+r)/2;
            if(matrix[i][m] == target){
                return true;
            }else if (matrix[i][m] > target){
                r = m - 1;
            }else if (matrix[i][m] < target){
                l = m + 1;
            }
        }
    }
    return false;
}
int main(){
    vector<vector<int>> matrix =  {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    int target = 3;
    bool ans = helper(matrix, target);
    cout << ans << endl;
    return 0;
}