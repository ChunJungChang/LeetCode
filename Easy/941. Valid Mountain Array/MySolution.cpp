class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i = 0, j = 0;

        for (i = 0; i < arr.size() - 1; i++) {
            if (arr[i] >= arr[i + 1]) {
                break;
            }
        }

        if (i == 0 || i == arr.size() - 1) {
            return false;
        }

        for (j = arr.size() - 1; j > 0; j--) {
            if (arr[j] >= arr[j - 1]) {
                break;
            }
        }

        if (i == j) {
            return true;
        } else {
            return false;
        }
    }
};
