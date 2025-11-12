/*
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA"

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
*/

#include<iostream>
#include<unordered_map>
using namespace std;
int helper(string s, int k){
    int j = 0, i = 0;
    int n = s.length();
    int c =0;
    int maxlen=0;
    unordered_map<char, int> mp;
    while(j <n){
        mp[s[j]]++;
        c = max(c, mp[s[j]]);
        int curr_len = j-i+1;
        if(curr_len - c > k){
            mp[s[i]]--;
            i++;
        }
        curr_len = j -i +1;
        maxlen = max(maxlen, curr_len);
        j++;
    }
    return maxlen;
}
int main(){
    string s = "AABABBA";
    int k = 1;
    cout << helper(s, k);
    return 0;
}