#include<iostream>
#include<stack>
using namespace std;
vector<int> helper(vector<int>& temperatures){
    stack<pair<int,int>> st;
    int n = temperatures.size();
    vector<int> ans(n, 0);
    for(int i = 0; i <n; i++){
        int t = temperatures[i];
        if(st.empty()){
            st.push({t, i});
        }else{
            if(t > st.top().first){
                while(!st.empty() && t > st.top().first){
                    ans[st.top().second] = i - st.top().second;
                    st.pop();
                }
                st.push({t, i});
            }else{
                st.push({t, i});
            }
        }
    }
    return ans;
}
int main(){
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> ot = helper(temperatures);
    for(auto i : ot){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}