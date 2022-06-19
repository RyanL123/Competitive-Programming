class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        unordered_map<string, vector<int>> mp;
        for (int i = 0; i < products.size(); i++) {
            int n = products[i].size();
            for (int j = 1; j <= n; j++) {
                string sub = products[i].substr(0, j);
                mp[sub].push_back(i);
            }
        }
        int n = searchWord.size();
        vector<vector<string>> ret;
        for (int i = 1; i <= n; i++) {
            string sub = searchWord.substr(0, i);
            vector<string> cur;
            for (int j = 0; j < mp[sub].size() && j < 3; j++) {
                cur.push_back(products[mp[sub][j]]);
            }
            ret.push_back(cur);
        }
        return ret;
    }
};