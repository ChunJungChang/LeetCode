class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ret = 0, tmp = 0, i = 0;
        
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                tmp++;
            } else if (nums[i] == 0) {
                if (tmp > ret) {
                    ret = tmp;
                }
                tmp = 0;
            }
        }

        if (tmp > ret) {
            ret = tmp;
            tmp = 0;
        }
              
        return ret;
    }
};
