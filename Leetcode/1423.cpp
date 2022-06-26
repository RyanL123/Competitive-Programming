class Solution {
public:
    // minimum sum of n-k
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), pfx[100005], sum = 0;
        memset(pfx, 0, sizeof(pfx));
        for (int i = 1; i <= n; i++) {
            pfx[i] += pfx[i-1] + cardPoints[i-1];
            sum += cardPoints[i-1];
        }
        int mn = 0x3f3f3f3f;
        for (int i = n-k; i <= n; i++) {
            mn = min(mn, pfx[i]-pfx[i-(n-k)]);
        }
        return sum - mn;
    }
};