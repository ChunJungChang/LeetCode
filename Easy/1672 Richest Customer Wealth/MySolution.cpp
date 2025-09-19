class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ret = 0, tmp = 0;

        for (size_t i = 0; i < accounts.size(); i++) {
            tmp = 0;

            for (size_t j = 0; j < accounts[i].size(); j++) {
                tmp = tmp + accounts[i][j];
            }
            
            if (tmp > ret) {
                ret = tmp;
            }
        }

        return ret;
    }
};
