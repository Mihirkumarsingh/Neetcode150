#include<iostream>
#include<queue>
using namespace std;
/*
small - max heap (stores smaller half)
large - min heap (stores larger half)
*/
void addNum(
    int num,
    priority_queue<int>& small,
    priority_queue<int, vector<int>, greater<int>>& large
){
    // Step 1: Insert into correct heap
    if (small.empty() || num <= small.top()) {
        small.push(num);
    } else {
        large.push(num);
    }

    // Step 2: Balance heaps
    if (small.size() > large.size() + 1) {
        large.push(small.top());
        small.pop();
    } else if (large.size() > small.size() + 1) {
        small.push(large.top());
        large.pop();
    }
}

double findMedian(
    priority_queue<int>& small,
    priority_queue<int, vector<int>, greater<int>>& large
) {
    if (small.size() > large.size()) {
        return small.top();
    } else if (large.size() > small.size()) {
        return large.top();
    } else {
        return (small.top() + large.top()) / 2.0;
    }
}
int main(){
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large; // min heap

    // Example usage
    addNum(1, small, large);
    cout << findMedian(small, large) << endl; // 1

    addNum(2, small, large);
    cout << findMedian(small, large) << endl; // 1.5

    addNum(3, small, large);
    cout << findMedian(small, large) << endl; // 2

    addNum(4, small, large);
    cout << findMedian(small, large) << endl; // 2.5

    return 0;
}