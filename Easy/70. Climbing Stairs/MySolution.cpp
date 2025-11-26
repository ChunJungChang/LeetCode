class Solution {
public:
    map<int, int> stairsMap;

    int climbStairs(int n) {
        int ret = 0;

        if (n < 3) {
            return n;
        }

        auto it = stairsMap.find(n);
        if (it != stairsMap.end()) {
            return it->second;
        }

        ret = climbStairs(n - 1) + climbStairs(n - 2);
        stairsMap.insert(pair<int, int>(n, ret));

        return ret;
    }
};
