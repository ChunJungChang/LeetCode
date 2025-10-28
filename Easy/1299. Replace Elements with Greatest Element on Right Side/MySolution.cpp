class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max = 0, i = 0, j = 0;

        for (i = 0; i < arr.size(); i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }

        for (i = 0; i < arr.size(); i++) {
            if (arr[i] != max) {
                arr[i] = max;
            } else if (arr[i] == max) {
                max = 0;

                for (j = i + 1; j < arr.size(); j++) {
                    if (arr[j] > max) {
                        max = arr[j];
                    }
                }

                arr[i] = max;
            }
        }

        arr[arr.size() - 1] = -1;

        return arr;
    }
};
