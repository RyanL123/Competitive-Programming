class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> frq, seq;
        for (int i : nums) frq[i]++;
        for (int i : nums) {
            if (frq[i] == 0) continue;
            if (seq[i-1] > 0) {
                seq[i-1]--;
                seq[i]++;
                frq[i]--;
            }
            else {
                if (frq[i+1] == 0 || frq[i+2] == 0) return false;
                frq[i]--;
                frq[i+1]--;
                frq[i+2]--;
                seq[i+2]++;
            }
        }
        return true;
    }
};