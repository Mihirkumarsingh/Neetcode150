#include<iostream>
using namespace std;
/*
("", 0, 0)
│
├── "(" (1,0)
│   ├── "((" (2,0)
│   │   ├── "(((" (3,0)
│   │   │   └── "((()" (3,1)
│   │   │       └── "((())" (3,2)
│   │   │           └── "((()))" (3,3) ✅
│   │   └── "(()" (2,1)
│   │       ├── "(()(" (3,1)
│   │       │   └── "(()()" (3,2)
│   │       │       └── "(()())" (3,3) ✅
│   │       └── "(())" (2,2)
│   │           └── "(())(" (3,2)
│   │               └── "(())()" (3,3) ✅
│   └── "()" (1,1)
│       └── "()(" (2,1)
│           ├── "()((" (3,1)
│           │   └── "()(()" (3,2)
│           │       └── "()(())" (3,3) ✅
│           └── "()()" (2,2)
│               └── "()()(" (3,2)
│                   └── "()()()" (3,3) ✅
*/

void generate(int n, int l, int r, string tmp, vector<string>& ans){
    if(l == n && r == n){
        ans.push_back(tmp);
    }
    if(l<n){
        generate(n, l+1, r, tmp + '(' , ans);
    }
    if(r<l){
        generate(n, l, r+1, tmp + ')', ans);
    }
}

vector<string> generateParenthesis(int n){
    vector<string> ans;
    string tmp;
    generate(n, 0, 0, tmp, ans);
    return ans;
}

int main(){
    int n = 3;
    vector<string> ans = generateParenthesis(n);
    cout << "[";
    for(auto str: ans){
        cout << str << " ";
    }
    cout << "]";
    return 0;
}