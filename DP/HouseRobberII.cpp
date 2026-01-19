#include<iostream>
using namespace std;

int helper(const vector<int>& nums, int l, int r){
    int rob1 = 0, rob2 = 0;
    for(int i = l ; i <= r; i++){
        int temp = max(nums[i]+ rob1, rob2);
        rob1 = rob2; 
        rob2 = temp;
    }

    return rob2;
}

int rob(vector<int>& nums){
    int n = nums.size();
    if(n == 1){
        return nums[0];
    }

    int case1 = helper(nums, 1, n-1);
    int case2 = helper(nums, 0, n-2);

    return max(case1, case2);
}

int main(){
    vector<int> nums = {1, 2, 3, 1};
    int ans = rob(nums);
    cout << ans;
    return 0;
}