class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int longestSequence = 0, numZeroes = 0, left = 0, right = 0;

        // While our window is in bounds
        while (right < nums.size()) {
            // Increase numZeroes if the rightmost element is 0
            if (nums[right] == 0) {
                numZeroes++;
            }

            // If our window is invalid, contract our window
            while (numZeroes == 2) {
                if (nums[left] == 0) {
                    numZeroes--;
                }
                left++;
            }

            // Update our longest sequence answer
            longestSequence = max(longestSequence, right - left + 1);

            // Expand our window
            right++;
        }
        return longestSequence;
    }
};
