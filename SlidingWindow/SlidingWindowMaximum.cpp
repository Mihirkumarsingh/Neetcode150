// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
#include<iostream>
#include<deque>
using namespace std;
vector<int> helper(vector<int>& nums, int k){
    vector<int> res;
    deque<int> mq;
    if(k==0){
        return res;
    }
    int n = nums.size();
    for(int i = 0 ; i< n; i++){
        int x = nums[i];

        if(i >= k){
            int leaving = nums[i-k];
            if(!mq.empty() && mq.front() == leaving){
                mq.pop_front();
            }
        }
        while(!mq.empty() && mq.back() < x){
            mq.pop_back();
        }
        mq.push_back(x);

        if(i >= k-1){
            res.push_back(mq.front());
        }
    }
    return res;
}
int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
}