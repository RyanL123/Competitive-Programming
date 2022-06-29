class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> ret;
        for (vector<int> v : people) {
            ret.insert(ret.begin() + v[1], {v[0], v[1]});
        }
        return ret;
    }
};