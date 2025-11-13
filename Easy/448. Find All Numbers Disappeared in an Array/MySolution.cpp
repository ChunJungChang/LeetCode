class Solution {
public:
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];

        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[j], arr[i]);
            }
        }
        swap(arr[i + 1], arr[high]);

        return i + 1;
    }

    void quicksort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);

            quicksort(arr, low, pi - 1);
            quicksort(arr, pi + 1, high);
        }
    }

    bool findElement(vector<int>& arr, int val, int low, int high) {
        bool ret = false;
        int midIdx = 0;

        if (low > high) {
            return ret;
        }

        midIdx = (low + high) / 2;

        if (val == arr[midIdx]) {
            ret = true;
        } else if (val < arr[midIdx]) {
            ret = findElement(arr, val, low, midIdx - 1);
        } else {
            ret = findElement(arr, val, midIdx + 1, high);
        }

        return ret;
    }

    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;

        quicksort(nums, 0, nums.size() - 1);

        for (int val = 1; val <= nums.size(); val++) {
            bool find = false;

            find = findElement(nums, val, 0, nums.size() - 1);

            if (!find) {
                ret.push_back(val);
            }
        }

        return ret;
    }
};
