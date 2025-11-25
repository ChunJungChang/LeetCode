class Solution {
public:
    map<int, int> fibMap;

    int fib(int n) {
        int ret = 0;

        if (n < 2) {
            return n;
        }

        auto it = fibMap.find(n);
        if (it != fibMap.end()) {
            return it->second;
        }

        ret = fib(n - 1) + fib(n - 2);
        fibMap.insert(std::pair<int, int>(n, ret));

        return ret;
    }
};
