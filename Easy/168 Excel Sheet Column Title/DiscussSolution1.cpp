class Solution {
public:
    string convertToTitle(int n) {
        string letter, result;
        
        while (n > 0) {
            n--;
            char letter = 'A'+ n % 26;;
            result = letter + result;
            n /= 26;
        }
        return result;
    }
};
