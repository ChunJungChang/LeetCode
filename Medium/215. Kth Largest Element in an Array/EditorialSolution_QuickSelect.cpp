class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k);
    }

    int quickSelect(vector<int>& nums, int k) {
        vector<int> left;
        vector<int> mid;
        vector<int> right;
        int pivot = 0, i = 0;

        srand(time(NULL));
        pivot = nums[rand() % nums.size()];

        for (i = 0; i < nums.size(); i++) {
            if (nums[i] > pivot) {
                left.push_back(nums[i]);
            } else if (nums[i] < pivot) {
                right.push_back(nums[i]);
            } else {
                mid.push_back(nums[i]);
            }
        }

        if (k <= left.size()) {
            return quickSelect(left, k);
        } else if (left.size() + mid.size() < k) {
            /* The elements in left and mid are greater than the answer, deleting them means we must shift k. */
            return quickSelect(right, k - left.size() - mid.size());
        } else {
            return pivot;
        }
    }
};
