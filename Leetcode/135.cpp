class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), ret = 0;
        vector<int> v(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i-1] < ratings[i]) v[i] = v[i-1]+1;
        }
        for (int i = n-2; i >= 0; i--) {
            if (ratings[i+1] < ratings[i]) v[i] = max(v[i], v[i+1]+1);
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};