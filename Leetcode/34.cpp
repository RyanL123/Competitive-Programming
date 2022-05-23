class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1, L = n, R = -1;
        while (l <= r) {
            int m = (l+r)/2;
            if (nums[m] == target) {
                L = min(L, m);
                r = m-1;
            }
            else if (nums[m] > target) r = m-1;
            else l = m+1;
        }
        l = 0, r = n-1;
        while (l <= r) {
            int m = (l+r)/2;
            if (nums[m] == target){
                R = max(R, m);
                l = m+1;
            }
            else if (nums[m] < target) l = m+1;
            else r = m-1;
        }
        if (L == n) L = -1;
        return {L, R};
    }
};