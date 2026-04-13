class Solution {
private:
    int helpLastStoneWeight(vector<int>& stones) {
        int firstMax = 0, secondMax = 0, newStone = 0;

        if (stones.size() == 0) {
            return 0;
        } else if (stones.size() == 1) {
            return stones[0];
        } else if (stones.size() == 2) {
            if (stones[0] == stones[1]) {
                return 0;
            } else {
                return stones[0] - stones[1];
            }
        }

        firstMax = stones[0];
        pop_heap(stones.begin(), stones.end());
        stones.pop_back();
        secondMax = stones[0];
        pop_heap(stones.begin(), stones.end());
        stones.pop_back();
        
        newStone = firstMax - secondMax;
        if (newStone != 0) {
            stones.push_back(newStone);
            push_heap(stones.begin(), stones.end());
        }

        return helpLastStoneWeight(stones);
    }

public:
    int lastStoneWeight(vector<int>& stones) {
        int ret = 0;

        make_heap(stones.begin(), stones.end());

        ret = helpLastStoneWeight(stones);

        return ret;
    }
};
