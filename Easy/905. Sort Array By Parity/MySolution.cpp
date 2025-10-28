class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ret;
        int index = 0, i = 0;

        for (i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                ret.push_back(nums[i]);
            }
        }

        for (i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 != 0) {
                ret.push_back(nums[i]);
            }
        }

        return ret;
    }
};
