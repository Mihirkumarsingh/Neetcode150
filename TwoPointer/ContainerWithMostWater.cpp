/*
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
In this case, the max area of water (blue section) the container can contain is 49.
*/

#include <iostream>
#include <algorithm>
using namespace std;
int mostWater(vector<int>& height){
    int n = height.size();
    int i = 0 , j = n-1;
    int maxArea = 0 ;
    int area = 0;
    while(i < j){
        area = min(height[j],height[i]) * (j-i);
        maxArea = max(maxArea, area);
        if(height[i] < height[j]){
            i++;
        }else{
            j--;
        }
    }
    return maxArea;
}
int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << mostWater(height)<<endl;
    return 0;
}