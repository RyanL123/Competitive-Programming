class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        for (int i = 0; i < 31; i++) {
            if (n%2 == 1) ret++;
            n = n>>1;
            ret = ret<<1;
        }
        if (n) ret++;
        return ret;
    }
};