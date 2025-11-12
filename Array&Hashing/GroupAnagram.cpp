#include <iostream>
using namespace std;

vector<vector<string>> groupAnagram(vector<string>& strs){
    unordered_map<string, vector<string>> mp;
    vector<vector<string>> ans;
    for(int i = 0; i < strs.size(); i++){
        string s = strs[i];
        sort(s.begin(), s.end());
        mp[s].push_back(strs[i]);
    }

    for (auto i : mp){
        ans.push_back(i.second);
    }
    return ans;
}

int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagram(strs);
    for(auto i: result){
        for ( auto str : i){
            cout << str << " ";
        }
        cout << endl;
    }
    return 0 ;
}