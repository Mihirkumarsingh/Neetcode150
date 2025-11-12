#include <iostream>
#include <queue>
using namespace std;
vector<int> TopKFrequent(vector<int>& ele, int k){
    unordered_map<int, int> mp;
    priority_queue<pair<int, int>> pq;
    vector<int> ans;
    for(int i = 0; i < ele.size(); i++){
        mp[ele[i]]++;
    }
    for(auto i : mp){
        pq.push({i.second, i.first});
    }

    while(!pq.empty() && k--){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;


}
int main(){
    vector<int> ele = {1,1,1,2,2,3};
    int k = 2;
    vector<int> a = TopKFrequent(ele, k);
    for(auto i: a){
        cout << i << " ";
    }
    return 0;
}