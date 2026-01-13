#include<iostream>
#include<queue>
using namespace std;
/*
JFK → [ATL, SFO]
ATL → [JFK, SFO]
SFO → [ATL]

JFK
 └─ ATL
     └─ JFK
         └─ SFO
             └─ ATL
                 └─ dfs(SFO) = null

Heap at SFO → empty ❌
itinerary = ["SFO"]

🔹 Returning to ATL
Heap empty ❌
➡️ Push
itinerary = ["SFO", "ATL"]

🔹 Returning to SFO
Heap empty ❌
➡️ Push
itinerary = ["SFO", "ATL", "SFO"]

🔹 Returning to JFK
Heap empty ❌
➡️ Push
itinerary = ["SFO", "ATL", "SFO", "JFK"]

🔹 Returning to ATL
Heap empty ❌
➡️ Push
itinerary = ["SFO", "ATL", "SFO", "JFK", "ATL"]

🔹 Returning to JFK
Heap empty ❌
➡️ Push
itinerary = ["SFO", "ATL", "SFO", "JFK", "ATL", "JFK"]
*/

unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
vector<string> itenary;

void dfs(string airport){
    while(!graph[airport].empty()){
        string next = graph[airport].top();
        graph[airport].pop();
        dfs(next);
    }

     // Add airport when no outgoing edges left
    itenary.push_back(airport);

}
int main() {
    vector<vector<string>> tickets = {
        {"JFK","SFO"},
        {"JFK","ATL"},
        {"SFO","ATL"},
        {"ATL","JFK"},
        {"ATL","SFO"}
    };

    for (auto &t : tickets) {
        graph[t[0]].push(t[1]);
    }

    // Start DFS from JFK
    dfs("JFK");

    // Reverse result
    reverse(itenary.begin(), itenary.end());

    // Print result
    for (auto &airport : itenary) {
        cout << airport << " ";
    }
    cout << endl;

    return 0;
}

