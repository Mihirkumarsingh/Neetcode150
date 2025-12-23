// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
#include<iostream>
#include<deque>
using namespace std;
vector<int> helper(vector<int>& nums, int k){
    int n = nums.size();
    vector<int> output(n - k + 1);
    deque<int> q;
    int l = 0, r = 0;

    while (r < n) {
        while (!q.empty() && nums[q.back()] < nums[r]) {
            q.pop_back();
        }
        q.push_back(r);

        if (l > q.front()) {
            q.pop_front();
        }

        if ((r + 1) >= k) {
            output[l] = nums[q.front()];
            l++;
        }
        r++;
    }

    return output;
}
int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
}