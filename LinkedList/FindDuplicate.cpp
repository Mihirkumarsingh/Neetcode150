/*
You must solve the problem without modifying the array nums 
and using only constant extra space
*/
#include<iostream>
using namespace std;
int helper(vector<int>& nums){
    int slow = nums[0];
    int fast = nums[0];
    while(true){
        slow = nums[slow];
        fast = nums[nums[fast]];
        if(slow == fast){
            break;
        }
    }
    slow = nums[0];
    while(fast != slow){
        slow = nums[slow];
        fast = nums[fast];
    }
    return fast;
}
int main(){
    vector<int> nums = {1,3,4,3,2};
    int ans = helper(nums);
    cout << ans; 
    return 0;
}