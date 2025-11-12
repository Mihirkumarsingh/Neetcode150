/*
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by 
array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water are being trapped.
*/

#include<iostream>
using namespace std;
int trapRainWater(vector<int>& input){
    int n = input.size();
    vector<int> l_max(n), r_max(n);
    l_max[0] = input[0];
    r_max[n - 1] = input[n-1];
    for(int i = 1; i<n ; i++){
        l_max[i] = max(input[i], l_max[i - 1]);
    }

    for(int j = n-2; j>=0 ; j--){
        r_max[j] = max(input[j], r_max[j + 1]);
    }
    int trapped = 0;
    for(int k = 0; k<n ; k++){
        trapped += min(l_max[k], r_max[k]) - input[k];
    }
    return trapped;
}
int main(){
    vector<int> input = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trapRainWater(input) << endl;
    return 0;
}