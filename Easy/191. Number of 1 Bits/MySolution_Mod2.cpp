class Solution {
public:
    int hammingWeight(uint32_t n) {
        int i = 0;
        
        while (n > 1) {
            if (n % 2 == 1)
                i++;
            n /= 2;
        }
        if (n == 1)
            i++;
        
        return i;
    }
};
