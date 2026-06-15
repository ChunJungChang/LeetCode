class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int ret = 0, cnt = 0;
        std::vector<int> heapVec;

        std::make_heap(heapVec.begin(), heapVec.end());

        for (auto& row : matrix) {
            for (int val : row) {
                if (cnt < k) {
                    heapVec.push_back(val);
                    std::push_heap(heapVec.begin(), heapVec.end());

                    cnt++;
                } else {
                    if (val <= heapVec[0]) {
                        std::pop_heap(heapVec.begin(), heapVec.end());
                        heapVec.pop_back();

                        heapVec.push_back(val);
                        std::push_heap(heapVec.begin(), heapVec.end());
                    } else {
                        break;
                    }
                }
            }
        }

        ret = heapVec[0];

        return ret;
    }
};
