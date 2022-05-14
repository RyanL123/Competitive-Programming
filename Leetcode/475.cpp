class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = 0, r = 1e9+1;
        while (l <= r) {
            int m = l+(r-l)/2;
            bool can = true;
            int j = 0, n = heaters.size();
            for (int i = 0; i < houses.size(); i++) {
                if (houses[i] >= heaters[j]-m && houses[i] <= heaters[j]+m) continue;
                while (j < n && (houses[i] < heaters[j]-m || houses[i] > heaters[j]+m)) {
                    j++;
                }
                if (j == n) {
                    can = false;
                    break;
                }
            }
            if (can) r = m-1;
            else l = m+1;
        }
        return l;
    }
};