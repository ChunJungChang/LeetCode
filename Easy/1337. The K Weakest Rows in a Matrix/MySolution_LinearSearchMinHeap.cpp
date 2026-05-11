class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int soldiersNum = 0, i = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> ret;

        i = 0;
        for (const auto& row : mat) {
            soldiersNum = 0;
            for (const int& value : row) {
                if (value == 1) {
                    soldiersNum++;
                } else {
                    break;
                }
            }
            minHeap.push(make_pair(soldiersNum, i));
            i++;
        }

        while (k > 0) {
            pair<int, int> top = minHeap.top();
            minHeap.pop();
            ret.push_back(top.second);
            k--;
        }

        return ret;
    }
};
