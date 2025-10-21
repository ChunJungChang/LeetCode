class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> mapCollect;
        map<int, int>::iterator iter;
        int ret = 0, i = 0, j = nums.size() - 1;

        for (i = 0; i < nums.size(); i++) {
            iter = mapCollect.find(nums[i]);
            if (iter != mapCollect.end()) {
                mapCollect[nums[i]]++;
                
    
            } else {
                mapCollect[nums[i]] = 1;
            }
        }

        nums.clear();

        for (iter = mapCollect.begin(); iter != mapCollect.end(); iter++) {
            nums.push_back(iter->first);
        }

        ret = nums.size();
        return ret;
    }
};
