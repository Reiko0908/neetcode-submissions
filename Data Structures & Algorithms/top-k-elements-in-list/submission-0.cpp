class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int num : nums) counts[num]++;
        using P = pair<int, int>;
        priority_queue<P, vector<P>, greater<P>> minHeap;
        for (auto& [num, occurrences] : counts) {
            minHeap.push({occurrences, num});
            if (minHeap.size() > k) minHeap.pop();

        }
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return result;
    }
};