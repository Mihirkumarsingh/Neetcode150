/*
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
*/
#include<iostream>
using namespace std;
int helper(vector<int>& nums){
    int l = 0 ;
    int r = nums.size()-1;
    if(l<r){
        return nums[l];
    }
    while(l<r){
    int mid = l+(r-l)/2;
        if(nums[mid]>nums[r]){
            // minimum is in the right part
            l = mid+1;
        }else{
            r  =mid;
        }
    }
    return nums[l];
}
int main(){
    vector<int> nums = {3,4,5,1,2};
    int ans = helper(nums);
    cout << ans << endl;
    return 0;
}