/*
 * Comment code will result "Time Limit Exceeded".
 */

class KthLargest {
private:
    int k;
    vector<int> myNumsK;
    priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        sort(nums.begin(), nums.end(), greater<int>());

        /*
        for (int i = 0; i < nums.size() && i < k ; i++) {
            myNumsK.push_back(nums[i]);
        }
        */

        for (int i = 0; i < nums.size() && i < k ; i++) {
            minHeap.push(nums[i]);
        }
    }
    
    int add(int val) {
        /*
        if (myNumsK.size() < k || myNumsK.back() < val) {
            myNumsK.push_back(val);
            sort(myNumsK.begin(), myNumsK.end(), greater<int>());
            if (myNumsK.size() > k) {
                myNumsK.pop_back();
            }
        }

        return myNumsK.back();
        */

        if (minHeap.size() < k || minHeap.top() < val) {
            minHeap.push(val);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
