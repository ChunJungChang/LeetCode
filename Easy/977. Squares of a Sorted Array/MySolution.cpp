class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ret;
        int i = 0;
        
        for (i = 0; i < nums.size(); i++) {
            ret.push_back(nums[i] * nums[i]);
        }
        
        sort(ret.begin(), ret.end());
        
        return ret;
    }
};
