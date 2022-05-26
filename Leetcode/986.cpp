class Solution {
public:
    // a < b && c < d
    bool intersection(int a, int b, int c, int d) {
        return !(c > b || d < a);
    }
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size(), m = secondList.size();
        int j = 0;
        vector<vector<int>> ret;
        for (int i = 0; i < n; i++) {
            int a = firstList[i][0], b = firstList[i][1];
            while (j < m && secondList[j][1] < a) {
                j++;
            }
            if (j >= m) break;
            while (j < m) {
                int c = secondList[j][0], d = secondList[j][1];
                if (intersection(a, b, c, d)) {
                    if (c >= a && d <= b) ret.push_back({c, d});
                    else if (a >= c && b <= d) ret.push_back({a, b});
                    else if (c <= b && c >= a) ret.push_back({c, b});
                    else if (a <= d && a >= c) ret.push_back({a, d});
                    if (d > b) break;
                    else j++;
                }
                else break;
            }
        }
        return ret;
    }
};