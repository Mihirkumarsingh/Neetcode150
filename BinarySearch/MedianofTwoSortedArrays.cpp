#include<iostream>
using namespace std;

double helper(vector<int>& nums1, vector<int>& nums2){
int n1 = nums1.size();
int n2 = nums2.size();

if(n1 > n2){
    return helper(nums2, nums1);
}
int l = 0, r = n1;
while(l <= r){
    int cut1 = (l+r)/2;
    int cut2 = (n1+n2+1)/2 - cut1;
    int left1 = (cut1 > 0)?nums1[cut1-1]: INT_MIN;
    int left2 = (cut2 > 0)?nums2[cut2-1]: INT_MIN;

    int right1 = (cut1 < n1)?nums1[cut1]: INT_MAX;
    int right2 = (cut2 < n2)?nums2[cut2]: INT_MAX;

    if(left1 <= right2 && left2 <= right1){
        if ((n1+n2)%2 == 0){
            return (max(left1, left2) + min(right1, right2))/2.0;
        }else{
            return max(left1, left2);
        }
    }else if(left1 > right2){
        r = cut1 - 1;
    }else{
        l = cut1 + 1;
    }

}
return 0.0;
}
int main(){
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    double ans = helper(nums1, nums2);
    cout << ans;
    return 0;
}