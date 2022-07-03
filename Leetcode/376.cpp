class Solution {
public:
    // when you remove an element from nums, you add the adjacent differences in the difference array
    // combine segments of the difference array with the same sign, ignoring elements that are 0
    // the final answer is len(d) + 1
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        vector<int> d;
        for (int i = 1; i < nums.size(); i++) {
            d.push_back(nums[i] - nums[i-1]);
        }
        int ret = d[0] != 0, last = d[0];
        for (int i = 1; i < d.size(); i++) {
            if ((last <= 0 && d[i] > 0) || (last >= 0 && d[i] < 0)) {
                last = d[i];
                ret++;
            }
            else continue;
        }
        return ret+1;
    }
};