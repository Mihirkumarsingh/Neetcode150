// Input: s = "A man, a plan, a canal: Panama" 
// Output: true

#include <iostream>
using namespace std;

bool CheckPalidrome(string s){
    vector<char> check;
    for(auto i: s){
        if(iswalnum(i)){
            check.push_back(tolower(i));
        }
    }
    int j = 0, k = check.size()-1;
    while(j < k){
        if(check[j] != check[k]){
            return false;
        }
        j++;
        k--;
    }
    return true;
}
int main(){
    string s = "A man, a plan, a canal: Panama";
    cout << CheckPalidrome(s)<< endl;
    return 0;
}