#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
bool CheckDuplicate(vector<int>& a){

    unordered_map<int, int> mp;
    for(int i = 0 ; i < a.size(); i++){
        mp[a[i]]++;
    }
    for(auto i: mp){
        if(i.second >1){
            return true;
        }
    }
    return false;
}
int main(){
    vector<int> Input = {1,2,3,4};
    cout << CheckDuplicate(Input);
    return 0;
}