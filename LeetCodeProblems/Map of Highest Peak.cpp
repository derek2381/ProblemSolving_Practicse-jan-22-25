// Problem Link
// https://leetcode.com/problems/map-of-highest-peak/description/


// Source Code

class Solution {
public:

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> res(m, vector<int>(n, -1)); // -1 indicates unvisited cells
        queue<pair<int, int>> q;

        // Initialize the queue with all water cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    res[i][j] = 0; // Water cells have height 0
                    q.push({i, j});
                }
            }
        }

        // Perform BFS
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];

                // Check if the new position is within bounds and hasn't been visited
                if (x >= 0 && x < m && y >= 0 && y < n && res[x][y] == -1) {
                    res[x][y] = res[i][j] + 1; // Assign height
                    q.push({x, y});
                }
            }
        }

        return res;
    }
};