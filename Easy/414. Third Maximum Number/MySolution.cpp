class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long firstMax = numeric_limits<long long>::min();
        long long secondMax = numeric_limits<long long>::min();
        long long thirdMax = numeric_limits<long long>::min();

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > firstMax) {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = nums[i];
            } else if (nums[i] > secondMax && nums[i] != firstMax) {
                thirdMax = secondMax;
                secondMax = nums[i];
            } else if (nums[i] > thirdMax && nums[i] != secondMax && nums[i] != firstMax) {
                thirdMax = nums[i];
            }
        }

        if (thirdMax == numeric_limits<long long>::min()) {
            return firstMax;
        } else {
            return thirdMax;
        }
    }
};
