#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mp;
        int flag = 1;

        if (s.size() != t.size()) {
            flag = 0;
            return flag;
        }

        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            mp[t[i]]--;
        }

        for (auto i : mp) {
            if (i.second != 0) {
                flag = 0;
                return flag;
            }
        }

        return flag;
    }
};

int main() {
    Solution obj;
    string s = "listen";
    string t = "silent";

    if (obj.isAnagram(s, t))
        cout << "The strings are anagrams." << endl;
    return 0;
}
