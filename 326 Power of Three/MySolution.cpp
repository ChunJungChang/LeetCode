/* Maximum Bboundary */
 * INT_MAX = 3^x
 * log(INT_MAX) = log(3^x)
 * log(INT_MAX) = xlog3
 * x = log(INT_MAX) / log3
 *
 * Max3PowerInt = 1162261467; 3^19, 3^20 = 3486784401 > MaxInt32
 * MaxInt32 = 2147483647; 2^31 - 1
 */

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        else {
            int tmp = pow(3, (int)(log(INT_MAX) / log(3)));
            return (tmp % n == 0);
        }
    }
};
