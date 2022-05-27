class Solution {
public:
    // if sum(i, j) < k, then all subarrays between (i, j) < k
    // if interval sum(i, j) < k and interval sum(u, v) < k and the intervals overlap
    // then the number of valid subarrays is 
    // num sub arrays within (i, j) + num subarrays within (u, v) - num of subarrays in the intersection
    // number of subarrays in an interval of size n is n*(n-1)/2
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), sum = 1, l = 0;
        vector<vector<int>> intervals;
        for (int r = 0; r < n; r++) {
            sum *= nums[r];
            while (sum >= k && l < r) {
                sum /= nums[l++];
            }
            if (sum < k) {
                intervals.push_back({l, r});
            }
        }
        int prevL = -1, prevR = -1, ret = 0;
        for (int i = 0; i < intervals.size(); i++) {
            int L = intervals[i][0], R = intervals[i][1];
            if (i == 0) {
                prevL = L, prevR = R;
                ret += ((R-L+1)*(R-L+2))/2;
                continue;
            }
            ret += ((R-L+1)*(R-L+2))/2;
            if (L <= prevR) {
                ret -= ((prevR-L+1)*(prevR-L+2))/2;
            }
            prevL = L, prevR = R;
        }
        return ret;
    }
};