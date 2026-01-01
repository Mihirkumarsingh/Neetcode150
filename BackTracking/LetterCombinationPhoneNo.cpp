#include<iostream>
using namespace std;

void Combinations(string digits, vector<string>& output, string &temp, vector<string>& pad, int idx){
    if(idx == digits.size()){
        output.push_back(temp);
        return;
    }
    string value = pad[digits[idx] - '0'];
    for(int i = 0 ; i<value.size(); i++){
        temp.push_back(value[i]);
        Combinations(digits, output, temp, pad, idx + 1);
        temp.pop_back();
    }
}

vector<string> letterCombinations(string digits){
    if(digits.empty()){
        return {};
    }

    vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> output;
    string temp;
    Combinations(digits, output, temp, pad, 0);
    return output;
}

int main(){
    string inputs = "23";
    vector<string> ans = letterCombinations(inputs);
    for(auto s : ans){
        cout << s << " ";
    }
    return 0;
}