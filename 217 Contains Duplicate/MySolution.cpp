class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::map<int, int> cmp;
        
        for (int i = 0;i < nums.size();i++) {
            if (cmp.find(nums[i]) == cmp.end()) {
                cmp.insert(pair<int, int> (nums[i], nums[i]));
            } else if (cmp.find(nums[i]) != cmp.end()) {
                return true;
            }
        }
        return false;
    }
};
