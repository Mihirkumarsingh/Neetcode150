#include<iostream>
using namespace std;

/*
Function: findCheapestPrice
---------------------------
n      : number of cities
flights: {from, to, price}
src    : starting city
dst    : destination city
k      : maximum allowed stops
*/

// Bellman-Ford Algo
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    for(int i =0; i <= k; i++){
        vector<int> temp = dist;

        for(auto flight: flights){
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];

            if(dist[from] == INT_MAX){
                continue;
            }
            temp[to] = min(temp[to], dist[from] + price);
        }

        dist = temp;
    }
    return dist[dst] == INT_MAX ? -1 : dist[dst];
}

int main(){
    int n = 4;
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600},
        {2, 3, 200}
    };

    int src = 0;
    int dst = 3;
    int k = 1;

    int result = findCheapestPrice(n, flights, src, dst, k);

    cout << "Cheapest Price = " << result << endl;
    return 0;
}