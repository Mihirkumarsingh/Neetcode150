#include<iostream>
using namespace std;

/*
solve(0)
├── solve(1)
│   ├── solve(2)
│   │   ├── solve(3)  -> 0   (base case)
│   │   └── solve(4)  -> 0   (base case)
│   └── solve(3)      -> 0   (base case)
└── solve(2)
    ├── solve(3)      -> 0   (base case)
    └── solve(4)      -> 0   (base case)
*/
int solveTLE(int i, vector<int>& cost){
    if(i >= cost.size()){
        return 0;
    }
    return cost[i] + min(
        solveTLE(i+1, cost),
        solveTLE(i+2, cost)
    );
}

int minCostClimbingStairsTLE(vector<int>& cost) {
    return min(solveTLE(0, cost), solveTLE(1, cost));
}
/*
===========================
TLE
===========================
*/

int solveTD(int i, vector<int>& cost, vector<int>& dp){
    if(i>= cost.size()){
        return 0;
    }

    if(dp[i] != -1){
        return dp[i];
    }

    dp[i] = cost[i] + min(
        solveTD(i + 1, cost, dp),
        solveTD(i + 2, cost, dp)
    );
    return dp[i];
}

int minCostClimbingStairsTD(vector<int>& cost){
    int n = cost.size();
    vector<int> dp(n, -1);
    return min(solveTD(0, cost, dp), solveTD(1, cost, dp));
}
/*
===========================
TOP DOWN
===========================
*/

int minCostClimbingStairsBU(vector<int>& cost){
    int n = cost.size();
    vector<int> dp(n+1, 0);

    // dp[0] = 0  (start before step 0)
    // dp[1] = 0  (start before step 1)

    for(int i = 2; i <= n; i++){
        dp[i] = min(
            dp[i-1] + cost[i-1],
            dp[i-2] + cost[i-2]
        );
    }

    return dp[n];
}


int main(){
    vector<int> cost = {10, 15, 20};
    cout << "Minimum Cost TLE= " << minCostClimbingStairsTLE(cost) << endl;

    cout << "Minimum Cost TOP Down= " << minCostClimbingStairsTD(cost) << endl;

    cout << "Minimum Cost bottom up= " << minCostClimbingStairsBU(cost) << endl;

    return 0;



}