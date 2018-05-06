class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index=0;
        int N = nums.size();

        for(int i = 0; i < N; ++i) {
            if(nums[i] != 0) {
                if(i != index) {
                    nums[index] = nums[i];
                    nums[i]=0;
                }
                ++index;
            }
        }
    }
};
