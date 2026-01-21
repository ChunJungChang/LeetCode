class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int ret = 0, i = 0;

        make_heap(nums.begin(), nums.end());

        for (i = 1; i <= k; i++) {
            pop_heap(nums.begin(), nums.end());
            ret = nums.back();
            nums.pop_back();
        }

        return ret;
    }
};
