#include <bits/stdc++.h>

using namespace std;

const int ROWS = 3;
const int COLS = 3;
const vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

string serializeGrid(const vector<vector<int>>& grid) {
    string serialized;
    for (const auto& row : grid) {
        for (int val : row) {
            serialized += to_string(val);
        }
    }
    return serialized;
}
bool isValid(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS);
}

// Struct to represent the state of the grid
struct GridState {
    vector<vector<int>> grid;
    int moves;
};

bool isGoalState(const vector<vector<int>>& grid) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}

int bfs(vector<vector<int>>& A) {
    queue<GridState> q;
    unordered_set<string> visited;

    q.push({A, 0});
    visited.insert(serializeGrid(A));

    while (!q.empty()) {
        GridState curr = q.front();
        q.pop();

        if (isGoalState(curr.grid)) {
            return curr.moves;
        }

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (curr.grid[i][j] > 1) {
                    for (const auto& direction : directions) {
                        int nx = i + direction[0];
                        int ny = j + direction[1];

                        if (isValid(nx, ny)) {
                            vector<vector<int>> newGrid = curr.grid;
                            newGrid[i][j]--;
                            newGrid[nx][ny]++;
                            string newGridStr = serializeGrid(newGrid);

                            if (visited.find(newGridStr) == visited.end()) {
                                visited.insert(newGridStr);
                                q.push({newGrid, curr.moves + 1});
                            }
                        }
                    }
                }
            }
        }
    }

    return -1; // If we reach here, there is no solution
}

int solution(vector<vector<int>>& A) {
    return bfs(A);
}

int main() {
    vector<vector<int>> temp{{0,0,0}, {0,0,0}, {0,0,9}};
    cout<<solution(temp);
}