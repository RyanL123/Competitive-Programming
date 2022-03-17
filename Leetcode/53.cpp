#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int cur = 0, mx = nums[0];
    for (int i = 0; i < n; i++) {
        if (cur < 0) cur = 0;
        cur += nums[i];
        mx = max(mx, cur);
    }
    return mx;
}

int main() {
}