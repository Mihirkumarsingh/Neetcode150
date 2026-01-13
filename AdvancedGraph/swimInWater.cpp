#include<iostream>
#include<queue>
using namespace std;

int main(){
    vector<vector<int>> grid = {
        {0,1,2,3,4},
        {24,23,22,21,5},
        {12,13,14,15,16},
        {11,17,18,19,20},
        {10,9,8,7,6}
    };

    int n = grid.size();
    /*
    Time here is NOT travel time.
        Time = water level.

        Since water rises uniformly and movement is instant,
        the cost of a path is the MAX elevation encountered on that path.
    */

   vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
   /*
        Min-heap priority queue
        Each element = {time, row, col}

        We always expand the cell which can be reached
        with the LOWEST water level so far (Dijkstra rule).
    */

   priority_queue<
        vector<int>,
        vector<vector<int>>,
        greater<vector<int>>
    > pq;

    dist[0][0] = grid[0][0];
    pq.push({grid[0][0], 0, 0});

    // Direction vectors for 4-directional movement
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    while (!pq.empty()) {

        // Get the cell reachable with minimum water level so far
        auto curr = pq.top();
        pq.pop();

        int time = curr[0];  // current water level needed
        int r = curr[1];
        int c = curr[2];

        // If we've reached bottom-right, this is the minimum possible time
        if (r == n - 1 && c == n - 1) {
            cout << time << endl;
            return 0;
        }

        // Explore all 4 neighbors
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // Check boundaries
            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {

                /*
                    KEY LINE (MOST IMPORTANT PART):
                    --------------------------------

                    newTime = max(time, grid[nr][nc])

                    WHY?

                    - 'time' is the water level needed to reach current cell
                    - 'grid[nr][nc]' is the elevation of the next cell

                    You can enter the next cell ONLY when:
                        water level >= its elevation

                    So the earliest time you can reach (nr, nc) is:
                        max(current water level, next cell elevation)

                */
                int newTime = max(time, grid[nr][nc]);

                /*
                    If we found a way to reach (nr, nc)
                    with a LOWER required water level,
                    update it and push to the priority queue.
                */
                if (newTime < dist[nr][nc]) {
                    dist[nr][nc] = newTime;
                    pq.push({newTime, nr, nc});
                }
            }
        }
    }
    return 0;
}