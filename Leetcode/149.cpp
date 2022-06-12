class Solution {
public:
    // y1-y2 = m(x1-x2)
    // m(x1-x2) - (y1-y2) <= 1e-9
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 1) return points.size();
        int n = points.size(), ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int cur = 0;
                int x1 = points[i][0], x2 = points[j][0], y1 = points[i][1], y2 = points[j][1];
                if (x1 == x2) {
                    for (int k = 0; k < n; k++) {
                        int x3 = points[k][0];
                        if (x3 == x2) cur++;
                    }
                }
                else {
                    double m = (double)(y1-y2)/(x1-x2);
                   
                    for (int k = 0; k < n; k++) {
                        int x3 = points[k][0], y3 = points[k][1];
                        if (abs(m*(x1-x3)-(y1-y3)) <= 1e-6) cur++;
                    }
                }
                ret = max(ret, cur);
            }
        }
        return ret;
    }
};