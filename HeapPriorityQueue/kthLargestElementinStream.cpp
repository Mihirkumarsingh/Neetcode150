#include<iostream>
#include<queue>
using namespace std;
int addElement(priority_queue<int, vector<int>, greater<int>>& pq,
               int k,
               int val) {

    pq.push(val);

    // Keep heap size <= k
    if (pq.size() > k) {
        pq.pop();
    }

    return pq.top();  // kth largest
}
int main(){
     vector<int> nums = {4, 5, 8, 2};
    int k = 3;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int num : nums) {
        addElement(pq, k, num);
    }

    cout << addElement(pq, k, 3) << endl;    // 4
    cout << addElement(pq, k, 5) << endl;    // 5
    cout << addElement(pq, k, 10) << endl;   // 5
    cout << addElement(pq, k, 9) << endl;    // 8
    cout << addElement(pq, k, 4) << endl;    // 8

    return 0;
}