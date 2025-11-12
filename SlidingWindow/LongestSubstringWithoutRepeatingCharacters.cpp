/*
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
#include <iostream>
#include <unordered_set>
using namespace std;
int LCSWRC(string s){
    unordered_set<char> substr;
    int i = 0, j = 0, n = s.length(); 
    int maxval = 0;
    while(j<n){
        if(substr.count(s[j]) == 0){
            substr.insert(s[j]);
            maxval = max(maxval, j-i+1);
        }else{
            while(substr.count(s[i] == 0)){
                substr.erase(s[i]);
                i++;
            }
            substr.insert(s[j]);
        }
        j++;
    }
    return maxval;
}
int main(){
    string s = "bbbbb";
    cout << LCSWRC(s);
}