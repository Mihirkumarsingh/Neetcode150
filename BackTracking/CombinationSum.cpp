#include <iostream>
using namespace std;

/*
                                   [] | 7
          ----------------------------------------------------------------
          |                |                 |                            |
       [2] | 5           [3] | 4           [6] | 1                     [7] | 0 ✅
          |
          |
     ------------------------------
     |            |            |
 [2,2] | 3     [2,3] | 2    [2,6] | -1 ❌
     |
     |
  -------------------------
  |            |         |
[2,2,2] | 1  [2,2,3] | 0 ✅  [2,2,6] | -3 ❌
  |
  |
  ❌ (all further choices < 0)

*/

void makeCombination(vector<int>& candidates, int target, int idx, vector<int>& comb, int total, vector<vector<int>>& res){
    if(total == target){
        res.push_back(comb);
        return;
    }
    if(total > target || idx >= candidates.size()){
        return;
    }
    comb.push_back(candidates[idx]);
    makeCombination(candidates, target, idx, comb, total + candidates[idx], res);
    comb.pop_back();
    makeCombination(candidates, target, idx+1, comb, total, res);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    vector<vector<int>> res;
    vector<int> comb;
    makeCombination(candidates, target, 0, comb, 0 , res);
    return res;
}

int main(){
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> res = combinationSum(candidates, target);
    
    for (auto& comb : res) {
        cout << "[ ";
        for (int x : comb) {
            cout << x << " ";
        }
        cout << "]\n";
    }
    return 0;
}