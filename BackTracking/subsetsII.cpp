#include<iostream>
using namespace std;
/*

ind=0
path=[]

[]
├── [1]
│   ├── [1,2]
│   │   └── [1,2,2]
│   └── (skip duplicate 2)
├── [2]
│   └── [2,2]
└── (skip duplicate 2)


*/


void makeCombination(int idx, vector<int>& candidates, vector<int>&comb, vector<vector<int>>& res){
    res.push_back(comb);

    for(int i = idx; i < candidates.size(); i++){
        if(i > idx && candidates[i] == candidates[i-1]){
            continue;
        }

        comb.push_back(candidates[i]);
        makeCombination(i+1, candidates, comb, res);
        comb.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& candidates){
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> comb;
    makeCombination(0, candidates, comb, res);
    return res;
}

int main(){
    vector<int> candidates = {1,2,2};
    int target = 5;
    vector<vector<int>> res = subsetsWithDup(candidates);

    for (auto& comb : res) {
        cout << "[ ";
        for (int x : comb) {
            cout << x << " ";
        }
        cout << "]\n";
    }
    return 0;
}