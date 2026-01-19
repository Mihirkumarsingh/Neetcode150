#include<iostream>
using namespace std;

int climbstairs(int n, vector<int>& dp){
    if(n == 0){
        return 1;
    }

    if(n == 1){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = climbstairs(n-1, dp) + climbstairs(n-2, dp);

    return dp[n];
}

int main(){
    int n = 5;
    vector<int> dp(n+1, -1);
    int ans = climbstairs(n, dp);
    cout << ans;
    return 0;
}