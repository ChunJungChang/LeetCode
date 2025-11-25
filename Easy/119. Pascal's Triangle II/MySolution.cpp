class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        vector<int> ret;

        if (rowIndex == 0) {
            ret.push_back(1);

            return ret;
        }

        res = getRow(rowIndex - 1);

        ret.push_back(1);
        for (auto it = res.begin(); it != res.end() - 1; it++) {
            ret.push_back(*it + *(it + 1));
        }
        ret.push_back(1);

        return ret;
    }
};
