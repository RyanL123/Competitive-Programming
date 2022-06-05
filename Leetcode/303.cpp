class NumArray {
public:
    int pfx[10005];
    NumArray(vector<int>& nums) {
        memset(pfx, 0, sizeof(pfx));
        for (int i = 1; i <= nums.size(); i++) {
            pfx[i] = pfx[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return pfx[right+1] - pfx[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */