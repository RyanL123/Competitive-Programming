class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int cur = 0, ret = 0;
        for (vector<int> v : boxTypes) {
            if (cur == truckSize) break;
            ret += min(v[0], truckSize-cur)*v[1];
            cur += min(v[0], truckSize-cur);
        }
        return ret;
    }
};