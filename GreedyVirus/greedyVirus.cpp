#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Directions for the 8 neighboring cells (up, down, left, right, and diagonals)
int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

// Function to check if a cell is within bounds
bool isValid(int x, int y, int M, int N) {
    return x >= 0 && x < M && y >= 0 && y < N;
}

// BFS function to find the minimum fudged data required
int minFudge(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> target) {
    int M = grid.size(), N = grid[0].size();
    vector<vector<int>> minFudge(M, vector<int>(N, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    minFudge[start.first][start.second] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto top = pq.top();
        int currentFudge = top.first;
        auto pos = top.second;
        pq.pop();
        int x = pos.first, y = pos.second;

        // If we reach the target, return the result
        if (x == target.first && y == target.second) {
            return currentFudge;
        }

        for (auto& dir : directions) {
            int newX = x + dir[0];
            int newY = y + dir[1];

            if (isValid(newX, newY, M, N)) {
                int requiredFudge = max(0, grid[x][y] + 1 - grid[newX][newY]);

                if (currentFudge + requiredFudge < minFudge[newX][newY]) {
                    minFudge[newX][newY] = currentFudge + requiredFudge;
                    pq.push({minFudge[newX][newY], {newX, newY}});
                }
            }
        }
    }

    return -1; // If the target is not reachable
}

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<int>> grid(M, vector<int>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    pair<int, int> start, target;
    cin >> start.first >> start.second;
    cin >> target.first >> target.second;

    // Convert to 0-based indexing
    start.first--; start.second--;
    target.first--; target.second--;

    cout << minFudge(grid, start, target) << endl;

    return 0;
}