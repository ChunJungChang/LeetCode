class Solution {
public:
    int mySqrt(int x) {
        int first = 0, last = x;
        int middle = (first + last) / 2;
        
        if (x == 0)
            return 0;
        else if (x == 1)
            return 1;
        while (middle != (x / middle)) {
            if ((last - 1) == first) {
                return first;
            }
            if (middle > ( x / middle) ) {
                last = middle;
                middle = (first + last) / 2;
            }
            else if (middle < (x / middle)) {
                first = middle;
                middle = (first + last) / 2;
            }
        }
        return middle;
    }
};
