class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for (int i : nums) s.insert(i);
        int ret = 0;
        for (int i : nums) {
            int j = i;
            if (s.count(i-1)) continue;
            while (s.count(j)) {
                j++;
            }
            ret = max(ret, j-i);
        }
        return ret;
    }
};