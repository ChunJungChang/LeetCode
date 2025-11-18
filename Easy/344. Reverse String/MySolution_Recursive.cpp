class Solution {
public:
    void reverseHelp(vector<char>& s, int i, int j) {
        if (i >= j) {
            return;
        }

        swap(s[i], s[j]);
        i++;
        j--;
        reverseHelp(s, i, j);
    }

    void reverseString(vector<char>& s) {
        reverseHelp(s, 0, s.size() - 1);
    }
};
