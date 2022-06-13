class Solution {
public:
    // invariant: r-l+1 >= k, elements within range [l, r] are candidates for k closest
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size(), l = 0, r = n-1;
        int mn = 0;
        while (l <= r) {
            int m = (l+r)/2;
            int diff = arr[m] - x;
            if (abs(diff) < abs(arr[mn]-x)) mn = m;
            if (diff >= 0) {
                r = m-1;
            }
            else {
                l = m+1;
            }
        }
        l = mn, r = mn;
        while (r-l+1 < k) {
            if (r+1 >= n) l--;
            else if (l-1 < 0) r++;
            else if (abs(arr[r+1]-x) < abs(arr[l-1]-x)) r++;
            else if (abs(arr[r+1]-x) > abs(arr[l-1]-x)) l--;
            else if (arr[r+1] < arr[l-1]) r++;
            else l--;
        }
        vector<int> ret;
        for (int i = l; i <= r; i++) ret.push_back(arr[i]);
        return ret;
    }
};