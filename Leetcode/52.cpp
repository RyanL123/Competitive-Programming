class Solution {
public:
    bool check(vector<string> &cur) {
        int n = cur.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cur[i][j] == 'Q') {
                    int r = i, c = j;
                    for (int rr = 0; rr < n; rr++) {
                        if (cur[rr][c] == 'Q' && rr != r) return false;
                    }
                    for (int cc = 0; cc < n; cc++) {
                        if (cur[r][cc] == 'Q' && cc != c) return false;
                    }
                    r -= min(i, j), c -= min(i, j);
                    while (r < n && c < n) {
                        if (r == i && c == j) {
                            r++, c++;
                            continue;
                        }
                        if (cur[r][c] == 'Q') return false;
                        r++, c++;
                    }
                    r = i, c = j;
                    r += min(n-i-1, j), c -= min(n-i-1, j);
                    while (r >= 0 && c < n) {
                        if (r == i && c == j) {
                            r--, c++;
                            continue;
                        }
                        if (cur[r][c] == 'Q') return false;
                        r--, c++;
                    }
                }
            }
        }
        return true;
    }
    void helper(set<vector<string>>& ret, vector<string> cur, int placed, int n) {
        if (placed == n) {
            ret.insert(cur);
            return;
        }
        for (int i = 0; i < n; i++) {
            cur[placed][i] = 'Q';
            if (check(cur)) helper(ret, cur, placed+1, n);
            cur[placed][i] = '.';
        }
    }
    int totalNQueens(int n) {
        set<vector<string>> ret;
        vector<string> cur(n, string(n, '.'));
        helper(ret, cur, 0, n);
        return ret.size();
    }
};