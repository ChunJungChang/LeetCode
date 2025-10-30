class Solution {
public:
    int titleToNumber(string s) {
        int i = 0;
        int index = 0;
        int result = 0;
        int length = s.length();
        
        while (length > 0) {
            length--;
            index = pow(26, i);
            i++;
            result = result + ((int)s[length] - 64) * index;
        }

        return result;
    }
};
