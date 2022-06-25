class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            int a = -0x3f3f3f3f, b = a, c = nums[i];
            if (i-2 >= 0) a = nums[i-2];
            if (i-1 >= 0) b = nums[i-1];
            if (c >= b) continue;
            else if (c < b && c < a) {
                nums[i] = b;
                cnt++;
            }
            else {
                nums[i-1] = c;
                cnt++;
            }
        }
        return cnt <= 1;
    }
};