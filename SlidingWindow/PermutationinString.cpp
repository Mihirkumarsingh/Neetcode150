/*
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
*/
#include<iostream>
using namespace std;
bool helper(string s1, string s2){
    vector<int> small(26, 0);
    vector<int> large(26, 0);
    for(auto i: s1){
        small[i - 'a']++;
    }
    for(int j=0; j < s1.length(); j++){
        large[s2[j] - 'a']++;
    }
    if(small == large){
        return true;
    }

    int k = 0; 
    int l = s1.length()-1;
    while(l < s2.length()){
        k++;
        l++;
        large[s2[k-1] - 'a']--;
        large[s2[l] - 'a']++;
        if(small == large){
            return true;
        }
        
    }
    return false;
}
int main(){
    string s1 = "ab";
    string s2 = "eidboaooo";
    cout << helper(s1, s2);
}