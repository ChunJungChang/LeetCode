class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        
        for(i;i<nums.size();i++) {
            if(nums[i] == 0) {
                for(j = i + 1;j<nums.size();j++) { 
                    if(nums[j] != 0) {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
};
