#include<iostream>
using namespace std;

vector<int> productExceptItself(vector<int>& nums){
    int n = nums.size();
    vector<int> post(n), pre(n), ans(n);
    int total1=1, total2=1;
    for(int i = 0; i < n; i++){
        total1 = total1 * nums[i];
        pre[i] = total1;
    }

    for(int j = n-1; j >= 0; j--){
        total2 = total2 * nums[j];
        post[j] = total2;
    }

    for(int k = 0; k < n; k++){
        if(k==0){
            ans[k] = post[k+1];
        }else if(k == n-1){
            ans[k] = pre[k-1];
        }else{
            ans[k] = pre[k-1]*post[k+1];
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,3,4};
    vector<int> a = productExceptItself(nums);
    for(auto i: a){
        cout << i << " ";
    }
    return 0;
}