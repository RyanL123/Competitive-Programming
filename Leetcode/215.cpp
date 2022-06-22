class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size(), frq[20005];
        memset(frq, 0, sizeof(frq));
        for (int i : nums) frq[i+10000]++;
        int cnt = 0;
        for (int i = 20000; i >= 0; i--) {
            if (frq[i]) cnt += frq[i];
            if (cnt >= k) return i-10000;
        }
        return 0;
    }
};