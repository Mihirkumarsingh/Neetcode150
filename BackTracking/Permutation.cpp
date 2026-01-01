#include<iostream>
using namespace std;
/*
                                 []
                         ┌─────────┼─────────┐
                       i=0        i=1        i=2
                        |          |          |
                      [1]        [2]        [3]
                 ┌──────┼──────┐ ┌──────┼──────┐ ┌──────┼──────┐
               i=1     i=2     X i=0     i=2     X i=0     i=1     X
                |       |        |       |        |       |
             [1,2]   [1,3]   [2,1]   [2,3]   [3,1]   [3,2]
               |       |        |       |        |       |
             i=2     i=1      i=2     i=0      i=1     i=0
               |       |        |       |        |       |
          [1,2,3] [1,3,2] [2,1,3] [2,3,1] [3,1,2] [3,2,1]
               ✓       ✓        ✓       ✓        ✓       ✓

*/
void recurPermute(vector<int>& ds, vector<int> &nums, vector<vector<int>> &ans, vector<int> &freq){
    if(ds.size() == nums.size()){
        ans.push_back(ds);
        return;
    }

    for(int i = 0; i < nums.size(); i++){
        if(!freq[i]){
            freq[i] = 1;
            ds.push_back(nums[i]);
            recurPermute(ds, nums, ans, freq);
            ds.pop_back();
            freq[i] = 0;
        }
    }
}
vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> freq(nums.size(), 0);
    recurPermute(ds, nums, ans, freq);
    return ans;
}
int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = permute(nums);
    for (auto& comb : res) {
        cout << "[ ";
        for (int x : comb) {
            cout << x << " ";
        }
        cout << "]\n";
    }
    return 0;
}