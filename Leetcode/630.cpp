class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp);
        int n = courses.size(), day = 0;
        priority_queue<int> pq;
        for (vector<int> v : courses) {
            day += v[0];
            pq.push(v[0]);
            if (day > v[1]) {
                while (!pq.empty() && day > v[1]) {
                    day -= pq.top();
                    pq.pop();
                }
            }
        }
        return pq.size();
    }
};