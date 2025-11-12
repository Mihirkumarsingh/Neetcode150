// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]

#include <iostream>
using namespace std;
vector<int> TwoSum(vector<int>& nums, int target){
    int n = nums.size()-1;
    int i = 0 , j = n-1;
    while(i<j){
        if(nums[i]+nums[j] > target){
            j--;
        }else if (nums[i]+nums[j] < target){
            i++;
        }else{
            return {i,j};
        }
    }
    return {};
}
int main(){
    vector<int> Input = {2,7,11,15};
    int target = 9;
    vector<int> ans = TwoSum(Input, target);
    for(auto i:ans){
        cout << i << " " <<endl;
    }
    return 0;
}
