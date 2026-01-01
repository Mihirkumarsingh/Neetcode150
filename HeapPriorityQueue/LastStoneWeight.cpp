#include<iostream>
#include<queue>
using namespace std;

int main() {
    vector<int> stones = {2, 7, 4, 1, 8, 1};

    // Default priority_queue = MAX heap
    priority_queue<int> pq;

    // Manually insert elements
    for (int stone : stones) {
        pq.push(stone);
    }

    while (pq.size() > 1) {
        int y = pq.top();  // largest
        pq.pop();

        int x = pq.top();  // second largest
        pq.pop();

        if (x != y) {
            pq.push(y - x);
        }
    }

    int result = pq.empty() ? 0 : pq.top();
    cout << result << endl;  // Output: 1

    return 0;
}