class WordFilter {
public:
    unordered_map<string, deque<int>> dict;
    int n;
    WordFilter(vector<string>& words) {
        n = words.size();
        for (int i = 0; i < n; i++) {
            int m = words[i].size();
            for (int j = 1; j <= m; j++) {
                string pre = words[i].substr(0, j);
                for (int k = 1; k <= m; k++) {
                    string suf = words[i].substr(m-k, k);
                    string cur = pre + '|' + suf;
                    dict[cur].push_back(i);
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string cur = prefix + '|' + suffix;
        if (dict[cur].size() == 0) return -1;
        return dict[cur].back();
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */