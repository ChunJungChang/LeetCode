class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) {
            return false;
        } else if (num == 1) {
            return true;
        } else if (num % 2 == 0) {
            num = num / 2;
            isUgly(num);
        } else if (num % 3 == 0) {
            num = num / 3;
            isUgly(num);
        } else if (num % 5 == 0) {
            num = num / 5;
            isUgly(num);
        } else{
            return false;
        }
    }
};
