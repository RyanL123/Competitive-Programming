class Solution {
public:
    int numberOfSteps(int num) {
        int ret = 0;
        while (num) {
            ret++;
            if (num % 2) num--;
            else num /= 2;
        }
        return ret;
    }
};