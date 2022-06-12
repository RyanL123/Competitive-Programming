class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while (n != 1) {
            int m = 0;
            if (st.count(n) == 1) return false;
            st.insert(n);
            while (n) {
                m += (n%10)*(n%10);
                n /= 10;
            }
            n = m;
        }
        return true;
    }
};