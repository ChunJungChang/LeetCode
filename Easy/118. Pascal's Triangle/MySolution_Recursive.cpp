class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        vector<int> lastEle, cur;

        if (numRows == 1) {
            ret.push_back({1});

            return ret;
        }

        ret = generate(numRows - 1);

        lastEle = ret.back();
        cur.push_back(1);
        for (int i = 0; i < lastEle.size() - 1; i++) {
            cur.push_back(lastEle[i] + lastEle[i + 1]);
        }
        cur.push_back(1);
        ret.push_back(cur);

        return ret;
    }
};
