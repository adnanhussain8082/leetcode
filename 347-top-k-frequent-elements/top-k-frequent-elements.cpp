class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }

        // heap
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> minHeap;
        for (auto i = mpp.begin(); i != mpp.end(); i++) {
            minHeap.push({i->second, i->first});

            if (minHeap.size() > k)
                minHeap.pop();
        }

        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};