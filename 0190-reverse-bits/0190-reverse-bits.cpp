class Solution {
public:
    int reverseBits(int n) {
        return __builtin_bitreverse32(n);
    }
};