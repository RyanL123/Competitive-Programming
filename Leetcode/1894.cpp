class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long tot = 0;
        for (int i = 0; i < n; i++) tot += chalk[i];
        k %= tot;
        long long pfx[100005];
        memset(pfx, 0, sizeof(pfx));
        for (int i = 1; i <= n; i++) pfx[i] += pfx[i-1] + chalk[i-1];
        int l = 1, r = n;
        while (l < r) {
            int m = (l+r)/2;
            if (pfx[m] <= k) l = m+1;
            else r = m;
        }
        return r-1;
    }
};