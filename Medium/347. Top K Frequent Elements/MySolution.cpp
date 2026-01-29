class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        vector<pair<int, int>> count;
        pair<int, int> p;

        for (int i = 0; i < nums.size(); i++) {
            int key_to_find  = nums[i];
            auto it = find_if(count.begin(), count.end(),
                              [key_to_find](pair<int, int>& element) {
                                  return element.first == key_to_find;
                              });
            if (it != count.end()) {
                it->second++;
            } else {
                count.push_back(make_pair(key_to_find, 1));
            }
        }

        auto compareBySecond = [](pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second < rhs.second;
        };
        make_heap(count.begin(), count.end(), compareBySecond);
        for (int i = 1; i <= k; i++) {
            pop_heap(count.begin(), count.end(), compareBySecond);
            p = count.back();
            count.pop_back();
            ret.push_back(p.first);
        }

        return ret;
    }
};
