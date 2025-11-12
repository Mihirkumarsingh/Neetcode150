// Input: nums = [-1,0,1,2,-1,-4]
//  Output: [[-1,-1,2],[-1,0,1]]
#include <iostream>
using namespace std;
vector<vector<int>> threeSum(vector<int>& v){
    sort(v.begin(), v.end());
    vector<vector<int>> ans;
    int n = v.size();
    for(int i = 0 ; i<n; i++){
        int j = i+1;
        int k = n-1;
        while(j<k){
            if(v[i]+v[j]+v[k] < 0){
                j++;
            }else if(v[i]+v[j]+v[k] > 0){
                k--;
            }else{
                ans.push_back({v[i],v[j],v[k]});
                j++;
                k--;
            }
        }
    }
    return ans;
}
int main(){
   vector<int> v = {-1,0,1,2,-1,-4};
   vector<vector<int>> a = threeSum(v);
   for(auto i: a){
    for( auto j : i ){
        cout << j << ", ";
    }
    cout <<"\n";
   }
   return 0;

}
