#include<iostream>
using namespace std;
int rob(vector<int>& nums){
    int rob1 = 0; // max money we can rob till house before that (i-2)
    int rob2 = 0; // max money we can rob till previous house (i-1)

    /*
    When you are at house i:
    If you rob it → money = nums[i] + rob1
    If you skip it → money = rob2
    */

   for(int i = 0; i < nums.size(); i++){
    int temp = max(nums[i]+ rob1, rob2);
    rob1 = rob2;
    rob2 = temp;
   }
   return rob2;
}

int main(){
    vector<int> nums = {2, 7, 9, 3, 1};
    int moneyrobbed = rob(nums);
    cout << moneyrobbed;
    return 0;
}