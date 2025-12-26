#include<iostream>
#include<set>
using namespace std;

/*
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

                                     []
                    -------------------------------------------------
                    |                                               |
                 include 1                                       exclude 1
                    |                                               |
                [1]                                                 []
         --------------------                              --------------------
         |                  |                              |                  |
     include 2            exclude 2                     include 2           exclude 2
         |                  |                              |                  |
     [1,2]                [1]                           [2]                  []
   -----------          -----------                  -----------          -----------
   |         |          |         |                  |         |          |         |
 inc 2     exc 2      inc 2     exc 2              inc 2     exc 2      inc 2     exc 2
   |         |          |         |                  |         |          |         |
[1,2,2]  [1,2]     [1,2]      [1]              [2,2]     [2]          [2]        []
   .
   .
   .  (continues FULLY, even when sum > target)

*/

// TLE O(n* 2^n) 
// why ?
// Problem 1: Duplicate generation


void makeCombination(vector<int>& candidates, int target, int idx, vector<int>& comb, int total, set<vector<int>>& res){
    if(total == target){
        res.insert(comb);
        return;
    }
    if(total > target || idx >= candidates.size()){
        return;
    }
    comb.push_back(candidates[idx]);
    makeCombination(candidates, target, idx+1, comb, total + candidates[idx], res);
    comb.pop_back();
    makeCombination(candidates, target, idx+1, comb, total, res);
}

set<vector<int>> combinationSumOnce(vector<int>& candidates, int target){
    sort(candidates.begin(), candidates.end());
    set<vector<int>> res;
    vector<int> comb;
    makeCombination(candidates, target, 0, comb, 0, res);
    return res;
}

int main(){
    vector<int> candidates = {2,5,2,1,2};
    int target = 5;
    set<vector<int>> res = combinationSumOnce(candidates, target);

    for (auto& comb : res) {
        cout << "[ ";
        for (int x : comb) {
            cout << x << " ";
        }
        cout << "]\n";
    }
    return 0;
}