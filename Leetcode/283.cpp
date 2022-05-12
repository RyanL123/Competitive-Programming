class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n-1 && nums[j] == 0) j++;
            if (nums[j] != 0) swap(nums[i], nums[j]);
        }
    }
};