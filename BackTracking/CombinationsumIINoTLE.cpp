#include<iostream>
#include<set>
using namespace std;

/*
Input: candidates = [2,1,2,2,5], target = 5
Output: 
[
[1,2,2],
[5]
]

                                      [] (idx=0, target=5)
        ---------------------------------------------------------------------------------
        |                |                 |                   |
     i=0:1            i=1:2              i=2:2               i=3:5
     pick             pick               SKIP                pick
                                       (dup sibling)
        |                |                                   |
 [1] (idx=1,t=4)    [2] (idx=2,t=3)                       [5] (idx=4,t=0) ✅
        |                |
   -----------------     -----------------
   |        |      |     |        |
 i=1:2   i=2:2   i=3:5  i=2:2   i=3:5
 pick    SKIP    BREAK  pick    BREAK
         (dup)           (>4)          (>3)
   |
[1,2] (idx=2,t=2)
   |
-----------------
|        |
i=2:2   i=3:5
pick    BREAK
   |
[1,2,2] (idx=3,t=0) ✅

*/

// TLE O(2^n) 
// but due to exclusions and non dup recurssive calls are small


void makeCombination(vector<int>& candidates, int target, int idx, vector<int>& comb, vector<vector<int>>& res){
    if(target == 0){
        res.push_back(comb);
        return;
    }

    for(int i = idx; i < candidates.size(); i++){
        if(i > idx && candidates[i] == candidates[i-1]){
            continue;
        }
        if(candidates[i] > target){
            break;
        }

        comb.push_back(candidates[i]);
        makeCombination(candidates, target - candidates[i], i+1, comb, res);
        comb.pop_back();
    }
}

vector<vector<int>> combinationSumOnce(vector<int>& candidates, int target){
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> comb;
    makeCombination(candidates, target, 0, comb, res);
    return res;
}

int main(){
    vector<int> candidates = {2,5,2,1,2};
    int target = 5;
    vector<vector<int>> res = combinationSumOnce(candidates, target);

    for (auto& comb : res) {
        cout << "[ ";
        for (int x : comb) {
            cout << x << " ";
        }
        cout << "]\n";
    }
    return 0;
}