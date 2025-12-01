/*Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
*/

#include<iostream>
#include<stack>
using namespace std;
int helper(vector<int>& heights){
    int n = heights.size();
    stack<pair<int, int>> st;
    int area = 0;
    for(int i = 0 ; i<n ; i++){
        if(st.empty()){
            st.push({i, heights[i]});
        }else{
            if(heights[i] < st.top().second){
                int index = 0;
                while(!st.empty() && heights[i] < st.top().second){
                    area = max((i - st.top().first)*st.top().second,area);
                    index = st.top().first;
                    st.pop();
                }
                st.push({index, heights[i]});
            }else{
                st.push({i, heights[i]});
            }
        }
    }
    while(!st.empty()){
        area = max((n - st.top().first)*st.top().second, area);
        st.pop();
    }
    return area;
}

int main(){
    vector<int> heights = {2,1,5,6,2,3};
    int area = helper(heights);
    cout << area;
    return 0;
}
