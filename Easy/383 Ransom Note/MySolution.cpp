#include <cstring>

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        bool ret = false;
        map<char, int> mapAlphabet;
        map<char, int>::iterator iter;
        int i = 0;
        
        for (i = 0; i < magazine.length(); i++) {
            mapAlphabet[magazine[i]]++;
        }

        for (i = 0; i < ransomNote.length(); i++) {
            iter = mapAlphabet.find(ransomNote[i]);
            if (iter == mapAlphabet.end() || iter->second <= 0) {
                return ret;
            } else {
                mapAlphabet[ransomNote[i]]--;
            }
        }
        ret = true;

        return ret;
    }
};
