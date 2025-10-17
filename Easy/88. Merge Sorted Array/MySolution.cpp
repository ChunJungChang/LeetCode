class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res(m + n);
        int nums1_idx = 0, nums2_idx = 0, res_idx = 0;
        
        while (nums1_idx < m && nums2_idx < n) {
            if (nums1[nums1_idx] < nums2[nums2_idx]) {
                res[res_idx++] = nums1[nums1_idx++];
            } else {
                res[res_idx++] = nums2[nums2_idx++];
            }
        }

        while (nums1_idx < m) {
            res[res_idx++] = nums1[nums1_idx++];
        }
        while (nums2_idx < n) {
            res[res_idx++] = nums2[nums2_idx++];
        }

        nums1 = res;
    }
};
