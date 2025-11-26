// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9

#include<string>
#include<iostream>
#include<stack>
using namespace std;
int helper(vector<string> tokens){
    stack<int> st;
    for(auto ch: tokens){
        if (ch == "+") {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(a+b);
        }
        else if (ch == "-") {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b- a);
        }
        else if (ch == "*") {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(a * b);
        }
        else if(ch == "/"){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b / a);
        }
        else { 
            st.push(stoi(ch));
        }
    }
    return st.top();

}
int main(){
    vector<string> tokens = {"2","1","+","3","*"};
    int ans = helper(tokens);
    cout << ans<< endl;
    return 0;
}
