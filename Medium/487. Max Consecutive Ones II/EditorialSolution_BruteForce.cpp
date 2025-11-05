class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int longestSequence = 0;

        for (int left = 0; left < nums.size(); left++) {
            int numZeroes = 0;

            //Check every consecutive sequence
            for (int right = left; right < nums.size(); right++) {
                // Count how many 0's
                if (nums[right] == 0) {
                    numZeroes += 1;
                }
                // Update answer if it's valid
                if (numZeroes <= 1) {
                    longestSequence = max(longestSequence, right - left + 1);
                }
            }
        }
        return longestSequence;
    }
};
