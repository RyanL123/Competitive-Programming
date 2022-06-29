class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int l = 0, r = arr.back(), ret = 0x3f3f3f3f, mn = 0x3f3f3f3f;
        while (l <= r) {
            int m = (l+r)/2;
            int sum = 0;
            for (int i : arr) {
                if (i <= m) sum += i;
                else sum += m;
            }
            if (abs(target-sum) < mn) {
                ret = m;
                mn = abs(target-sum);
            }
            else if (abs(target-sum) == mn) ret = min(ret, m);
            if (sum < target) l = m+1;
            else r = m-1;
        }
        return ret;
    }
};