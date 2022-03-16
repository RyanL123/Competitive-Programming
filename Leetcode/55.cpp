#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int mx = nums[0];
    for (int i = 0; i < n-1; i++) {
        mx = max(mx, i+nums[i]);
        if (mx <= i) {
            return false;
        }
    }
    return true;
}

int main() {
}