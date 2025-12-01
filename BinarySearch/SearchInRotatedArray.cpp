/*
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/
#include<iostream>
using namespace std;

int helper(vector<int>& nums, int target){
    int l = 0;
    int r = nums.size()-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(nums[mid] == target){
            return mid;
        }
        // mid is in left half 
        if(nums[mid]>= nums[l]){
            // is target in first half of left half ?
            if(target >= nums[l] && target < nums[mid]){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        // right half
        }else{
            // is target in 1st half of right half ?
            if(target <= nums[r] && nums[mid] < target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
    }
    return -1;
}
int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int ans = helper(nums, target);
    cout << ans << endl;
    return 0;
}