class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n-1;
        while (l <= r) {
            int m = (l+r)/2;
            if (m+1 < n && nums[m+1] == nums[m]) ;
            else if (m-1 >= 0 && nums[m-1] == nums[m]) m--;
            else return nums[m];
            if ((n-m)%2 == 0) r = m-1;
            else l = m+2;
        }
        return nums[0];
    }
};