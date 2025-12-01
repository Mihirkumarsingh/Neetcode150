/*
Input: piles = [3,6,7,11], h = 8
Output: 4
*/
#include<iostream>
using namespace std;
int TimeTaken(vector<int>& piles, int mid){
    int t = 0;
    for(auto i: piles){

        t += ceil((double)i/(double)mid);
    }
    return t;
}

int helper(vector<int>& piles, int h){
    int l = 1; 
    int r = *max_element(piles.begin(), piles.end());
    while(l<=r){
        int mid = (l+r)/2;
        int timeTakenToEat = TimeTaken(piles, mid);
        if(timeTakenToEat <= h){
            r = mid -1;
        }else{
            l = mid+1;
        }
    }
    return l;
}

int main(){
    vector<int> piles = {3,6,7,11};
    int h = 8;
    int ans = helper(piles, h);
    cout << ans<<endl;
    return 0;
}