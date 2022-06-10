class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ret = 0;
        while (true) {
            if (left == 0 || right == 0) return ret;
            int a = log2(left);
            int b = log2(right);
            if (a == b) {
                ret += 1<<a;
                left -= 1<<a;
                right -= 1<<b;
            }
            else break;
        }
        return ret;
    }
};