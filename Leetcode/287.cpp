#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    int lo = 1, hi = n;
    while (lo < hi) {
        int mid = (lo+hi)/2;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= mid) cnt++;
        }
        if (cnt <= mid) lo = mid+1;
        else hi = mid;
    }
    return lo;
}

int main() {
}