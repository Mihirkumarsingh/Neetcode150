#include<iostream>
using namespace std;
/*
func(index=0, path=[])
│
├── i=0 → s[0..0] = "a" ✔ palindrome
│   │
│   └── func(index=1, path=["a"])
│       │
│       ├── i=1 → s[1..1] = "a" ✔
│       │   │
│       │   └── func(index=2, path=["a","a"])
│       │       │
│       │       ├── i=2 → s[2..2] = "b" ✔
│       │       │   │
│       │       │   └── func(index=3, path=["a","a","b"])
│       │       │       │
│       │       │       └── index == s.size()
│       │       │           ✅ STORE ["a","a","b"]
│       │       │
│       │       └── BACKTRACK → pop "b"
│       │
│       └── BACKTRACK → pop "a"
│
├── i=1 → s[0..1] = "aa" ✔
│   │
│   └── func(index=2, path=["aa"])
│       │
│       ├── i=2 → s[2..2] = "b" ✔
│       │   │
│       │   └── func(index=3, path=["aa","b"])
│       │       │
│       │       └── index == s.size()
│       │           ✅ STORE ["aa","b"]
│       │
│       └── BACKTRACK → pop "b"
│
└── i=2 → s[0..2] = "aab" ❌ not palindrome
*/
bool isPalindrome(string s, int start, int end){
    while(start <= end){
        if (s[start] != s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void func(int idx, string s, vector<string>& path, vector<vector<string>>& res){
    if(idx == s.size()){
        res.push_back(path);
        return;
    }

    for(int i = idx ; i < s.size(); i++){
        if(isPalindrome(s, idx, i)){
            path.push_back(s.substr(idx, i-idx+1));
            func(i+1, s, path, res);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s){
    vector<vector<string>> res;
    vector<string> path;
    func(0, s, path, res);
    return res;
}

int main(){
    string s = "aab";
    vector<vector<string>> ans = partition(s);
    for(auto s: ans){
        cout << "[";
        for( auto i : s){
            cout << i << " ";
        }
        cout << "]";
    }
    return 0;
}