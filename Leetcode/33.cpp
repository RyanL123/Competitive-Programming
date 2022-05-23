class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n-1;
        while (l <= r) {
            int m = (l+r)/2;
            cout << l << ' ' << m << ' ' << r << endl;
            if (nums[m] == target) return m;
            if (nums[l] < nums[r]) {
                if (nums[m] > target) r = m-1;
                else l = m+1;
            }
            else {
                if (nums[m] < target) {
                    if (nums[m] > nums[l]) l = m+1;
                    else if (nums[r] < target) r = m-1;
                    else l = m+1;
                }
                else {
                    if (nums[m] < nums[l]) r = m-1;
                    else if (nums[l] > target) l = m+1;
                    else r = m-1;
                }
            }
        }
        return -1;
    }
};