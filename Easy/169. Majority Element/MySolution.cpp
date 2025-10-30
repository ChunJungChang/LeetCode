class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majority_main(nums, 0, nums.size() - 1);
    }
private:
    int mid = 0;
    
    int majority_main(vector<int>& nums, int begin, int end) {
        if (begin == end)
            return nums[begin];
        
        mid = begin + (end - begin) / 2;
        
        int a = majority_main(nums, begin, mid);
        int b = majority_main(nums, mid + 1, end);
        
        if (a == b) {
            return a;
        }
        else {
            int count_a = 0;
            int count_b = 0;
            for (int i = begin;i <= end;i++) {
                if (nums[i] == a)
                    count_a++;
            }
            for (int i = begin;i <= end;i++) {
                if (nums[i] == b)
                    count_b++;
            }
            return count_a > count_b ? a : b;
        }
    }
};
