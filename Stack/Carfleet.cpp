// Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
// Output: 3

#include<iostream>
#include<stack>
using namespace std;

int helper(vector<int>&position, vector<int>& speed, int target){
    unordered_map<int, int> mp;
    stack<double> st;
    int count =0;
    int n = position.size();
    for(int i =0 ; i<n ; i++){
        mp[position[i]] = speed[i];
    }
    sort(position.begin(), position.end());
    
    for(int j = n-1; j>=0; j--){
        double time = (target-position[j])/mp[position[j]];
        if(st.empty()){
            st.push(time);
            count++;
        }else{
            if(time > st.top()){
                st.push(time);
                count++;
            }
        }
    }
    return count;

}
int main(){
    int target = 12;
    vector<int> position = {10,8,0,5,3};
    vector<int> speed = {2,4,1,1,3};
    int ans = helper(position, speed, target);
    cout << ans;
    return 0;
}