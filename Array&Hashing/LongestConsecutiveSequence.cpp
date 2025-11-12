/* 
Input: nums = [100,4,200,1,3,2]
Output: 4
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Input: nums = [1,0,1,2]
Output: 3
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int LCS(vector<int>& nums){
    unordered_map<int, bool> mp;
    for(auto i: nums){
        mp[i] = true;
    }
    for(auto i: nums){
        if(mp.count(i-1)>0){
            mp[i]=false;
        }
    }
    int lg = 0;
    for(int x: nums){
        if(mp[x] == true){
            int cnt = 1;
            while(mp.count(x+cnt) > 0){
                cnt++;
            }
            lg = max(lg, cnt);
        }
    }
    return lg;
}

int main(){

    vector<int> nums = {100,4,200,1,3,2};
    cout << LCS(nums) << endl;
}