// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
#include<iostream>
#include<unordered_map>
using namespace std;
string helper(string s, string t){
    unordered_map<char, int> mp1;
    unordered_map<char, int> mp2;
    for(auto i : t){
        mp1[i]++;
    }
    int j = 0;
    int k = 0;
    int n = s.length();
    int letterCount;
    int check = INT_MAX;
    string result;
    while(k<n){
        char ch = s[k];
        if(mp1.find(ch) != mp1.end()){
            mp2[ch]++;
            if(mp2[ch] <= mp1[ch]){
                letterCount++;
            }
        }
        if(letterCount >= t.length()){
            while(mp1.find(s[j]) == mp1.end() || mp2[s[j]] > mp1[s[j]]){
                mp2[s[j]]--;
                j++;
            }
            if(k-j+1 < check){
                result = s.substr(j, k-j+1);
            }
        }
        k++;
    }
    return result;
}
int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string ans = helper(s, t);
    cout << ans;

}
