class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool result = false;

        if (n > 0) {
            if ((n & n - 1) == 0)
                result = true;
        } else {
            result = false;
        }
        
        return result;
    }
};
