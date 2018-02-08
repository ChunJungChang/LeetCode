class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;
        
        while (i < j) {
            while ((s[i] != 'a' &&
                    s[i] != 'e' &&
                    s[i] != 'i' &&
                    s[i] != 'o' &&
                    s[i] != 'u') &&
                   (s[i] != 'A' &&
                    s[i] != 'E' &&
                    s[i] != 'I' &&
                    s[i] != 'O' &&
                    s[i] != 'U') &&
                    i < s.length()) {
                i++;
            }
            while ((s[j] != 'a' &&
                    s[j] != 'e' &&
                    s[j] != 'i' &&
                    s[j] != 'o' &&
                    s[j] != 'u') &&
                   (s[j] != 'A' &&
                    s[j] != 'E' &&
                    s[j] != 'I' &&
                    s[j] != 'O' &&
                    s[j] != 'U') &&
                    j >= 0) {
                j--;
            }
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        
        return s;
    }
};
