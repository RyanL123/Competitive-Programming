class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), ret = 0;
        int hsh[1005], sz[1005];
        for (int i = 0; i < n; i++) {
            int l = words[i].size();
            sz[i] = l;
            int curHash = 0;
            for (int j = 0; j < l; j++) {
                curHash |= 1 << (words[i][j] - 'a');
                hsh[i] = curHash;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if ((hsh[i] & hsh[j]) == 0) {
                    ret = max(ret, sz[i]*sz[j]);
                }
            }
        }
        return ret;
    }
};