/*
Input: prices = [7,1,5,3,6,4]
Output: 5
*/

#include<iostream>
using namespace std;
int buyAndSellStock(vector<int>& prices){
    int buy = prices[0];
    int n = prices.size();
    int m = 0;
    for(int i = 0  ;i <n; i++){
        if(prices[i]< buy){
            buy = prices[i];
        }else if(prices[i] > buy){
            m = max(m, (prices[i]-buy));
        }
    }
    return m;
}
int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout << buyAndSellStock(prices)<< endl;
    return 0;
}