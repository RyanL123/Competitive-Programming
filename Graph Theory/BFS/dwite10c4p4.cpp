#include <iostream>
#include <queue>

using namespace std;

int main() {
    for (int t = 0; t < 5; t++) {
        int mountain[10][10];
        string s;
        for (int i = 0; i < 10; i++) {
            cin >> s;
            for (int j = 0; j < 10; j++) {
                mountain[i][j] = s[j] - 48;
            }
        }
        // gets input of line dashes
        cin >> s;

        int lowest = 100000;
        for (int i = 0; i < 10; i++) {
            queue<pair<int, int>> q;
            int steps[10][10];
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    steps[j][k] = 100000;
                }
            }
            q.push(make_pair(i, 0));
            steps[i][0] = 0;
            while (!q.empty()) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                if (row + 1 < 10 && abs(mountain[row][col] - mountain[row + 1][col]) <= 1
                    && steps[row + 1][col] > steps[row][col] + 1) {
                    steps[row + 1][col] = steps[row][col] + 1;
                    q.push(make_pair(row + 1, col));
                }
                if (row - 1 >= 0 && abs(mountain[row][col] - mountain[row - 1][col]) <= 1
                    && steps[row - 1][col] > steps[row][col] + 1) {
                    steps[row - 1][col] = steps[row][col] + 1;
                    q.push(make_pair(row - 1, col));
                }
                if (col + 1 < 10 && abs(mountain[row][col] - mountain[row][col + 1]) <= 1
                    && steps[row][col + 1] > steps[row][col] + 1) {
                    steps[row][col + 1] = steps[row][col] + 1;
                    q.push(make_pair(row, col + 1));
                }
                if (col - 1 >= 0 && abs(mountain[row][col] - mountain[row][col - 1]) <= 1
                    && steps[row][col - 1] > steps[row][col] + 1) {
                    steps[row][col - 1] = steps[row][col] + 1;
                    q.push(make_pair(row, col - 1));
                }
            }
            for (int j = 0; j < 10; j++) {
                if (steps[j][9] < lowest) {
                    lowest = steps[j][9];
                }
            }
        }
        if (lowest == 100000){
            cout << "IMPOSSIBLE" << endl;
        }
        else {
            cout << lowest << endl;
        }
    }
}