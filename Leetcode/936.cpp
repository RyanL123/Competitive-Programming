class Solution {
public:
    bool done(string &s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '?') return false;
        }
        return true;
    }
    bool match(string &a, string &b) {
        if (a.size() != b.size()) return false;
        if (a == string(a.size(), '?')) return false;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i] && a[i] != '?') return false;
        }
        return true;
    }
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size();
        vector<int> ret;
        while (!done(target)) {
            bool found = false;
            for (int i = 0; i < n-stamp.size()+1; i++) {
                string substr = target.substr(i, stamp.size());
                if (match(substr, stamp)) {
                    found = true;
                    ret.push_back(i);
                    for (int j = i; j < i+stamp.size(); j++) {
                        target[j] = '?';
                    }
                }
            }
            if (!found && !done(target)) return {};
        }
        if (ret.size() > n*10) return {};
        reverse(ret.begin(), ret.end());
        return ret;
    }
};