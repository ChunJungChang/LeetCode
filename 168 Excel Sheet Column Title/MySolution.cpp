class Solution {
public:
    string convertToTitle(int n) {
        string result;
        int quotient = 0;
        int remainder = 0;
        
        quotient = n / 26;
        //remainder: 0, 1~25
        remainder = n % 26;
        if (remainder == 0) {
            remainder = 25 + 65;
            if (quotient == 1) {
                result = (char)remainder;
                return result;
            }
            else {
                quotient = quotient - 2 + 65;
                result = (char)remainder;
                result = (char)quotient + result;
                return result;
            }
        }
        else {
            remainder--;
        }
        remainder += 65;
        
        if (quotient > 0) {
            result = convertToTitle(quotient) + (char)remainder;
        }
        else {
            result = (char)remainder;
            return result;
        }
    }
};
