class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int mx1 = horizontalCuts[0], mx2 = verticalCuts[0], MOD = 1e9+7;
        for (int i = 1; i < horizontalCuts.size(); i++) {
            mx1 = max(mx1, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        mx1 = max(mx1, h-horizontalCuts.back());
        for (int i = 1; i < verticalCuts.size(); i++) {
            mx2 = max(mx2, verticalCuts[i] - verticalCuts[i-1]);
        }
        mx2 = max(mx2, w-verticalCuts.back());
        return (long long)mx1*mx2%MOD;
    }
};