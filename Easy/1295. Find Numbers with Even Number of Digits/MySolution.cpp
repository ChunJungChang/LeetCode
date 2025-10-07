class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ret = 0, tmp = 0, i = 0, j = 0;
        
        for (i = 0; i < nums.size(); i++) {
            tmp = nums[i];
            j = 0;
            while (tmp > 0) {
                j++;
                tmp /= 10;
            }
            if (j %2 == 0) {
                ret++;
            }
        }
        
        return ret;
    }
};
