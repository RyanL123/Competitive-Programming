#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int n, m;
    string input;
    queue<pair<int, int>> queue;
    char factory[110][110];
    int steps[110][110];
    for (int i = 0; i < 110; i++) {
        for (int j = 0; j < 110; j++) {
            factory[i][j] = 'W';
            steps[i][j] = INT_MAX;
        }
    }

    //gets factory floor plan
    vector<pair<int, int>> exits;
    vector<pair<int, int>> cameras;
    cin >> n >> m;
    for (int i = n - 1; i >= 0; i--) {
        cin >> input;
        for (int j = 0; j < input.size(); j++) {
            factory[i][j] = input[j];
            if (input[j] == 'S') {
                queue.push(make_pair(i, j));
                steps[i][j] = 0;
            }
            // store exits in the exits vector
            if (input[j] == '.') {
                exits.emplace_back(make_pair(i, j));
            }
            if (input[j] == 'C'){
                cameras.emplace_back(make_pair(i, j));
            }
        }
    }

    // starting from every camera, mark all squares with direct line of sight as invalid
    for (int k = 0; k < cameras.size(); k++) {
        int i = cameras[k].first;
        int j = cameras[k].second;
            // loop until a wall is detected
            // check up
        int a = i;
        while (factory[a + 1][j] != 'W') {
            if (factory[a + 1][j] == '.' || factory[a + 1][j] == 'S') {
                factory[a + 1][j] = 'I';
            }
            a++;
        }
        // check down
        int b = i;
        while (factory[b - 1][j] != 'W') {
            if (factory[b - 1][j] == '.' || factory[b - 1][j] == 'S') {
                factory[b - 1][j] = 'I';
            }
            b--;
        }
        // check right
        int c = j;
        while (factory[i][c + 1] != 'W') {
            if (factory[i][c + 1] == '.' || factory[i][c + 1] == 'S') {
                factory[i][c + 1] = 'I';
            }
            c++;
        }
        // check left
        int d = j;
        while (factory[i][d - 1] != 'W') {
            if (factory[i][d - 1] == '.' || factory[i][d - 1] == 'S') {
                factory[i][d - 1] = 'I';
            }
            d--;
        }
    }

    // if spawn point is within line of sight of any camera
    if (factory[queue.front().first][queue.front().second] == 'I') {
        for (int i = 0; i < exits.size(); i++) {
            cout << -1 << endl;
        }
        return 0;
    }

    //BFS
    while (!queue.empty()) {
        int x = queue.front().first;
        int y = queue.front().second;
        // currently standing on a conveyor belt
        if (factory[x][y] == 'U') {
            if (steps[x + 1][y] > steps[x][y] && factory[x + 1][y] != 'W' && factory[x + 1][y] != 'I'
                && factory[x + 1][y] != 'C') {
                queue.push(make_pair(x + 1, y));
                steps[x + 1][y] = steps[x][y];
            }
        } else if (factory[x][y] == 'D') {
            if (steps[x - 1][y] > steps[x][y] && factory[x - 1][y] != 'W' && factory[x - 1][y] != 'I'
                && factory[x - 1][y] != 'C') {
                queue.push(make_pair(x - 1, y));
                steps[x - 1][y] = steps[x][y];
            }
        } else if (factory[x][y] == 'R') {
            if (steps[x][y + 1] > steps[x][y] && factory[x][y + 1] != 'W' && factory[x][y + 1] != 'I'
                && factory[x][y + 1] != 'C') {
                queue.push(make_pair(x, y + 1));
                steps[x][y + 1] = steps[x][y];
            }
        } else if (factory[x][y] == 'L') {
            if (steps[x][y - 1] > steps[x][y] && factory[x][y - 1] != 'W' && factory[x][y - 1] != 'I'
                && factory[x][y - 1] != 'C') {
                queue.push(make_pair(x, y - 1));
                steps[x][y - 1] = steps[x][y];
            }
        } else {
            if (factory[x + 1][y] != 'W' && factory[x + 1][y] != 'C'
                && factory[x + 1][y] != 'I' && steps[x + 1][y] > steps[x][y] + 1) {
                steps[x + 1][y] = steps[x][y] + 1;
                queue.push(make_pair(x + 1, y));
            }
            //check down
            if (factory[x - 1][y] != 'W' && factory[x - 1][y] != 'C'
                && factory[x - 1][y] != 'I' && steps[x - 1][y] > steps[x][y] + 1) {
                steps[x - 1][y] = steps[x][y] + 1;
                queue.push(make_pair(x - 1, y));
            }
            //check right
            if (factory[x][y + 1] != 'W' && factory[x][y + 1] != 'C'
                && factory[x][y + 1] != 'I' && steps[x][y + 1] > steps[x][y] + 1) {
                steps[x][y + 1] = steps[x][y] + 1;
                queue.push(make_pair(x, y + 1));
            }
            //check left
            if (factory[x][y - 1] != 'W' && factory[x][y - 1] != 'C'
                && factory[x][y - 1] != 'I' && steps[x][y - 1] > steps[x][y] + 1) {
                steps[x][y - 1] = steps[x][y] + 1;
                queue.push(make_pair(x, y - 1));
            }
        }
        queue.pop();
    }

    for (int i = 0; i < exits.size(); i++) {
        if (steps[exits[i].first][exits[i].second] == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << steps[exits[i].first][exits[i].second] << endl;
        }
    }
}