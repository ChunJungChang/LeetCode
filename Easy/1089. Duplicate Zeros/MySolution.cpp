class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> res;
        int len = arr.size(), i = 0;

        for (i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                res.push_back(arr[i]);
                res.push_back(0);
            } else {
                res.push_back(arr[i]);
            }

            if (res.size() == arr.size()) {
                break;
            }
        }

        arr.assign(res.begin(), res.end());
        arr.resize(len);
    }
};
