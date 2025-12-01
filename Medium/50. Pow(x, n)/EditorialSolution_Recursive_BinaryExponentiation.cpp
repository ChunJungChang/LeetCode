/**
 * func binaryExp(x, n):
 *     if n == 0: return 1.0
 *     if n < 0: return 1.0 / binaryExp(x, -n)
 *
 *     // Binary exponentiation steps.
 *     if n is even: return binaryExp(x * x, n / 2)
 *     if n is odd: return x * binaryExp(x * x, (n - 1) / 2)
 */

class Solution {
public:
    double helpmyPow(double x, long long n) {
        double ret = 0;

        if (n == 0) {
            ret = 1.0;
        } else if (n % 2 == 0) {
            ret = myPow(x * x, n / 2);
        } else if (n % 2 == 1) {
            ret = x * myPow(x * x, (n - 1) / 2);
        }

        return ret;
    }

    double myPow(double x, int n) {
        double ret = 0;

        if (n == 0) {
            ret = 1.0;
        } else if (n > 0) {
            ret = helpmyPow(x, n);
        } else if (n < 0) {
            ret = helpmyPow(x, abs((long long)n));
        }

        if (n < 0) {
            ret = 1.0 / ret;
        }

        return ret;
    }
};
