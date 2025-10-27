class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int i  = 0, j = 0;
        
        for (i = 0; i < arr.size() - 1; i++) {
            for (j = i + 1; j < arr.size(); j++) {
                if (arr[i] == 2 * arr[j]) {
                    return true;
                } else if (2 * arr[i] == arr[j]) {
                    return true;
                }
            }
        }

        return false;
    }
};
