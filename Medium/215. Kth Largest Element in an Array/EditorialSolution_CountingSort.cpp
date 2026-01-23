class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int minValue = INT_MAX, maxValue = INT_MIN, remain = k, i = 0;
        
        for (i = 0; i < nums.size(); i++) {
            minValue = min(minValue, nums[i]);
            maxValue = max(maxValue, nums[i]);
        }

        vector<int> count(maxValue - minValue + 1);
        for (i = 0; i < nums.size(); i++) {
            count[nums[i] - minValue]++;
        }

        for (i = count.size() - 1; i >= 0; i--) {
            remain -= count[i];
            if (remain <= 0) {
                return minValue + i;
            }
        }

        return -1;
    }
};
