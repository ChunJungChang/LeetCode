class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sortedHeights = heights;
        int ret = 0, index = 0, i = 0;

        for (index = 0; index < sortedHeights.size() - 1; index++) {
            for (i = index + 1; i < sortedHeights.size(); i++) {
                if (sortedHeights[index] > sortedHeights[i]) {
                    swap(sortedHeights[index], sortedHeights[i]);
                }
            }
        }

        for (i = 0; i < sortedHeights.size(); i++) {
            if (sortedHeights[i] != heights[i]) {
                ret++;
            }
        }

        return ret;
    }
};
