#include<iostream>
using namespace std;
/*
------------------------------------------------------------
SUBSETS USING BACKTRACKING (INCLUDE / EXCLUDE PATTERN)

For every element, we make TWO decisions:
1) Include nums[index]
2) Exclude nums[index]

This forms a binary recursion tree of height = nums.size()
Total subsets = 2^n

Key ideas:
- index tells us WHICH element we are deciding on
- subset stores CURRENT choices
- res stores ALL valid subsets
------------------------------------------------------------


                     []
              /                 \
          [1]                   []
        /      \             /       \
     [1,2]     [1]        [2]         []
     /   \     /   \      /   \        /   \
[1,2,2] [1,2] [1,2] [1] [2,2] [2]    [2]   []

*/

void createSubset(vector<int>& nums, int index, vector<vector<int>>& res, vector<int>& subset){
    /*
    --------------------------------------------------------
    BASE CASE:
    If index reaches nums.size(), it means we have decided
    INCLUDE / EXCLUDE for all elements.
    Current subset is COMPLETE and VALID.
    --------------------------------------------------------
    */
   if(index == nums.size()){
    res.push_back(subset);
    return;
   }
   // CHOICE 1: INCLUDE nums[index]
   subset.push_back(nums[index]);
   // Move to next index (next decision)
   createSubset(nums, index + 1, res, subset);

    /*
    --------------------------------------------------------
    BACKTRACK:
    Undo the INCLUDE decision so that we can try EXCLUDE.
    This restores subset to its previous state.
    --------------------------------------------------------
    */
   subset.pop_back();

    /*
    --------------------------------------------------------
    CHOICE 2: EXCLUDE nums[index]
    We do NOT add nums[index] to subset.
    Simply move to the next index.
    --------------------------------------------------------
    */
   createSubset(nums, index + 1, res, subset);
}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> res;
    vector<int> subset;
    createSubset(nums, 0, res, subset);
    cout << "All subsets:\n";
    for (auto& s : res) {
        cout << "[ ";
        for (int x : s) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}