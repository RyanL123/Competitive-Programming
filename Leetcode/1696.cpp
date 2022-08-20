class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int dp[100005], n = nums.size();
        memset(dp, -0x3f, sizeof(dp));
        dp[n-1] = nums[n-1];
        priority_queue<pair<int, int>> pq;
        pq.push({dp[n-1], n-1});
        for (int i = n-2; i >= 0; i--) {
            while (!pq.empty() && pq.top().second > i+k) pq.pop();
            dp[i] = pq.top().first + nums[i];
            pq.push({dp[i], i});
        }
        return dp[0];
    }
};