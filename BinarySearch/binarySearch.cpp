/*
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
*/
#include<iostream>
using namespace std;
int helper(vector<int>& nums, int target){
    int l = 0;
    int r = nums.size()-1;
    while(l<=r){
        int m = (l+r)/2;
        if(nums[m] == target){
            return m;
        }else if(nums[m]>target){
            r = m-1;
        }else if(nums[m]<target){
            l = m+1;
        }
    }
    return -1;
}
int main(){
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    int ans = helper(nums, target);
    cout << ans;
    return 0;
}