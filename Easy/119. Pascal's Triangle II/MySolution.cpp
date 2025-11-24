class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res, ret;

        if (rowIndex == 0) {
            ret.push_back(1);

            return ret;
        } else if (rowIndex == 1) {
            ret.push_back(1);
            ret.push_back(1);

            return ret;
        }

        res = getRow(rowIndex - 1);
        ret.push_back(1);
        for (int i = 0; i < res.size() - 1; i++) {
            ret.push_back(res[i] + res[i + 1]);
        }
        ret.push_back(1);

        return ret;
    }
};
